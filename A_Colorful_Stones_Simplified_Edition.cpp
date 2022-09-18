#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    lol i = 0;
    lol j = 0;
    while (j < t.size())
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    cout << i + 1;

    return 0;
}