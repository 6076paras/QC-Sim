//
// Created by Paras Pokharel on 2025-01-01.
//

#include "QuantumGates.hpp"

Eigen::Matrix2cd QuantumGates::X() {
    Eigen::Matrix2cd X ;
    X << std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0),
        std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0);
    return X;

}

Eigen::Matrix2cd QuantumGates::Y() {
    Eigen::Matrix2cd Y;
    Y << std::complex<double>(0.0, 0.0), std::complex<double>(0.0, -1.0),
        std::complex<double>(0.0, 1.0), std::complex<double>(0.0, 0.0);
    return Y;

}

Eigen::Matrix2cd QuantumGates::Z() {
    Eigen::Matrix2cd Z;
    Z << std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0),
             std::complex<double>(0.0, 0.0), std::complex<double>(-1.0, 0.0);
    return Z;

}