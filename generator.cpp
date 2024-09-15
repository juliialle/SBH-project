#include "generator.h"

char alphabet[] = {'A', 'T', 'G', 'C'};

string generate(int n, unsigned int seed) {
    string DNA = "";
    srand(seed);

    for (int i = 0; i < n; i++)
        DNA += alphabet[rand() % sizeof(alphabet)];
    return DNA;
}

void makeSpectrum(vector<string>& oligonucleotides, const string& DNA, int k, int n) {
    for(size_t start = 0; start <= n - k; start++) {
        string oligonucleotide = DNA.substr(start, k);
        oligonucleotides.push_back(oligonucleotide);
    }
}

void eraseRepetitions(vector<string>& oligonucleotides) {
    //Liczba powtórzeń
    unsigned long oligoNum = oligonucleotides.size();
    sort(oligonucleotides.begin(), oligonucleotides.end()); // Sortujemy wektor
    auto newEnd = unique(oligonucleotides.begin(), oligonucleotides.end()); // Przesuwamy duplikaty na koniec
    oligonucleotides.erase(newEnd, oligonucleotides.end()); // Usuwamy duplikaty
    unsigned long numRepetitionErr = oligoNum - oligonucleotides.size();
}

void negativeErrors(vector<string>& oligonucleotides, int numErr, unsigned int seed) {
    srand(seed);
    for(int i = 0; i < numErr; i++) {
        int x = rand() % oligonucleotides.size();
        oligonucleotides.erase(oligonucleotides.begin() + x);
    }
}

void positiveErrors(vector<string>& oligonucleotides, int numErr, int k, unsigned int seed) {
    srand(seed);
    for(int i = 0; i < numErr; i++) {
        string DNA;
        for (int j = 0; j < k; j++)
            DNA += alphabet[rand() % sizeof(alphabet)];

        oligonucleotides.push_back(DNA);
    }
}

void saveFile(int n, int k, int posErr, int negErr, const string& osequence, const string& rsequence, int dist, double t) {
    ofstream file;
    file.open("700n.csv", ios::app);
    if (!file) {
        cout << " Error while creating the file ";
    }
    else {
//        file << "n: " << n << "  ";
//        file << "k: " << k << "  ";
//        file << "posErr: " << posErr << "  ";
//        file << "negErr: " << negErr << endl;
//        file << "Levenshtein: " << dist << " ";
//        file << "Time: " << fixed << t << endl;
        file << dist <<  ",";
        file << fixed << t << endl;
        file.close();
    }
}


