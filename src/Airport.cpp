//
// Created by aabedraba on 23/10/19.
//

#include "Airport.h"

Airport::Airport(string fileName )
{
    cargaAeropuerto(fileName);
    _simetry = checkSimerty();
}

Airport::~Airport() {

}

void Airport::cargaAeropuerto(string fileName) {
    ifstream file;
    file.open(fileName);
    string linea;
    if (file.good()) {
        getline(file, linea);
        _numDoors = stoi(linea, nullptr, 10);
        //
        _distanceMatrix.resize(_numDoors);
        _fluxMatrix.resize(_numDoors);
        for (int i = 0; i < _numDoors; ++i) {
            _distanceMatrix[i].resize(_numDoors);
            _fluxMatrix[i].resize(_numDoors);
        }

        for (int i = 0; i < _numDoors; ++i) {
            for (int j = 0; j < _numDoors; ++j) {
                file >> _fluxMatrix[i][j];
            }
        }
        file >> ws; //salto de linea
        for (int i = 0; i < _numDoors; ++i) {
            for (int j = 0; j < _numDoors; ++j) {
                file >> _distanceMatrix[i][j];
            }
        }
    }
    file.close();
    fileName.erase(0, 6);
    _airportName = fileName;
}

int Airport::getNumDoors() const {
    return _numDoors;
}

const vector<vector<int>> &Airport::getDistanceMatrix() const {
    return _distanceMatrix;
}

const vector<vector<int>> &Airport::getFluxMatrix() const {
    return _fluxMatrix;
}

bool Airport::checkSimerty() {
    for (int i = 0; i < _numDoors; i++)
        for (int j = i + 1; j < _numDoors; j++) {
            if (_fluxMatrix[i][j] != _fluxMatrix[j][i]) {
                return false;
            }
        }
    return true;
}

bool Airport::isSimetric() const {
    return _simetry;
}

const string &Airport::getAirportName() const {
    return _airportName;
}
