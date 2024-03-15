#include <bits/stdc++.h>
#include<NTL/ZZ.h>

using namespace std;
using namespace NTL;
int main()
{
    ZZ acc, val;
    acc=0;
    while(cin>>val)
    acc += val*val;
    cout<<acc<<"\n";
    return 0;
}