#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    string a;
    cin >> a;

    lol n = a.size();
    cout << 3 << endl;
    cout << "L " << 2 << endl;
    cout << "R " << 2 << endl;
    cout << "R " << 2 * n - 1 << endl;

    return 0;
}