#include <bits/stdc++.h>
#define lol unsigned long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        if (a < b)
            swap(a, b);
        if ((a % b == 0) || a / b > 1)
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }

    return 0;
}