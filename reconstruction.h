#ifndef SBH_RECONSTRUCTION_H
#define SBH_RECONSTRUCTION_H
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void makeWeightedGraph(int k, vector<string>& oligonucleotides, int** matrix);
string reconstruct(int** matrix, const string& start, vector<string>& oligonucleotides, int n, int k, double p);

#endif //SBH_RECONSTRUCTION_H
