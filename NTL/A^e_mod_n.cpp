#include <NTL/ZZ.h>
#include <iostream>

using namespace NTL;
using namespace std;

ZZ MyPowerMod(const ZZ& a, const ZZ& e, const ZZ& n) {
    if (n == ZZ(0)) {
        cerr << "Error: Modulus 'n' cannot be zero." << endl;
        exit(1);
    }

    if (e == ZZ(0)) return ZZ(1);
    long k = NumBits(e);
    ZZ res = ZZ(1);
    ZZ base = a % n; // Calculate a mod n to reduce the base within the range [0, n-1]

    for (long i = k - 1; i >= 0; i--) {
        res = (res * res) % n;
        if (bit(e, i) == 1) res = (res * base) % n;
    }

    if (e < ZZ(0)) return InvMod(res, n);
    else return res;
}

int main() {
    ZZ a, e, n;

    // Input values for a, e, and n
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of e: ";
    cin >> e;
    cout << "Enter the value of n: ";
    cin >> n;

    // Call MyPowerMod function
    ZZ Result = MyPowerMod(a, e, n);

    // Output the result
    cout << "Result: " << Result << endl;

    return 0;
}
