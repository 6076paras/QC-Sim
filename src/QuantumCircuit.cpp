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