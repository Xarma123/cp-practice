#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol b[n];
        map<lol, vector<lol>> desire;

        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] != b[i])
                desire[b[i]].push_back(i);
        }
        lol c[m];
        map<lol, vector<lol>> paloler;
        for (lol i = 0; i < m; i++)
        {
            cin >> c[i];
            paloler[c[i]].push_back(i);
        }
        map<lol, vector<lol>> right;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                right[a[i]].push_back(i);
            }
        } 
        
    }

    return 0;
}