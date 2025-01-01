//
// Created by Paras Pokharel on 2025-01-01.
//

#ifndef QC_SIM_QUANTUMSTATE_HPP
#define QC_SIM_QUANTUMSTATE_HPP

#include <Eigen/Dense>
class QuantumState {
public:
    QuantumState();
    Eigen::Vector2cd C2() const;
};


#endif //QC_SIM_QUANTUMSTATE_HPP
