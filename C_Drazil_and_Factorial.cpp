#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol f[10];
    memset(f, 0, sizeof(f));
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '4')
        {
            f[3]++;
            f[2] += 2;
        }
        else if (s[i] == '6')
        {
            f[5]++;
            f[3]++;
        }
        else if (s[i] == '8')
        {
            f[7]++;
            f[2] += 3;
        }
        else if (s[i] == '9')
        {
            f[7]++;
            f[3] += 2;
            f[2]++;
        }
        else
            f[s[i] - '0']++;
    }
    for (lol i = 9; i >= 2; i--)
    {
        while (f[i]--)
        {
            cout << i;
        }
    }

    return 0;
}