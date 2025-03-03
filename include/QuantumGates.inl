//
// Created by Paras Pokharel on 2025-01-01.
//
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
MatrixClass QuantumGates<MatrixClass>::getRepresentation(std::string stringGate, int nQubit, int target, int control) {
    // get equivalent gates from string
    MatrixClass Gate;
    MatrixClass result = MatrixClass::Identity(1,1);

    if (stringGate == "CNOT") {
        Gate = CNOT();
        // special handling for CNOT
        for (int i = 1; i < nQubit + 1; i++) {
            if (i == control || i == target) {
                if (i == std::min(control, target)) {
                    result = Eigen::kroneckerProduct(result, Gate);
                    i++; 
                }
            } else {
                MatrixClass I = MatrixClass::Identity(2,2);
                result = Eigen::kroneckerProduct(result, I).eval();
            }
        }
    } else {
        // handle single-qubit gates
        if (stringGate == "H") Gate = H();
        if (stringGate == "X") Gate = X();
        if (stringGate == "Y") Gate = Y();
        if (stringGate == "Z") Gate = Z();
        
        // build tensor product
        for (int i = 1; i < nQubit + 1; i++) {
            if (target == i) {
                // Debug prints before kronecker product
                std::cout << "\nDebug before kronecker product:";
                std::cout << "\nResult matrix (" << result.rows() << "x" << result.cols() << "):\n" << result;
                std::cout << "\nGate matrix (" << Gate.rows() << "x" << Gate.cols() << "):\n" << Gate << std::endl;
                result = Eigen::kroneckerProduct(result, Gate).eval();
            } else {
                MatrixClass I = MatrixClass::Identity(2,2);
                result = Eigen::kroneckerProduct(result, I).eval();
            }
        }
    }
    
    return result;
}

