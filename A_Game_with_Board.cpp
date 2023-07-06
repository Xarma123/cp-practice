#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        if (n >= 5)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
    }
}