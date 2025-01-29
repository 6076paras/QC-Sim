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
    Eigen::VectorXcd complexXVector;
    QuantumCircuit* circuit;  // Changed to raw pointer since QuantumState doesn't own QuantumCircuit
    
    // helper methods for display
    void displayVector();
    void displayDirac();

public:
    enum Format {
        diracFormat,
        vectorFormat,
        DEFAULT = vectorFormat
    };

    explicit QuantumState(QuantumCircuit* circuit);  // Keep raw pointer in constructor
    void initialize();
    void normalize();
    Eigen::VectorXcd getStateVector();
    void display(Format format = DEFAULT);
};

