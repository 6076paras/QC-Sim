#include <iostream>
#include "QuantumState.hpp"
#include "QuantumGates.hpp"
int main() {
    // testing
    int qubitsize = 2;
    QuantumState qs(qubitsize);
    std::cout << "Initial State Vector:" << std::endl;
    qs.displayState();

    // test and print gates 
    std::cout << QuantumGates<>::H();

    return 0;
}
