#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    lol n;
    cin >> n;

    cout << 3 << ".";
    for (lol i = 0; i < n; i++)
    {
        cout << s[i];
    }
}