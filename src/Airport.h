//
// Created by aabedraba on 23/10/19.
//

#ifndef META_AIRPORT_H
#define META_AIRPORT_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Airport {
public:
    Airport(string fileName );
    virtual ~Airport();
    int getNumDoors() const;
    const vector<vector<int>> &getDistanceMatrix() const;
    const vector<vector<int>> &getFluxMatrix() const;
    bool isSimetric() const;

    const string &getAirportName() const;

private:
    void cargaAeropuerto( string fileName);
    bool checkSimerty();


private:
    int _numDoors;
    bool _simetry;
    string _airportName;
    vector<vector<int>> _distanceMatrix;
    vector<vector<int>> _fluxMatrix;
};


#endif //META_AIRPORT_H
