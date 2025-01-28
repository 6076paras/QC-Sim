#include "QuantumCircuits.hpp"
#include <iostream>
#include <vector>

// initialize a circuit with n qubits
QuantumCircuit::QuantumCircuit(int nQubits) {
    this->nQubit = nQubits;
} 

// add H gate to the container
void QuantumCircuit::H(int qubit){
    this->container.push_back({"H",qubit}); 
}

// add X gate to the container
void QuantumCircuit::X(int qubit){
    this->container.push_back({"X",qubit}); 
}

// add Z gate to the container
void QuantumCircuit::Z(int qubit){
    this->container.push_back({"Z",qubit}); 
}

// add Z gate to the container
void QuantumCircuit::CNOT(int target, int control){
    this->container.push_back({"Z", target, control}); 
}

// display the container visually
void QuantumCircuit::display(){

    // loop throguh "a" qubit, and add operators belonging to it
    for (int q = 1; q == this->nQubit + 1 ; q++){
            
            // lopp through gates and Print gates beloning to a qubit
            for (auto& op : container){
                if (op.target == q || op.control == q) {
                    if (op.gateName == "H") {
                        std::cout << "─[H]─";
                    }
                    else if (op.gateName == "X") {
                        std::cout << "─[X]─";
                    }
                    else if (op.gateName == "Z") {
                        std::cout << "─[Z]─";
                    }
                    else if (op.gateName == "CNOT") {
                        if (q == op.control) {
                            std::cout << "──●──";  
                        }
                        else if (q == op.target) {
                             std::cout << "──⊕──";  
                        }
                    }
                }
                // print empty line  
                else {
                std::cout << "─────";  
                }

            };
    };

}