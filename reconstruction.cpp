#include "reconstruction.h"

void makeWeightedGraph(int k, vector<string>& oligonucleotides, int** matrix) {
    int maxweight = 3;
    int weight = 4;

    for(int i = 0; i < oligonucleotides.size(); i++) {
        for(int j = 0; j < oligonucleotides.size(); j++) {
            matrix[i][j] = 0;
            for(int x = maxweight; x > 0; --x) {
                if(oligonucleotides[i].substr(x, k - x) == oligonucleotides[j].substr(0, k - x))
                    weight = x;
            }
            if(weight <= maxweight) {
                matrix[i][j] = weight;
            }
            weight = 4;
        }
    }
}

string reconstruct(int** matrix, const string& start, vector<string>& oligonucleotides, int n, int k, double p) {
    string solution;
    bool found, found2, found3;
    int used = 0;
    int index;
    int S = p*(n - k + 1);

    auto it = find(oligonucleotides.begin(), oligonucleotides.end(), start);
    if (it != oligonucleotides.end())
        index = it - oligonucleotides.begin();
    else
        return solution;

    solution += start;
    used++;
    found = false;

    for(int j = 0; j < oligonucleotides.size(); j++) {
        if(matrix[index][j] == 1) {
                solution += oligonucleotides[j].substr(k - 1, k);
                index = j;
                used++;
                found = true;
                break;
        }
    }
    if(!found) {
        for(int j = 0; j < oligonucleotides.size(); j++) {
            if(matrix[index][j] == 2) {
                solution += oligonucleotides[j].substr(k - 2, k);
                index = j;
                used++;
                break;
            }
        }
    }

    while(used < S || solution.size() != n) {
        found = false;
        found2 = false;
        found3 = false;

        for(int j = 0; j < oligonucleotides.size(); j++) {
            if(matrix[index][j] == 1) {
                solution += oligonucleotides[j].substr(k - 1, k);
                index = j;
                used++;
                found = true;
                found2 = true;
                found3 = true;
                break;
            }
        }
        if(!found) {
            for(int j = 0; j < oligonucleotides.size(); j++) {
                if(matrix[index][j] == 2) {
                    solution += oligonucleotides[j].substr(k - 2, k);
                    index = j;
                    used++;
                    found2 = true;
                    found3 = true;
                    break;
                }
            }
        }
        if(!found2) {
            for(int j = 0; j < oligonucleotides.size(); j++) {
                if(matrix[index][j] == 3) {
                    solution += oligonucleotides[j].substr(k - 3, k);
                    index = j;
                    used++;
                    found3 = true;
                    break;
                }
            }
        }
        if(!found3) {
            index++;
            solution += oligonucleotides[index];
            used++;
        }
    }
    return solution;
}

