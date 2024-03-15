#include <NTL/mat_ZZ.h>
#include <fstream>
#include <iostream>

using namespace std;
using namespace NTL;

int main() {
    // Define the input and output file names
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    // Open the input file
    ifstream inputFile(inputFileName);

    // Check if the input file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile(outputFileName);

    // Check if the output file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the output file." << endl;
        inputFile.close();
        return 1;
    }

    // Read input from the input file and write to the output file
    string line;
    while (getline(inputFile, line)) {
        // Write the line read from the input file to the output file
        outputFile << line << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Input from '" << inputFileName << "' copied to '" << outputFileName << "'." << endl;

    return 0;
}
