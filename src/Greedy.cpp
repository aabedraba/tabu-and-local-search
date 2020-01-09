//
// Created by aabedraba on 23/10/19.
//

#include "Greedy.h"

Greedy::Greedy(Airport *airport) :
        _airport(airport) {
    auto start = std::chrono::steady_clock::now();
    initializeVectors();
    quickSort(_fluxSum, _fluxIndex, 0, _sizeVectors);
    quickSort(_distanceSum, _distanceIndex, 0, _sizeVectors);
    orderVectors();
    _solutionCost = Utils::solutionCost(_solutionVector, _airport->getFluxMatrix(), _airport->getDistanceMatrix(),
                                        _airport->isSimetric());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<float> diff = end - start;
    _executionTime = diff.count();
}

Greedy::~Greedy() {

}

void Greedy::initializeVectors() {
    _sizeVectors = _airport->getNumDoors();
    int fluxSum = 0;
    int distanceSum = 0;
    for (int i = 0; i < _sizeVectors; ++i) {
        for (int j = 0; j < _sizeVectors; ++j) {
            distanceSum += _airport->getDistanceMatrix()[i][j];
            fluxSum += _airport->getFluxMatrix()[i][j];
        }
        _fluxSum.push_back(fluxSum);
        _distanceSum.push_back(distanceSum);
        _fluxIndex.push_back(i);
        _distanceIndex.push_back(i);

        fluxSum = 0;
        distanceSum = 0;
    }
}

int Greedy::partition(vector<int> &arr, vector<int> &ind, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swap(ind[i], ind[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    swap(ind[i + 1], ind[high]);
    return (i + 1);
}

void Greedy::quickSort(vector<int> &arr, vector<int> &ind, int low, int high) {
    if (low < high) {
        int pi = partition(arr, ind, low, high);
        quickSort(arr, ind, low, pi - 1);
        quickSort(arr, ind, pi + 1, high);
    }
}

void Greedy::orderVectors() {
    _solutionVector.resize(_sizeVectors);
    for (int i = _sizeVectors - 1; i >= 0; --i)
        _solutionVector[_fluxIndex[i]] = _distanceIndex[_sizeVectors - 1 - i];
}

const vector<int> &Greedy::getSolutionVector() const {
    return _solutionVector;
}

int Greedy::getSolutionCost() const {
    return _solutionCost;
}

const string Greedy::getLog() const {
    return Utils::getLog("Greedy", _log, _executionTime, _airport->getAirportName(), _sizeVectors, _solutionVector,
                         _solutionCost);
}




