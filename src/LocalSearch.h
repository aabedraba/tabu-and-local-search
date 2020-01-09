//
// Created by aabedraba on 23/10/19.
//

#ifndef META_LOCALSEARCH_H
#define META_LOCALSEARCH_H

#include <random>
#include <time.h>
#include "Airport.h"
#include "Utils.h"
#include <bits/stdc++.h>
#include <chrono>

class LocalSearch {
public:

    LocalSearch(Airport *airport, int randSeed);
    virtual ~LocalSearch();
    void initializeRandomSolution();
    const vector<int> &getSolutionVector() const;
    int getSolutionCost() const;
    const string getLog() const;

private:
    void generateSolution();
    int iterateNeighbours(int &bestSwap1, int &bestSwap2);

private:
    Airport *_airport;
    vector<int> _solutionVector;
    int _sizeVectors;
    int _solutionCost;
    string _log;
    float _executionTime;

};


#endif //META_LOCALSEARCH_H
