#include <bits/stdc++.h>
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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<lol> ans;
        lol j = n - 1;
        while (j >= 0)
        {
            lol i;
            for (i = 0; i <= j; i++)
            {
                if (a[i] == j + 1)
                    break;
            }
            if (i != j)
            {
                ans.push(i + 1);
            }
            else
                ans.push(0);
            vector<lol> x;
            for (lol k = i + 1; k <= j; k++)
            {
                x.push_back(a[k]);
            }
            for (lol k = 0; k <= i; k++)
            {
                x.push_back(a[k]);
            }
            for (i = 0; i <= j; i++)
            {
                a[i] = x[i];
            }
            x.clear();
            j--;
        }
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }

    return 0;
}