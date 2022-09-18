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
    sort(s.begin(), s.end());
    lol i = 0;
    while (s[i] == '+')
        i++;
    string n;
    while (i < s.size())
    {
        n.push_back(s[i]);

        if (i != s.size() - 1)
            n.push_back('+');
        i++;
    }

    cout << n;

    return 0;
}