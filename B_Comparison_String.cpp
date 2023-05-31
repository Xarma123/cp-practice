#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol up = 0;
        lol down = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && s[j] == s[j - 1])
                j++;
            if (s[i] == '<')
                up = max(up, j - i);
            else
                down = max(down, j - i);
            i = j - 1;
        }
        cout << max(up, down) + 1 << "\n";
    }
}