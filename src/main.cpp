#include <iostream>
#include "QuantumCircuit.hpp"
#include "QuantumState.hpp"
#include "QuantumGates.hpp"
int main() {
    // testing
    int qubitsize = 2;
    QuantumState qs(qubitsize);
    qs.display();

    // test and print gates 
    std::cout << QuantumGates<>::H(); 

    // test cicuit
    QuantumCircuit qc(2);
    qc.X(1);
    qc.CNOT(1,2);
    qc.display();

    return 0;
}
