//
// Created by Paras Pokharel on 2025-01-01.
//

#include <iostream>
#include <cmath>
#include "QuantumState.hpp"
QuantumState::QuantumState(int nQubit){
    this->size = pow(2,nQubit);
    complexXVector.resize(size);
    initialize();
}

void QuantumState::initialize() {
    // initialize to (|0>)^n state
    complexXVector(0) = std::complex<double>(1.0,0.0);
}

void QuantumState::display(){
    std::cout << complexXVector;
}

/* TODO: 
 * - better vectorial display of stateVector
 * - option for dirac notation
 * - switching opton
 */