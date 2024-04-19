#include<NTL/ZZ.h>
#include<NTL/mat_ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h> // For determinant calculation
#include <fstream>
#include <iostream>

using namespace std;
using namespace NTL;

int main() {
    // Define the input and output file names
    string inputFileName = "Input.txt";
    string outputFileName = "Output.txt";

    // Open the input file
    ifstream InputFile(inputFileName);

    // Check if the input file is opened successfully
    if (!InputFile.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }
    // Open the output file in append mode
    ofstream OutputFile(outputFileName, ios_base::app);

    // Check if the output file is opened successfully
    if (!OutputFile.is_open()) {
        cerr << "Error: Unable to open the output file." << endl;
        return 1;
    }


    // Read the matrix from the input file
    Mat<ZZ> matrix;
    matrix.SetDims(3,3);
    InputFile >> matrix;
    OutputFile<<matrix;

    

    // Calculate the determinant of the matrix
    ZZ det=determinant(matrix);
    
   

    // Print the determinant to the output file
    OutputFile << "Determinant: " << det << endl;

    

    cout << "Determinant calculated and appended to '" << outputFileName << "'." << endl;
    // Close the input file
    InputFile.close();
    // Close the output file
    OutputFile.close();
    return 0;
}