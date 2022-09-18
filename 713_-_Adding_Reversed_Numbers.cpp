#include <bits/stdc++.h>
#define lol long long
using namespace std;
string add(string a, string b)
{
    lol i = 0, j = 0;
    lol cary = 0;
    string ans = "";
    while (i < a.size() || j < b.size() || cary > 0)
    {
        lol v = cary;
        if (i < a.size())
        {
            v += a[i] - '0';
            i++;
        }
        if (j < b.size())
        {
            v += b[j] - '0';
            j++;
        }
        ans.push_back(char(v % 10 + '0'));
        cary = v / 10;
    }
    i = 0;
    while (i < ans.size() - 1 && ans[i] == '0')
        i++;

    return ans.substr(i);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        cout << add(a, b) << endl;
    }

    return 0;
}