#pragma once
/**
 * @brief Quantum Circuit class that acts as container 
 * Provides methods to:
 * - Add quantum gates
 * - Build circuits
 * - Display circuit diagram
 * - Execute quantum operations
 */
class QuantumCircuit{
    
    public:
        int nQubit;
        void H(int qubit);
        void Z(int qubit);
        void X(int qubit);
        void CNOT(int control, int target);
        void display();
    private:
};