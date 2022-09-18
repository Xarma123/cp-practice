#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "white" << endl;
        cout << 1 << " " << 2;
    }
    else
        cout << "black" << endl;
    return 0;
}