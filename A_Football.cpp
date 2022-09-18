#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    string s1 = "", s2 = "";
    lol s[2];
    s[0] = s[1] = 0;
    while (t--)
    {
        string q;
        cin >> q;

        if (s1 == "")
            s1 = q;
        else if (q != s1 && s2 == "")
            s2 = q;

        if (q == s1)
            s[0]++;
        else
            s[1]++;
    }
    if (s[0] > s[1])
        cout << s1;
    else
        cout << s2;

    return 0;
}