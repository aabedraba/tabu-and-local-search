//
// Created by aabedraba on 23/10/19.
//

#ifndef META_UTILS_H
#define META_UTILS_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

namespace Utils {
    int solutionCost(const vector<int> &solution, const vector<vector<int>> &fluxMatrix,
                     const vector<vector<int>> &distanceMatrix, const bool simetric);

    int calculateSwapCost(vector<int> &solution, const int solutionCost, const pair<int, int> &swapPos, const vector<vector<int>> &fluxMatrix,
                          const vector<vector<int>> &distanceMatrix, const bool simetric);

    int partialSwapCost(const vector<int> &solution, const pair<int, int> swapPositions,
                        const vector<vector<int>> &fluxMatrix, const vector<vector<int>> &distanceMatrix,
                        const bool simetric);
    void writeInFile(int seed, const string type, const string airport, const string log);
    const string getLog(string algorithmType, const string log, float time, string airportName, int sizeVectors, const vector<int> &solutionVector,
                      int solutionCost);
    string logSolution(string type, pair<int, int> movement, vector<int> &solutionVector, int cost, int iteration, int environmentIteration);
}

#endif //META_UTILS_H
