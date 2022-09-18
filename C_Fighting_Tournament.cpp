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
    while (t--)
    {
        lol n, q;
        cin >> n >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<lol> x;
        x.push(-1);
        vector<lol> nex(n), prev(n);
        for (lol i = 0; i < n; i++)
        {
            while (x.top() != -1 && a[x.top()] < a[i])
            {
                nex[x.top()] = i;
                x.pop();
            }
            prev[i] = x.top();
            x.push(i);
        }
        while (x.size() && x.top() != -1)
        {
            nex[x.top()] = n;
            x.pop();
        }
        while (q--)
        {
            lol i, k;
            cin >> i >> k;
            i--;
            if (a[i] == n)
            {
                if (i <= 1)
                {
                    cout << k << endl;
                }
                else
                {
                    cout << max(k - (i - 1), 0ll) << endl;
                }
            }
            else
            {
                if (prev[i] != -1)
                {
                    cout << 0 << endl;
                }
                else
                {
                    if (i == 0)
                    {
                        cout << min(nex[i] - i - 1, k) << endl;
                    }
                    else if (i == 1)
                    {
                        k--;
                        if (k == 0)
                            cout << 1 << endl;
                        else
                        {
                            cout << min(nex[i] - i - 1, k) + 1 << endl;
                        }
                    }
                    else
                    {
                        k -= i - 1;
                        if (k <= 0)
                            cout << 0 << endl;
                        else
                        {
                            k--;
                            if (k == 0)
                                cout << 1 << endl;
                            else
                            {
                                cout << min(nex[i] - i - 1, k) + 1 << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}