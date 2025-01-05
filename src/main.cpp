#include <iostream>
#include "QuantumState.hpp"
#include "QuantumGates.hpp"
int main() {
    // testing
    int qubitsize = 2;
    QuantumState qs(qubitsize);
    std::cout << "Initial State Vector:" << std::endl;
    qs.displayState();

    // multiply with gates

    return 0;
}
