//
// Created by Paras Pokharel on 2025-01-01.
//

#ifndef QC_SIM_QUANTUMSTATE_HPP
#define QC_SIM_QUANTUMSTATE_HPP

#include <Eigen/Dense>
class QuantumState {
private:
    void normalize(Eigen::VectorXcd complexVector);
public:
    QuantumState();
    // n dimensional complex vector
    Eigen::VectorXcd complexVector(int size);

    // state vector
    Eigen::VectorXcd stateVector();

    // initialize
    void initializeStateVector(const Eigen::VectorXcd& complexVector);





};


#endif //QC_SIM_QUANTUMSTATE_HPP
