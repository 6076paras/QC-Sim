#include "QuantumCircuit.hpp"
#include "QuantumGates.hpp"
#include "QuantumState.hpp"  
#include <iostream>
#include <memory>  


// initialize a circuit with n qubits
QuantumCircuit::QuantumCircuit(int nQubit) 
    : nQubit(nQubit) {

        // instantiate state
        state = std::make_unique<QuantumState>(*this);
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
    this->container.push_back({"CNOT", target, control}); 
}

// return the combined transformation
Eigen::MatrixXcd QuantumCircuit::getCombTransform(QuantumGates<>& gateObj){

    // init
    Eigen::MatrixXcd result = Eigen::MatrixXcd::Identity(pow(2,this->nQubit), pow(2,this->nQubit));

    // loop and multiply
    for ( unitOperator& op : this->container){
        // get representation
        Eigen::MatrixXcd representation = gateObj.getRepresentation(op.gateName, this->nQubit, op.target, op.control);
        result *= representation;
    }
    return result;
}


// display the container visually
void QuantumCircuit::display(){

    std::cout << "\n╔════════════════════════╗";
    std::cout << "\n║     Quantum Circuit    ║";
    std::cout << "\n╚════════════════════════╝\n\n";
    
    // loop throguh "a" qubit, and add operators belonging to it
    for (int q = 1; q < this->nQubit + 1 ; q++){
        std::cout << "q" << q << ":  "; 

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
                else {
                std::cout << "─────";  
                }

            }
        std::cout << "\n";
    }
    std::cout << "\n"; 
}

// clear
void QuantumCircuit::clear() {
    container.clear();
}
