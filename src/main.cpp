#include <iostream>
#include "QuantumState.hpp"
int main() {
    // testing
    int qubitsize = 2;
    QuantumState qs(qubitsize);
    std::cout << "Initial State Vector:" << std::endl;
    qs.displayState();
    return 0;
}
