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


void QuantumState::display(Format format) {
    std::cout << "\n╔═══════════════════════════════╗";
    std::cout << "\n║      Quantum State Vector     ║";
    std::cout << "\n╚═══════════════════════════════╝\n\n";

    switch(format) {
        case vectorFormat:
            displayVector();
            break;
        case diracFormat:
            displayDirac();
            break;
    }
}

void QuantumState::displayVector() {
    for (int i = 0; i < size; i++) {
        std::cout << (i == 0 ? "⎡" : i == size-1 ? "⎣" : "⎢");
        std::complex<double> z = complexXVector(i);
        std::cout << std::fixed << std::setprecision(3) 
                 << " (" << std::setw(6) << z.real() 
                 << " + " << std::setw(6) << z.imag() << "i) ";
        std::cout << (i == 0 ? "⎤\n" : i == size-1 ? "⎦\n" : "⎥\n");
    }
    std::cout << "\n";
}

void QuantumState::displayDirac() {
    bool first = true;
    for (int i = 0; i < size; i++) {
        std::complex<double> z = complexXVector(i);
        if (std::abs(z) > 1e-10) {
            if (!first) std::cout << " + ";
            std::cout << "(" << std::fixed << std::setprecision(3) 
                     << z.real() << " + " << z.imag() << "i)|" 
                     << i << "⟩";
            first = false;
        }
    }
    std::cout << "\n\n";
}

