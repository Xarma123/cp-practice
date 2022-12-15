#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;

    lol tot = 0;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            lol j = i + 1;
            while (j < n && s[j] == s[i])
                j++;
            tot += (j - i) / b;
            i = j - 1;
        }
    }

    cout << tot - a + 1 << endl;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            lol j = i + 1;
            while (j < n && s[j] == s[i])
                j++;
            lol p = (j - 1 - (j - i) % b);
            lol c = (j - i) / b;
            while (c-- && tot >= a)
            {
                cout << p + 1 << " ";
                tot--;
                p -= b;
            }
            i = j - 1;
        }
    }

    return 0;
}