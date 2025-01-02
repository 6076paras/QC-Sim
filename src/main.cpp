#include <iostream>
#include "QuantumState.hpp"
int main() {
    // testing
    int qubitSize = 2;
    QuantumState qs(qubitSize);
    std::cout << "Initial State Vector:" << std::endl;
    qs.displayState();

    for (int i = 1; i <= 5; i++) {

        std::cout << "i = " << i << std::endl;
    }
    return 0;
}
