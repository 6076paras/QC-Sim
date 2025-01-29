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

    private:
        int nQubit;
        struct unitOperator {
            std::string gateName;
            int target;
            int control = -1;
        };
        std::vector<unitOperator> container;
    
    public:
        explicit QuantumCircuit(int nQubits); 

        // gate operations
        // TODO: chain links
        void H(int qubit);
        void Z(int qubit);
        void X(int qubit);
        void CNOT(int control, int target);
        
        // circuit operations
        void display();
        void clear(); 
        
        
};