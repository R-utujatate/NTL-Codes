#include <NTL/ZZ.h>
#include <NTL/vector.h>
#include <iostream>

using namespace std;
using namespace NTL;

ZZ sum(const Vec<ZZ>& v)
{
    ZZ acc;
    acc = 0;
    for (long i = 0; i < v.length(); i++)
        acc += v[i];
    return acc;
}

int main()
{
    Vec<ZZ> v;

    // Read input into the vector
    long int length;
    cout << "Enter the number of elements in the vector: ";
    cin >> length;

    v.SetLength(length);
    cout << "Enter the elements of the vector: ";
    for (long int i = 0; i < length; i++)
        cin >> v[i];

    // Calculate the sum
    ZZ result = sum(v);

    // Output the sum
    cout << "Sum: " << result << endl;

    return 0;
}
