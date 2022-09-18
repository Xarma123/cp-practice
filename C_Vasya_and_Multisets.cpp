#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    vector<lol> s1;
    vector<lol> t3;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);

    for (lol i = 0; i < n; i++)
    {

        lol j = i + 1;
        if (j < n)
        {
            while (a[j].first == a[i].first)
            {
                j++;
                if (j == n)
                    break;
            }
        }

        if (j - i >= 3)
            t3.push_back(a[i].second);
        else if (j - i == 1)
            s1.push_back(a[i].second);
        i = j - 1;
    }

    bool t3t = false;
    if (s1.size() % 2 != 0)
        t3t = true;
    if (t3t && t3.size() == 0)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        char ans[n];
        memset(ans, 'A', sizeof(ans));
        for (lol i = 1; i < s1.size(); i += 2)
        {
            ans[s1[i]] = 'B';
        }
        if (t3t)
        {
            ans[t3[0]] = 'B';
        }

        for (lol i = 0; i < n; i++)
        {
            cout << ans[i];
        }
    }

    return 0;
}