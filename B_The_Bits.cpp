#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    lol c[4];
    c[0] = c[1] = c[2] = c[3] = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == '0' && b[i] == '0')
            c[0]++;
        if (a[i] == '0' && b[i] == '1')
            c[1]++;
        if (a[i] == '1' && b[i] == '0')
            c[2]++;
        if (a[i] == '1' && b[i] == '1')
            c[3]++;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == '0' && b[i] == '0')
        {
            ans += c[2] + c[3];
        }
        else if (a[i] == '0' && b[i] == '1')
        {
            ans += c[2];
        }
        else if (a[i] == '1' && b[i] == '0')
        {
            ans += c[0] + c[1];
        }
        else
        {
            ans += c[0];
        }
    }
    cout << ans / 2;
}