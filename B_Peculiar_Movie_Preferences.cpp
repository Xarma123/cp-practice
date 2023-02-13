#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(string a)
{
    lol i = 0, j = a.size() - 1;
    while (i < j)
    {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<string> x, y, z;
        bool ans = false;
        for (lol i = 0; i < n&&!ans; i++)
        {
            if (a[i].size() == 1)
            {
                ans = true;
                break;
            }
            else if (a[i].size() == 2)
            {
                string s = a[i];
                reverse(s.begin(), s.end());
                if (x.count(s) || z.count(s))
                    ans = true;
            }
            else
            {
                string s = a[i];
                reverse(s.begin(), s.end());
                if (y.count(s))
                    ans = true;
                s.pop_back();
                if (x.count(s))
                    ans = true;
            }

            ans |= check(a[i]);
            if (a[i].size() == 2)
                x.insert(a[i]);
            else if (a[i].size() == 3)
            {
                y.insert(a[i]);
                z.insert(a[i].substr(0, 2));
            }
        }
        if (ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}