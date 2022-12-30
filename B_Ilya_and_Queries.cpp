#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol c[s.size() + 1];
    c[0] = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        c[i + 1] = c[i];
        if (i > 0 && s[i] == s[i - 1])
            c[i + 1]++;
    }
    lol m;
    cin >> m;
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        cout << c[r] - c[l] << endl;
    }

    return 0;
}