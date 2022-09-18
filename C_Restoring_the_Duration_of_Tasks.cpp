#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        deque<lol> q;
        lol n;
        cin >> n;
        lol s[n];
        lol f[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> f[i];
        }
        lol st = 0;
        vector<lol> d(n, 0);
        while (st < n)
        {
            if (q.empty())
            {
                q.push_back(st);
                d[st] = f[st] - s[st];
              
            }
            else
            {
                if (f[q.back()] <= s[st])
                {

                    q.push_back(st);
                    d[st] = f[st] - s[st];
                   
                }
                else
                {
                    d[st] = f[st] - f[q.back()];

                    q.push_back(st);
                    
                }
            } 
            st++;
            
        }
        for (lol i = 0; i < n; i++)
        {
            cout << d[i] << " ";
        }
        cout << endl;
    }

    return 0;
}