#ifndef SBH_GENERATOR_H
#define SBH_GENERATOR_H

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string generate(int n, unsigned int seed);
void makeSpectrum(vector<string>& oligonucleotides, const string& DNA, int k, int n);
void eraseRepetitions(vector<string>& oligonucleotides);
void negativeErrors(vector<string>& oligonucleotides, int numErr, unsigned int seed);
void positiveErrors(vector<string>& oligonucleotides, int numErr, int k, unsigned int seed);
void saveFile(int n, int k, int posErr, int negErr, const string& osequence, const string& rsequence, int dist, double t);

#endif //SBH_GENERATOR_H
