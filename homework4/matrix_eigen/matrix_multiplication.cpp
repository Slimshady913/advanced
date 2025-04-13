#include <iostream>
#include <Eigen/Dense>

int main() {
    // Define the matrices
    Eigen::Matrix<double, 3, 2> A;
    Eigen::Matrix<double, 2, 3> B;

    // Initialize matrix A
    A << 1, 2,
         3, 4,
         5, 6;

    // Initialize matrix B
    B << 7, 8, 9,
         10, 11, 12;

    // Perform matrix multiplication
    Eigen::Matrix<double, 3, 3> C = A * B;

    // Print the result
    std::cout << "The result of the matrix multiplication is:\n" << C << std::endl;

    return 0;
}