#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2)
        {
            cout << -1 << '\n';
            continue;
        }
        lol i = 0, j = n - 1;
        vector<lol> ans;
        while (i < j && ans.size() < 300ll)
        {

            if (s[i] != s[j])
            {
                i++;
                j--;
            }
            else if (s[i] == '0')
            {
                ans.push_back(j + 1);
                s.insert(j + 1, "01");
                j += 2;
            }
            else
            {
                ans.push_back(i);
                s.insert(i, "01");
                j += 2;
            }
        }
        if (ans.size() == 300ll && i < j)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << '\n';
    }

    return 0;
}
