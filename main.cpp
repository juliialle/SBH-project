#include "generator.h"
#include "reconstruction.h"
#include "levenshtein.h"
#include <ctime>
#include <iomanip>
#include <set>

int main() {
    srand(time(nullptr));
    int n, k, negErr, posErr;
    double coverageDegree;

    cout << "Długość DNA: ";
    cin >> n;
    cout << "Długość oligonukleotydów: ";
    cin >> k;

    cout << endl;
    cout << "Liczba błędów negatywnych: ";
    cin >> negErr;
    cout << "Liczba błędów pozytywnych: ";
    cin >> posErr;
    cout << endl;
//    cout << "Stopień pokrycia (75-100%): ";
//    cin >> coverageDegree;
//    cout << endl;

    //for(int t = 0; t < 5; t++) {
        vector<string> spectrum;
        string sample = generate(n,rand());
        makeSpectrum(spectrum, sample, k, n);
        string first = spectrum.front();
        spectrum.erase(spectrum.begin());

        eraseRepetitions(spectrum);

        negativeErrors(spectrum, negErr, rand());
        positiveErrors(spectrum, posErr, k, rand());

        spectrum.insert(spectrum.begin(), first);
        int vertices = spectrum.size();

        int **matrix = new int*[vertices];
        for(int i = 0; i < vertices; ++i) {
            matrix[i] = new int[vertices]; // Alokuje pamięć dla każdego wiersza (tablice intów)
        }

        clock_t start = clock();

        makeWeightedGraph(k, spectrum, matrix);

        string reconstructedDNA = reconstruct(matrix, first, spectrum, n, k, 0.85);

        clock_t end = clock();
        double elapsed = double(end - start)/CLOCKS_PER_SEC;

        int dist = levenshteinDist(sample, reconstructedDNA);

        cout << dist << endl;
        cout << fixed << elapsed;

        saveFile(n, k, posErr, negErr, sample, reconstructedDNA, dist, elapsed);

        for (int i = 0; i < vertices; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    //}

    return 0;
}
