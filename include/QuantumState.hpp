//
// Created by Paras Pokharel on 2025-01-01.
//

#ifndef QC_SIM_QUANTUMSTATE_HPP
#define QC_SIM_QUANTUMSTATE_HPP

#include <Eigen/Dense>
class QuantumState {
public:
    QuantumState(int size);
    int size;
    Eigen::VectorXcd complexXVector;
    void initialize();
    void normalize();
    Eigen::VectorXcd getStateVector();
    void displayState();
};


#endif //QC_SIM_QUANTUMSTATE_HPP
