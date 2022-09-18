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
    for (lol i = 0; i < n; i++)
    {
        s.push_back('a');
    }
    s[n - 3] = 'B';
    s[n - 2] = 'I';
    s[n - 1] = 'V';

    string q = "ROYG";
    lol j = 0;
    for (lol i = 0; i < n - 3; i++)
    {
        s[i] = q[j];
        j++;
        j %= 4;
    }

    cout << s << endl;

    return 0;
}