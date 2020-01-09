//
// Created by aabedraba on 23/10/19.
//

#include <tuple>
#include "LocalSearch.h"

LocalSearch::LocalSearch(Airport *airport, int randSeed) :
        _airport(airport) {
    srand(randSeed);
    _sizeVectors = _airport->getNumDoors();
    auto start = std::chrono::steady_clock::now();
    initializeRandomSolution();
    Utils::logSolution("Initial Solution", make_pair(-1, -1), _solutionVector, _solutionCost, 0, -1);
    generateSolution();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<float> diff = end - start;
    _executionTime = diff.count();
}

LocalSearch::~LocalSearch() {

}

void LocalSearch::initializeRandomSolution() {
    for (int i = 0; i < _sizeVectors; ++i)
        _solutionVector.push_back(i);

    for (int i = 0; i < _sizeVectors; ++i) {
        int randInRange = rand() % _sizeVectors;
        swap(_solutionVector[i], _solutionVector[randInRange]);
    }
    _solutionCost = Utils::solutionCost(_solutionVector, _airport->getFluxMatrix(), _airport->getDistanceMatrix(),
                                        _airport->isSimetric());
}

void LocalSearch::generateSolution() {
    int iterationsInSolution = 0, movements = 0, environment = 0;
    int bestSwap1, bestSwap2;
    while (iterationsInSolution < 100 && movements < 50000) {
        int bestIterationCost = iterateNeighbours(bestSwap1, bestSwap2);
        if (bestIterationCost < _solutionCost) {
            swap(_solutionVector[bestSwap1], _solutionVector[bestSwap2]);
            _solutionCost = bestIterationCost;
            movements++;
            _log += Utils::logSolution("Solution", make_pair(bestSwap1, bestSwap2), _solutionVector, _solutionCost,
                                      movements, environment);
            iterationsInSolution = 0;
        } else {
            iterationsInSolution++;
        }
        environment++;
    }
}

int LocalSearch::iterateNeighbours(int &bestSwap1, int &bestSwap2) {
    pair<int, int> swapPositions;
    int bestSwapCost = INT_MAX;
    for (int i = 0; i < 10; ++i) {
        swapPositions.first = rand() % _sizeVectors;
        swapPositions.second = rand() % _sizeVectors;
        while (swapPositions.first == swapPositions.second) swapPositions.second = rand() % _sizeVectors;
        int swapCost = Utils::calculateSwapCost(_solutionVector, _solutionCost, swapPositions,
                                                _airport->getFluxMatrix(), _airport->getDistanceMatrix(),
                                                _airport->isSimetric());
        if (swapCost < bestSwapCost) {
            bestSwap1 = swapPositions.first;
            bestSwap2 = swapPositions.second;
            bestSwapCost = swapCost;
        }
    }
    return bestSwapCost;
}

const vector<int> &LocalSearch::getSolutionVector() const {
    return _solutionVector;
}

int LocalSearch::getSolutionCost() const {
    return _solutionCost;
}

const string LocalSearch::getLog() const {
    return Utils::getLog("Local Optimization", _log, _executionTime, _airport->getAirportName(), _sizeVectors, _solutionVector,
                         _solutionCost);
}
