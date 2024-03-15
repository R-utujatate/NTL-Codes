#include<NTL/ZZ.h>
#include<NTL/matrix.h>
#include <bits/stdc++.h>

using namespace std;
using namespace NTL;
void mul(Mat<ZZ>& x,Mat<ZZ>& A, Mat<ZZ>& B)
{
    long n=A.NumRows();
    long l=A.NumCols();
    long m=B.NumCols();

    if(l != B.NumRows())
     Error("matrix multiplication:dimension mismatch");
     // make X have n rows and m columns
     x.SetDims(n,m);

     long i,j,k;
     ZZ acc,tmp;

     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            acc=0;
            for(k=0;k<l;k++){
                mul(tmp,A[i][k],B[k][j]);
                add(acc,acc,tmp);
            }
            x[i][j]=acc;
        }
     }
}
int main() {
    Mat<ZZ> x, A, B;

    // Input for matrix A
    cout << "Enter the number of rows and columns for matrix A: ";
    long rows_A, cols_A;
    cin >> rows_A >> cols_A;

    A.SetDims(rows_A, cols_A);

    cout << "Enter the elements of matrix A:" << endl;
    for (long i = 0; i < rows_A; i++) {
        for (long j = 0; j < cols_A; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Input for matrix B
    cout << "Enter the number of rows and columns for matrix B: ";
    long rows_B, cols_B;
    cin >> rows_B >> cols_B;

    B.SetDims(rows_B, cols_B);

    cout << "Enter the elements of matrix B:" << endl;
    for (long i = 0; i < rows_B; i++) {
        for (long j = 0; j < cols_B; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    mul(x, A, B);

    // Print the result matrix x
    cout << "Result matrix x:" << endl;
    for (long i = 0; i < x.NumRows(); i++) {
        for (long j = 0; j < x.NumCols(); j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}