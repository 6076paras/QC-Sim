//
// Created by Paras Pokharel on 2025-01-01.
//

#ifndef QC_SIM_QUANTUMGATES_HPP
#define QC_SIM_QUANTUMGATES_HPP

#include <Eigen/Dense>

class QuantumGates {
public:
    static Eigen::Matrix2cd X();
    static Eigen::Matrix2cd Y();
    static Eigen::Matrix2cd Z();
};


#endif //QC_SIM_QUANTUMGATES_HPP
