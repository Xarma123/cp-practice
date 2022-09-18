#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b; 
        cout<<(a^(a&b))+(b^(a&b))<<endl;
    }

    return 0;
}