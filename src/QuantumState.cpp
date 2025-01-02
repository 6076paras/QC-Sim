//
// Created by Paras Pokharel on 2025-01-01.
//

#include "QuantumState.hpp"
QuantumState::QuantumState(int size){
    this->size = size;
    complexXVector.resize(size);
    initialize();
};

void QuantumState::initialize() {
    // initialize to (|0>)^n state
    complexXVector[0] = std::complex<double>(1.0,0.0);
};

void QuantumState::displayState(){
    std::cout << complexXVector;
};

