//
// Created by Paras Pokharel on 2025-01-01.
//

 /* TODO: 
 * - option for dirac notation
 * - switching opton
 */
#include "QuantumState.hpp"
QuantumState::QuantumState(int nQubit){
    this->size = pow(2,nQubit);
    this->complexXVector.resize(size);
    initialize();
}

void QuantumState::initialize() {
    // initialize to (|0>)^n state
    this->complexXVector(0) = std::complex<double>(1.0,0.0);
}

void QuantumState::display() {
    std::cout << "\n╔═══════════════════════════════╗";
    std::cout << "\n║      Quantum State Vector     ║";
    std::cout << "\n╚═══════════════════════════════╝\n\n";

    for (int i = 0; i < size; i++) {
        
        // start brackets for each row
        std::cout << (i == 0 ? "⎡" : i == size-1 ? "⎣" : "⎢");
        
        // get complex number
        std::complex<double> z = complexXVector(i);
        
        // format: (a + bi)
        std::cout << std::fixed << std::setprecision(3) 
                 << " (" << std::setw(6) << z.real() 
                 << " + " << std::setw(6) << z.imag() << "i) ";
        
        // end brackets for each row
        std::cout << (i == 0 ? "⎤\n" : i == size-1 ? "⎦\n" : "⎥\n");
    }
    std::cout << "\n";
}

