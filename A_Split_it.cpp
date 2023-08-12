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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol i = 0, j = n - 1;
        while (j - i >= 2)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                break;
        }
        if (i >= k)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}