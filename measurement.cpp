#include <iostream>
#include <chrono>
#include <fstream>
#include "src/dictionary_sc.h"
#include "src/dictionary_avl.h"
#include "src/dictionary_heap.h"

using namespace std;
using namespace std::chrono;

template<typename Function>
double measure_time(Function func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {
    const int SIZES[] = {2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000};
    const int TESTS = 100;
    const int SEEDS[] = {250, 300, 350, 400, 450};

    ofstream resultsFile("results/DictionaryResults.txt");

    if (!resultsFile.is_open()) {
        cerr << "Nie udało się otworzyć pliku do zapisu wyników." << endl;
        return 1;
    }

    for (int size : SIZES) {
        cout << "\n\n==== Testowanie słowników dla rozmiaru: " << size << " elementów ====" << endl;
        resultsFile << "\n\n==== Testowanie słowników dla rozmiaru: " << size << " elementów ====\n";

        double total_insert_sc = 0.0, total_remove_sc = 0.0;
        double total_insert_avl = 0.0, total_remove_avl = 0.0;
        double total_insert_heap = 0.0, total_remove_heap = 0.0;
        int seedCount = 0;

        for (int seed : SEEDS) {
            srand(seed);

            DictionarySC dictSC;
            DictionaryAVL dictAVL;
            DictionaryHeap dictHeap;

            double insert_sum_sc = 0.0, remove_sum_sc = 0.0;
            double insert_sum_avl = 0.0, remove_sum_avl = 0.0;
            double insert_sum_heap = 0.0, remove_sum_heap = 0.0;

            for (int t = 0; t < TESTS; t++) {
                // TESTY INSERT
                for (int i = 0; i < size; i++) {
                    int key = rand() % (size * 10);
                    int value = rand() % 10000;
                    insert_sum_sc += measure_time([&]() { dictSC.insert(key, value); });
                    insert_sum_avl += measure_time([&]() { dictAVL.insert(key, value); });
                    insert_sum_heap += measure_time([&]() { dictHeap.insert(key, value); });
                }

                // TESTY REMOVE
                for (int i = 0; i < size / 2; i++) {
                    int key = rand() % (size * 10);
                    remove_sum_sc += measure_time([&]() { dictSC.remove(key); });
                    remove_sum_avl += measure_time([&]() { dictAVL.remove(key); });
                    remove_sum_heap += measure_time([&]() { dictHeap.remove(key); });
                }

                dictSC.clear();
                dictAVL.clear();
                dictHeap.clear();
            }

            total_insert_sc += insert_sum_sc / TESTS;
            total_remove_sc += remove_sum_sc / TESTS;

            total_insert_avl += insert_sum_avl / TESTS;
            total_remove_avl += remove_sum_avl / TESTS;

            total_insert_heap += insert_sum_heap / TESTS;
            total_remove_heap += remove_sum_heap / TESTS;

            seedCount++;
        }

        // 🔹 Zapisywanie wyników do pliku
        resultsFile << "\n*** Wyniki dla DictionarySC ***\n";
        resultsFile << "Insert: " << (total_insert_sc / seedCount) << " s\n";
        resultsFile << "Remove: " << (total_remove_sc / seedCount) << " s\n";

        resultsFile << "\n*** Wyniki dla DictionaryAVL ***\n";
        resultsFile << "Insert: " << (total_insert_avl / seedCount) << " s\n";
        resultsFile << "Remove: " << (total_remove_avl / seedCount) << " s\n";

        resultsFile << "\n*** Wyniki dla DictionaryHeap ***\n";
        resultsFile << "Insert: " << (total_insert_heap / seedCount) << " s\n";
        resultsFile << "Remove: " << (total_remove_heap / seedCount) << " s\n";
    }

    resultsFile.close();
    return 0;
}