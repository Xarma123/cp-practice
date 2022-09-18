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
    string a1 = "";
    for (lol i = 0; i < s.size(); i++)
    {
        a1.push_back('0');
    }
    lol i = a1.size() - 1;
    a1[i] = '1';
    lol ans = 0;
    while (s > a1)
    {
        ans++;
        a1[i] = '0';
        i -= 2;
        if (i < 0)
            break;
        a1[i] = '1';
    }
    cout << ans;

    return 0;
}