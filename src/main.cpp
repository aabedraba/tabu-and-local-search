#include <iostream>
#include <vector>

#include "Airport.h"
#include "Greedy.h"
#include "Utils.h"
#include "LocalSearch.h"
#include "TabuSearch.h"

using namespace std;

enum value {
    ALGORITHM = 0,
    AIRPORT = 1,
    ID = 2
};

void readParametersFile(vector<string> &parameters){
    ifstream file;
    file.open("_parametros.txt");
    string linea;
    if (file.good()) {
        while (!file.eof()) {
            file.ignore(256, ' ');
            file.ignore(256, ' ');
            file >> linea;
            parameters.push_back(linea.c_str());
        }
    }
    file.close();
}

int main() {
    vector<string> parameters;
    readParametersFile(parameters);
    string file = "_data/" + parameters[AIRPORT];
    int seed = stoi(parameters[ID], nullptr, 10);
    for (int i = 1; i < 5; ++i) {
        Airport *airport = new Airport(file);
        if (parameters[ALGORITHM] == "greedy"){
            Greedy *greedy = new Greedy(airport);
            Utils::writeInFile(seed, "Greedy", airport->getAirportName(), greedy->getLog());
            delete greedy;
        }
        else if (parameters[ALGORITHM] == "local"){
            LocalSearch *local = new LocalSearch(airport, seed);
            Utils::writeInFile(seed, "Busqueda Local", airport->getAirportName(), local->getLog());
            delete local;
        }
        else if (parameters[ALGORITHM] == "tabu"){
            TabuSearch *tabu = new TabuSearch(airport, seed);
            Utils::writeInFile(seed, "Tabu", airport->getAirportName(), tabu->getLog());
            delete tabu;
        }
    }


    return 0;
}
