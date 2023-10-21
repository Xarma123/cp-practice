#include <bits/stdc++.h>
#define lol long long
using namespace std;
//
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b, c;
    cin >> a >> b >> c;
    lol f[26];
    memset(f, 0, sizeof(f));
    for (auto e : a)
        f[e - 'A']++;
    for (auto e : b)
        f[e - 'A']++;
    for (auto e : c)
        f[e - 'A']--;
    lol i;
    for (i = 0; i < 26; i++)
        if (f[i] != 0)
            break;
    if (i == 26)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}