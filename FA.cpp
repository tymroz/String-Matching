#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::vector<int>> Compute_Transition_Function(const std::string& pattern) {
    int m = pattern.size();
    std::vector<std::vector<int>> transitions(m+1, std::vector<int>(26, 0));
    transitions[0][pattern[0] - 'a'] = 1;

    int q = 0;
    for (int i = 1; i <= m; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            transitions[i][c - 'a'] = transitions[q][c - 'a'];
        }
        transitions[i][pattern[i] - 'a'] = i + 1;
        q = transitions[q][pattern[i] - 'a'];
    }

    return transitions;
}

void Finnite_Automata_Matcher(const std::string& text, const std::vector<std::vector<int>>& transitions) {
    int m = transitions.size() - 1;
    int q = 0;
    for (int i = 0; i < text.size(); i++) {
        q = transitions[q][text[i] - 'a'];
        if (q == m) {
            std::cout << "Wzorzec znaleziono na pozycji: " << i - m + 1 << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    std::string pattern = argv[1];
    std::string text;

    std::ifstream input_file(argv[2]);

    input_file >> text;
    input_file.close();

    std::vector<std::vector<int>> automaton = Compute_Transition_Function(pattern);
    Finnite_Automata_Matcher(text, automaton);

    return 0;
}