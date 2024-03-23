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
    Mat<ZZ> matrix;
    inputFile >> matrix;

    // Close the input file
    inputFile.close();

    // Define a vector to store 10x10 submatrices with determinant zero
    vector<Mat<ZZ>> submatrices;

    // Extract all 10x10 submatrices and calculate their determinants
    for (long i = 0; i < 10; ++i) {
        for (long j = 0; j < 10; ++j) {
            // Create a 10x10 submatrix starting from position (i, j)
            Mat<ZZ> submatrix;
            submatrix.SetDims(10, 10);
            for (long row = 0; row < 10; ++row) {
                for (long col = 0; col < 10; ++col) {
                    submatrix[row][col] = matrix[i + row][j + col];
                }
            }

            // Calculate the determinant of the submatrix
            ZZ det;
            determinant(det, submatrix);

            // If determinant is zero, store the submatrix
            if (det == 0) {
                submatrices.push_back(submatrix);
            }
        }
    }

    // Open the output file in append mode
    ofstream outputFile(outputFileName, ios_base::app);

    // Check if the output file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the output file." << endl;
        return 1;
    }

    // Write the submatrices with determinant zero to the output file along with their determinants
    for (const auto& submatrix : submatrices) {
        outputFile << "Submatrix with determinant zero:" << endl;
        outputFile << submatrix << endl;

        ZZ det;
        determinant(det, submatrix);
        outputFile << "Determinant: " << det << endl;
        outputFile << "--------------------" << endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Submatrices with determinant zero written to '" << outputFileName << "'." << endl;

    return 0;
}
