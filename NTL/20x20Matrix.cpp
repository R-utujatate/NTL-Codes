#include <NTL/mat_ZZ.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace NTL;

int main() {
    // Define the input and output file names
    string inputFileName = "INPUT.txt";
    string outputFileName = "OUTPUT.txt";

    // Open the input file
    ifstream inputFile(inputFileName);

    // Check if the input file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    // Read the 20x20 matrix from the input file
    ZZ p=conv<ZZ>("101");
    ZZ_p::init(p);
    Mat<ZZ_p> matrix;
    matrix.SetDims(20,20);
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
    for (long i = 0; i < 20; ++i) {
        for (long j = 0; j < 20; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile << endl;

    // Calculate the determinant of the given matrix
    //ZZ det = determinant(matrix);
    outputFile << "Determinant of the given matrix: " << determinant(matrix) << endl << endl;

    // Define a vector to store 10x10 submatrices with determinant zero
    vector<Mat<ZZ_p>> submatrices;

    // Extract all 10x10 submatrices and calculate their determinants
    for (long i = 0; i < 10; ++i) {
        for (long j = 0; j < 10; ++j) {
            // Create a 10x10 submatrix starting from position (i, j)
            Mat<ZZ_p> submatrix;
            submatrix.SetDims(10, 10);
            for (long row = 0; row < 10; ++row) {
                for (long col = 0; col < 10; ++col) {
                    submatrix[row][col] = matrix[i + row][j + col];
                }
            }

            // Calculate the determinant of the submatrix
            ZZ_p subDet = determinant(submatrix);

            // If determinant is zero, store the submatrix
            if (subDet == 0) {
                submatrices.push_back(submatrix);
            }
        }
    }

    // Write the submatrices with determinant zero to the output file along with their determinants
    if (!submatrices.empty()) {
        outputFile << "Submatrices with determinant zero:" << endl;
        for (const auto& submatrix : submatrices) {
            outputFile << "Submatrix:" << endl;
            for (long i = 0; i < 10; ++i) {
                for (long j = 0; j < 10; ++j) {
                    outputFile << submatrix[i][j] << " ";
                }
                outputFile << endl;
            }
            ZZ_p subDet = determinant(submatrix);
            outputFile << "Determinant: " << subDet << endl;
            outputFile << "--------------------" << endl;
        }
    } else {
        outputFile << "No submatrices with determinant zero found." << endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Matrix and its submatrices with determinant zero written to '" << outputFileName << "'." << endl;

    return 0;
}
