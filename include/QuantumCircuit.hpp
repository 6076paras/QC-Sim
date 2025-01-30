#pragma once
#include <iostream>
#include <vector>   
#include <memory>  

// forward declaration for circular dependency
class QuantumState;

/**
 * @brief Quantum Circuit class that acts as container 
 * Provides methods to:
 * - Execute quantum operations
 */
class QuantumCircuit {

    private:
        struct unitOperator {
            std::string gateName;
            int target;
            int control = -1;
        };
        std::vector<unitOperator> container;
    
    public:
        int nQubit;
        std::unique_ptr<QuantumState> state;
        QuantumCircuit(int nQubits); 

        

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