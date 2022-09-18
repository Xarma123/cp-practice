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
        string a;
        cin >> a;
        lol ans[n];
        stack<lol> one, zero;
        lol c = 1;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == '0')
            {
                if (!one.empty())
                {
                    lol id = one.top();
                    one.pop();
                    ans[i] = id;
                    zero.push(id);
                }
                else
                {
                    zero.push(c);
                    ans[i] = c;
                    c++;
                }
            }
            else
            {
                if (!zero.empty())
                {
                    lol id = zero.top();
                    zero.pop();
                    ans[i] = id;
                    one.push(id);
                }
                else
                {
                    one.push(c);
                    ans[i] = c;
                    c++;
                }
            }
        }
        cout << one.size() + zero.size() << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}