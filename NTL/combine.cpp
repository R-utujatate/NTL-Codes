#include <iostream>
#include <sstream>
#include <NTL/mat_ZZ.h>
#include <NTL/ZZ_p.h>
#include <mpi.h>

using namespace std;
using namespace NTL;

// Function to calculate determinant of a matrix
ZZ calculateDeterminant(const Mat<ZZ>& matrix) {
    ZZ det=determinant(matrix);
    return det;
}

/// @brief 
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Master process takes the input matrix from the user
    Mat<ZZ> matrix;
    matrix.SetDims(3,3);
    if (rank == 0) {
        // Prompt user to enter the matrix
        cout << "Enter the 3x3 matrix:" << endl;

        // Read the matrix from input using stringstream and string
        stringstream inputMatrixStream;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ZZ element;
                cin >> element;
                inputMatrixStream << element << " ";
            }
            inputMatrixStream << endl;
        }
        inputMatrixStream >> matrix;
        
    }

    

    // Calculate the determinant of the matrix
    ZZ det = calculateDeterminant(matrix);

    // Output the determinant from each process
    cout << "Process " << rank << " calculated determinant: " << det << endl;

    MPI_Finalize();
    return 0;
}
