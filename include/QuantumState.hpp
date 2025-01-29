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
    std::shared_ptr<QuantumCircuit> circuit;  
    
    // helper methods for display
    void displayVector();
    void displayDirac();

public:
    enum Format {
        diracFormat,
        vectorFormat,
        DEFAULT = vectorFormat
    };

    QuantumState(QuantumCircuit* circuit);  
    void initialize();
    void normalize();
    Eigen::VectorXcd getStateVector();
    void display(Format format = DEFAULT);
};

