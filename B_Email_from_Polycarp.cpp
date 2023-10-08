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
        string a, b;
        cin >> a >> b;
        queue<pair<char, lol>> v;
        for (lol i = 0; i < b.size(); i++)
        {
            lol j = i + 1;
            while (j < b.size() && b[i] == b[j])
                j++;
            v.push({b[i], j - i});
            i = j - 1;
        }
        bool ans = true;
        for (lol i = 0; i < a.size(); i++)
        {
            lol j = i + 1;
            while (j < a.size() && a[i] == a[j])
                j++;
            if (v.size() == 0)
            {
                ans = false;
                break;
            }
            pair<char, lol> c = v.front();

            v.pop();
            if (!(c.first == a[i] && c.second >= (j - i)))
            {

                ans = false;
                break;
            }
            i = j - 1;
        }
        if (v.size() != 0)
            ans = false;
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}