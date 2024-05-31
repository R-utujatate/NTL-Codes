#include <NTL/mat_ZZ.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace NTL;

int main() {
    // Define the input and output file names
    string inputFileName = "Matrix_input1.txt";
    string outputFileName = "Matrix_output1.txt";

    // Open the input file
    ifstream inputFile(inputFileName);

    // Check if the input file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    // Read the 20x20 matrix from the input file
    ZZ p = conv<ZZ>("101");
    ZZ_p::init(p);
    Mat<ZZ_p> matrix;
    matrix.SetDims(78, 78);
    inputFile >> matrix;

    // Close the input file
    inputFile.close();

    // Open the output file
    ofstream outputFile(outputFileName);

    // Check if the output file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the output file." << endl;
        return 1;
    }

    // Write the given matrix to the output file
    outputFile << "Given Matrix:" << endl;
    for (long i = 0; i < 78; ++i) {
        for (long j = 0; j < 78; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile << endl;

    // Calculate the determinant of the given matrix
    ZZ_p det = determinant(matrix);
    outputFile << "Determinant of the given matrix: " << det << endl << endl;

    // Write all submatrices with determinant zero to the output file
    outputFile << "Submatrices with determinant zero:" << endl;
    for (long size = 39; size <= 78; ++size) {
        for (long i = 0; i <= 78 - size; ++i) {
            for (long j = 0; j <= 78 - size; ++j) {
                // Create a submatrix starting from position (i, j) with size x size
                Mat<ZZ_p> submatrix;
                submatrix.SetDims(size, size);
                for (long row = 0; row < size; ++row) {
                    for (long col = 0; col < size; ++col) {
                        submatrix[row][col] = matrix[i + row][j + col];
                    }
                }

                // Calculate the determinant of the submatrix
                ZZ_p subDet = determinant(submatrix);

                // Check if the determinant is zero
                if (IsZero(subDet)) {
                    // Write submatrix and its determinant to the output file
                    outputFile << "Submatrix of size " << size << "x" << size << " starting at (" << i << ", " << j << "):" << endl;
                    for (long row = 0; row < size; ++row) {
                        for (long col = 0; col < size; ++col) {
                            outputFile << submatrix[row][col] << " ";
                        }
                        outputFile << endl;
                    }
                    outputFile << "Determinant: " << subDet << endl << endl;
                }
            }
        }
    }

    // Close the output file
    outputFile.close();

    cout << "Matrix and submatrices with zero determinants written to '" << outputFileName << "'." << endl;

    return 0;
}