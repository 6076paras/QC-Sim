#pragma once
#include "QuantumGates.hpp"
#include <iostream>
#include <vector>   
#include <memory>  
#include <Eigen/Dense>

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
        Eigen::MatrixXcd getCombTransform(QuantumGates<>& gateObj);
    
    public:
        int nQubit;
        std::unique_ptr<QuantumState> state;
        QuantumCircuit(int nQubit); 

        

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