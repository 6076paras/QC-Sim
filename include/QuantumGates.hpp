//
// Created by Paras Pokharel on 2025-01-01.
//
#pragma once
#include <Eigen/Dense>
#include <complex>
#include <cmath>
#include <iostream>
#include <unsupported/Eigen/KroneckerProduct>

template<typename MatrixClass = Eigen::MatrixXcd>
class QuantumGates {
public:
    static MatrixClass X();
    static MatrixClass Y();
    static MatrixClass Z();
    static MatrixClass CNOT();
    static MatrixClass H();
    static MatrixClass I();
    MatrixClass getRepresentation(std::string stringGate, int nQubit, int target, int control);
};

#include "QuantumGates.inl"


