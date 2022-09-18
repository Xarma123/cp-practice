#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<lol> in;
    set<lol> entered;
    vector<lol> ans;
    lol last = 0;
    lol i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (entered.count(a[i]))
            {
                if (in.size() == 0)
                {
                    ans.push_back(i - last);
                    entered.clear();
                    last = i;
                    entered.insert(a[i]);
                    in.insert(a[i]);
                }
                else
                {
                    break;
                }
            }
            else
            {
                entered.insert(a[i]);
                in.insert(a[i]);
            }
        }
        else
        {
            if (in.count((-a[i])))
            {
                in.erase((-a[i]));
                if (in.size() == 0)
                {
                    ans.push_back(i - last + 1);
                    last = i + 1;
                    entered.clear();
                }
            }
            else
            {
                break;
            }
        }
    }
    if (i < n || in.size() != 0)
    {
        cout << -1;
    }
    else
    {   if(last!=n)
        ans.push_back(n - last);
        cout << ans.size() << endl;
        for (lol i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}