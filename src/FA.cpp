#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/*
autor: Tymoteusz Roźmiarek
zrodla: Cormen T.H., Leiserson Ch.E., Rivest R.L.: Wprowadzenie do algorytmów
*/

std::vector<std::vector<int>> ComputeTransitionFunction(const std::string &P, const std::string &alphabet) {
    int m = P.length();
    std::vector<std::vector<int>> delta(m + 1, std::vector<int>(alphabet.size(), 0));

    for (int q = 0; q <= m; q++) {
        for (int a = 0; a < alphabet.size(); a++) {
            char currentChar = alphabet[a];
            int k = std::min(m + 1, q + 2);

            std::string Pqa = P.substr(0, q) + currentChar;
            do {
                k--;
            } while (k > 0 && P.substr(0, k) != Pqa.substr(Pqa.size() - k));

            delta[q][a] = k;
        }
    }
    return delta;
}

void FiniteAutomatonMatcher(const std::string &T, const std::vector<std::vector<int>> &delta, int m) {
    int n = T.length();
    int q = 0;

     for (int i = 0; i < n; i++) {
        q = delta[q][T[i]-'a'];
        if (q == m) {
            std::cout << "Wzorzec znaleziono na pozycji: " << i - m + 1 << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {

    std::string pattern = argv[1];
    std::string text;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    std::ifstream input_file(argv[2]);
    input_file >> text;
    input_file.close();

    std::vector<std::vector<int>> delta = ComputeTransitionFunction(pattern, alphabet);

    FiniteAutomatonMatcher(text, delta, pattern.length());

    return 0;
}
