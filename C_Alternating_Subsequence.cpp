a#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        vector<lol> ans;
        while (n--)
        {
            lol a;
            cin >> a;
            if (ans.size() == 0)
                ans.push_back(a);
            else if (ans.back() > 0 && a > 0)
            {
                if (ans.back() < a)
                {
                    ans.pop_back();
                    ans.push_back(a);
                }
            }
            else if (ans.back() < 0 && a < 0)
            {
                if (ans.back() < a)
                {
                    ans.pop_back();
                    ans.push_back(a);
                }
            }
            else
                ans.push_back(a);
        }
        lol s = 0;
        for (lol i = 0; i < ans.size(); i++)
        {
            s += ans[i];
        }
        cout << s << endl;
    }

    return 0;
}