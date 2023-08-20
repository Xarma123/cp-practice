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
        string s;
        cin >> s;
        lol n;
        cin >> n;
        lol b[n];
        vector<lol> z;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] == 0)
                z.push_back(i);
        }
        string a(n, 'A');
        sort(s.begin(), s.end());
        lol j = s.size() - 1;
        while (z.size() > 0)
        {

            lol i = j - 1;
            while (i >= 0 && s[i] == s[j])
                i--;
            if (j - i >= z.size())
            {
                while (z.size())
                {
                    lol e = z.back();
                    b[e] = -1;
                    a[e] = s[j];
                    for (lol k = 0; k < n; k++)
                    {
                        b[k] -= abs(k - e);
                    }
                    z.pop_back();
                }

                for (lol k = 0; k < n; k++)
                {
                   
                    if (b[k] == 0)
                        z.push_back(k);
                }
              
            }
            j = i;
        }
        cout << a << '\n';
    }
}