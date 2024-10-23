#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> build_automaton(const string& pattern) {
    int m = pattern.size();
    vector<vector<int>> transitions(m+1, vector<int>(256, 0));

    transitions[0][pattern[0]] = 1;

    int state = 0;
    for (int i = 1; i <= m; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            transitions[i][c] = transitions[state][c];
        }
        transitions[i][pattern[i]] = i + 1;
        state = transitions[state][pattern[i]];
    }

    return transitions;
}

void search_pattern(const string& text, const vector<vector<int>>& transitions) {
    int m = transitions.size() - 1;
    int state = 0;
    for (int i = 0; i < text.size(); i++) {
        state = transitions[state][text[i]];
        if (state == m) {
            cout << "Wzorzec znaleziono na pozycji: " << i - m + 1 << endl;
        }
    }
}

int main() {
    string pattern = "abc";
    string text = "abcabcabc";

    vector<vector<int>> automaton = build_automaton(pattern);
    search_pattern(text, automaton);

    return 0;
}