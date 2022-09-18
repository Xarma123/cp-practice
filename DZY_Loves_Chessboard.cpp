#include <bits/stdc++.h>
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string b = "WB";
    lol x = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] == '-')
                cout << a[i][j];
            else
            {
                cout << b[x];
            }
            x = 1 - x;
        }
        cout << endl;
        if(m%2==0)
        x=1-x;
    }
}