//
// Created by Paras Pokharel on 2025-01-01.
//

#ifndef QC_SIM_QUANTUMGATES_HPP
#define QC_SIM_QUANTUMGATES_HPP

#include <Eigen/Dense>

template<typename MatrixClass = Eigen::MatrixXcd>
class QuantumGates {
public:
    static MatrixClass X();
    static MatrixClass Y();
    static MatrixClass Z();
};

#include "QuantumGates.inl"

#endif //QC_SIM_QUANTUMGATES_HPP
