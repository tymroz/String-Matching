#include <iostream>

void Finnite_Automata_Matcher(text, transition_function, pattern_length) {
    n = text.length
    int q = 0
    for(int i = 0; i <= n; i++) {
        q = transition_function(q, text[i]);
        if(q == m) {
            std::cout << "Pattern occurs with shift" << i - m << std::endl;
        }
    }
}

int Compute_Transition_Function (pattern, alphabet) {
    m = pattern.length
    for(int q = 0; q <=m; q++) {
        for(char a : alphabet) {
            k = min(m+1, q+2)
            while(Pk is suffix of Pqa) {
                k = k - 1
            }
        }
        transition_function(q, a) = k
    }

    return transition_function
}

int main(int argc, char* argv[]) {
    
    return 0;
}
