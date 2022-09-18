#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n; 
        
        cout << (long long)powl(2, n) - 1 << endl;
    }

    return 0;
}