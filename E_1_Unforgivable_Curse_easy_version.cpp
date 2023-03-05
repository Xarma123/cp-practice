#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        bool f = true;
        map<char, lol> f1, f2;
        for (lol i = 0; i < n; i++)
        {
            f1[s[i]]++;
            f2[t[i]]++;
        }
        for (char i = 'a'; i <= 'z'; i++)
            if (f1[i] != f2[i])
                f = false;

        for (lol i = 0; i < min(n, k); i++)
        {
            if (n - 1 - i < k)
            {
                if (s[i] != t[i])
                {

                    f = false;
                }
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}