#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string b(k, '0');
    for (lol i = 0; i < k; i++)
    {
        b[i] = s[i];
    }
    lol p = 0;
    while (b.size() < s.size())
    {
        b += b[p];
        p++;
        p %= k;
    }
    if (b >= s)
    {
        cout << b.size() << "\n";
        cout << b;
    }
    else
    {
        for (lol i = k - 1; i >= 0; i--)
        {
            if (b[i] != '9')
            {
                char c = char(b[i] + 1);
                lol j = i;
                while (j < b.size())
                {
                    b[j] = c;
                    j += k;
                }
                i++;
                for (; i < k; i++)
                {
                    j = i;
                    while (j < b.size())
                    {
                        b[j] = '0';
                        j += k;
                    }
                }

                break;
            }
        }
        if (b >= s)
        {
            cout << b.size() << '\n';
            cout << b;
        }
        else
        {
            cout << s.size() + 1;
            for (lol i = 0; i < s.size() + 1; i++)
            {
                if (i % k == 0)
                    cout << '1';
                else
                    cout << '0';
            }
        }
    }
}