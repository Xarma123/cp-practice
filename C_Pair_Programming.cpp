#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol k, n, m;
        cin >> k >> n >> m;
        lol a[n], b[m];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        lol i = 0, j = 0;
        bool ans = true;
        vector<lol> q;
        while (i < n && j < m)
        {

            if (a[i] == 0)
            {
                q.push_back(a[i]);
                k++;
                i++;
            }
            else if (b[j] == 0)
            {
                q.push_back(b[j]);
                k++;
                j++;
            }
            else if (a[i] <= k)
            {
                q.push_back(a[i]);
                i++;
            }
            else if (b[j] <= k)
            {
                q.push_back(b[j]);
                j++;
            }
            else
            {
                ans = false;
                break;
            }
        }
        if (!ans)
            cout << -1 << endl;
        else
        {
            while (i < n)
            {

                if (a[i] == 0)
                {
                    q.push_back(a[i]);
                    k++;
                    i++;
                }
                else if (a[i] <= k)
                {
                    q.push_back(a[i]);
                    i++;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            while (j < m)
            {
                if (b[j] == 0)
                {
                    q.push_back(b[j]);
                    k++;
                    j++;
                }
                else if (b[j] <= k)
                {
                    q.push_back(b[j]);
                    j++;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
            {
                for (lol f = 0; f < q.size(); f++)
                {
                    cout << q[f] << " ";
                }
                cout << endl;
            }
            else
                cout << -1 << endl;
        }
    }

    return 0;
}