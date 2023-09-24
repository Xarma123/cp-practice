#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        lol k;
        cin >> k;
       
        if (a > b)
            swap(a, b);
        if (k > b - 1)
            cout << "OBEY\n";
        else if (k == b - 1)
        {
            if (a == 1)
                cout << "REBEL\n";
            else
                cout << "OBEY\n";
        }
        else if (       )
            cout << "REBEL\n";
        else
            cout << "OBEY\n";
    }
}