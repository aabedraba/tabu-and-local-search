//
// Created by aabedraba on 23/10/19.
//

#ifndef META_GREEDY_H
#define META_GREEDY_H

#include "Airport.h"
#include <iostream>
#include "Utils.h"
#include <chrono>

class Greedy {
public:
    Greedy( Airport *airport );
    virtual ~Greedy();
    const vector<int> &getSolutionVector() const;
    int getSolutionCost() const;
    const string getLog() const;

private:
    void initializeVectors();
    void quickSort(vector<int> &arr, vector<int> &ind, int low, int high);
    int partition(vector<int> &arr, vector<int> &ind, int low, int high);
    void orderVectors();

private:
    Airport *_airport;
    vector<int> _fluxSum;
    vector<int> _fluxIndex;
    vector<int> _distanceSum;
    vector<int> _distanceIndex;
    vector<int> _solutionVector;
    int _sizeVectors;
    int _solutionCost;
    string _log;
    float _executionTime;
};


#endif //META_GREEDY_H
