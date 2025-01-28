#pragma once
#include <iostream>
#include <vector>   
#include <iostream>
/**
 * @brief Quantum Circuit class that acts as container 
 * Provides methods to:
 * - Add quantum gates
 * - Build circuits
 * - Display circuit diagram
 * - Execute quantum operations
 */
class QuantumCircuit {
    
    public:
        explicit QuantumCircuit(int nQubits); 
        int nQubit;
        void H(int qubit);
        void Z(int qubit);
        void X(int qubit);
        void CNOT(int control, int target);
        void display();
        struct unitOperator {
            std::string gateName;
            int target;
            int control = -1;
        };
        std::vector<unitOperator> container;
    private:
};