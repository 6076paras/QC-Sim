//
// Created by Paras Pokharel on 2025-01-01.
//
#ifndef QC_SIM_QUANTUMGATES_INL
#define QC_SIM_QUANTUMGATES_INL

#include "QuantumGates.hpp"
#include <complex>

template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::X() {
    MatrixClass X = MatrixClass::Zero(2,2);
    X << std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0),
        std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0);
    return X;

}
template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::Y() {
    MatrixClass Y = MatrixClass::Zero(2,2);;
    Y << std::complex<double>(0.0, 0.0), std::complex<double>(0.0, -1.0),
        std::complex<double>(0.0, 1.0), std::complex<double>(0.0, 0.0);
    return Y;

}
template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::Z() {
    MatrixClass Z = MatrixClass::Zero(2,2);;
    Z << std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0),
             std::complex<double>(0.0, 0.0), std::complex<double>(-1.0, 0.0);
    return Z;

}

template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::CNOT() {
    MatrixClass CNOT = MatrixClass::Zero(4,4);
    CNOT << std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0),
            std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0),
            std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0),
            std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0);
    return CNOT;

}

template<typename MatrixClass>
MatrixClass QuantumGates<MatrixClass>::H(){
    MatrixClass H = MatrixClass::Zero(2,2);
    H << std::complex<double>(1.0 / std::sqrt(2), 0.0), std::complex<double>(1.0 / std::sqrt(2), 0.0),
         std::complex<double>(1.0 / std::sqrt(2), 0.0), std::complex<double>(-1.0 / std::sqrt(2), 0.0);
    return H;
}
#endif