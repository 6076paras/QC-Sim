//
// Created by Paras Pokharel on 2025-01-01.
//
#pragma once
#include <Eigen/Dense>
#include <iostream>
#include <cmath>
#include <iomanip> 
class QuantumState {
private:
    int size;
    Eigen::VectorXcd complexXVector;


public:
    QuantumState(int nQubit);
    void initialize();
    void normalize();
    Eigen::VectorXcd getStateVector();
    void display();
};

