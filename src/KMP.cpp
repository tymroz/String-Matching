#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/*
autor: Tymoteusz Roźmiarek
zrodla: Cormen T.H., Leiserson Ch.E., Rivest R.L.: Wprowadzenie do algorytmów
*/

std::vector<int> Compute_Prefix_Function(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> pi(m);
    int k = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

void KMP_Matcher(const std::string& pattern, const std::string& text) {
    int m = pattern.length();
    int n = text.length();
    std::vector<int> pi = Compute_Prefix_Function(pattern);
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            std::cout << "Wzorzec znaleziono na pozycji: " << i - m + 1 << std::endl;
            q = pi[q - 1];
        }
    }
}

int main(int argc, char* argv[]) {
    std::string pattern = argv[1];
    std::string text;

    std::ifstream input_file(argv[2]);

    input_file >> text;
    input_file.close();

    KMP_Matcher(pattern, text);

    return 0;
}