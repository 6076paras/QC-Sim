//
// Created by Paras Pokharel on 2025-01-01.
//
#include "QuantumGates.hpp"
template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::X() {
    MatrixClass X = MatrixClass::Zero(2,2);
    X << std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0),
        std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0);
    return X;

}
template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::Y() {
    MatrixClass Y = MatrixClass::Zero(2,2);;
    Y << std::complex<double>(0.0, 0.0), std::complex<double>(0.0, -1.0),
        std::complex<double>(0.0, 1.0), std::complex<double>(0.0, 0.0);
    return Y;

}
template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::Z() {
    MatrixClass Z = MatrixClass::Zero(2,2);;
    Z << std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0),
             std::complex<double>(0.0, 0.0), std::complex<double>(-1.0, 0.0);
    return Z;

}

template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::CNOT() {
    MatrixClass CNOT = MatrixClass::Zero(4,4);
    CNOT << std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0),
            std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0),
            std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0),
            std::complex<double>(0.0, 0.0), std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0);
    return CNOT;

}

template<typename MatrixClass>
MatrixClass QuantumGates<MatrixClass>::H(){
    MatrixClass H = MatrixClass::Zero(2,2);
    H << std::complex<double>(1.0 / std::sqrt(2), 0.0), std::complex<double>(1.0 / std::sqrt(2), 0.0),
         std::complex<double>(1.0 / std::sqrt(2), 0.0), std::complex<double>(-1.0 / std::sqrt(2), 0.0);
    return H;
}

template<typename MatrixClass>  
MatrixClass QuantumGates<MatrixClass>::I() {
    MatrixClass Y = MatrixClass::Zero(2,2);;
    I << std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 1.0),
        std::complex<double>(1.0, 0.0), std::complex<double>(1.0, 0.0);
    return I;
}

template<typename MatrixClass>
MatrixClass QuantumGates<MatrixClass>::getRepresentation(std::string stringGate, int nQubit, int target, int control){
    
    // get equivlent gates from string
    MatrixClass Gate;
    if (stringGate == "H"){
        Gate = H();
    }
    if (stringGate == "Z"){
        Gate = Z();
    }
    if (stringGate == "X"){
        Gate = X();
    }
    if (stringGate == "Y"){
        Gate = Y();
    }
    if (stringGate == "CNOT"){
        Gate = CNOT();
    }
    
    // init
    Eigen::MatrixXcd result = Eigen::MatrixXcd::Identity(1,1);
    
    // loop through each qubit and find the gate representaion 
    for (int i = 1 ; i < nQubit + 1  ; i++){
        
        // if qubit, use Gate else, I
        if (target == i){
            result = Eigen::kroneckerProduct(result, Gate);
        } else {
            MatrixClass I = MatrixClass::Identity(2,2);
            result = Eigen::kroneckerProduct(result, I);
        }
    }
    return result
}

