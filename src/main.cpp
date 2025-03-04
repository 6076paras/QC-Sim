#include <iostream>
#include "QuantumCircuit.hpp"
#include "QuantumState.hpp"
#include "QuantumGates.hpp"
int main() {
    // Create circuit first
    QuantumCircuit qc(2);
    
    // Use circuit's state
    qc.state->display();

    // test circuit operations
    qc.X(1);
    qc.CNOT(1,2);
    qc.display();

    // transform and display
    qc.transformState();
    qc.state->display();

    return 0;
}
