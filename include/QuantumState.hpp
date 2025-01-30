//
// Created by Paras Pokharel on 2025-01-01.
//
#pragma once
#include "QuantumCircuit.hpp"
#include <Eigen/Dense>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>  

class QuantumState {
private:
    int size;
    Eigen::VectorXcd stateVector;
    
    // helper methods for display
    void displayVector();
    void displayDirac();
    enum Format {
        diracFormat,
        vectorFormat,
        DEFAULT = vectorFormat
    };

public:
    explicit QuantumState(QuantumCircuit& circuit); 
    void initialize();
    void transformState(Eigen::MatrixXcd& combTransfrom);
    void normalize();
    void display(Format format = DEFAULT);
};

