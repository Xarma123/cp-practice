#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<lol> a(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol t;
    cin >> t;
    vector<pair<lol, lol>> v;
    v.push_back({0, n - 1});
    lol ans = 0;
    bool q1 = false, q2 = false;
    for (lol b = 30; b >= 0; b--)
    {
        if (q1)
        {
            vector<pair<lol, lol>> nv;
            for (auto e : v)
            {
                lol l = -1;
                for (lol i = e.first; i <= e.second; i++)
                {
                    if ((a[i] & (1ll << b)) == 0)
                    {
                        if (l != -1)
                        {
                            nv.push_back({l, i - 1});
                            l = -1;
                        }
                    }
                    else
                    {
                        if (l == -1)
                            l = i;
                    }
                }
                if (l != -1)
                {
                    nv.push_back({l, e.second});
                }
            }
            vector<pair<lol, lol>> nvv;
            for (auto e : nv)
            {
                lol val = a[e.first];
                for (lol i = e.first + 1; i <= e.second; i++)
                {
                    val &= a[i];
                }
                val &= (~((1ll << (b + 1)) - 1));
                if (val == ans)
                {
                    nvv.push_back(e);
                }
            }
            if (nvv.size())
            {
                v = nvv;
                ans |= (1ll << b);
            }
            else
            {
                q1 = true;
            }
        }
        else if (q2)
        {
            vector<pair<lol, lol>> nv;
            for (auto e : v)
            {
                lol val = a[e.first];
                for (lol i = e.first + 1; i <= e.second; i++)
                {
                    val &= a[i];
                }
                if ((val & (1ll << b)) == 0)
                {
                    nv.push_back(e);
                }
            }
            if (nv.size())
            {
                v = nv;
            }
            else
            {
                ans |= (1ll << b);
                q2 = true;
            }
        }
        else if ((t & (1ll << b)))
        {
            
            vector<pair<lol, lol>> nv;
            for (auto e : v)
            {
                lol l = -1;
                for (lol i = e.first; i <= e.second; i++)
                {
                    if ((a[i] & (1ll << b)) == 0)
                    {
                        if (l != -1)
                        {
                            nv.push_back({l, i - 1});
                            l = -1;
                        }
                    }
                    else
                    {
                        if (l == -1)
                            l = i;
                    }
                }
                if (l != -1)
                {
                    nv.push_back({l, e.second});
                }
            }
            vector<pair<lol, lol>> nvv;
            for (auto e : nv)
            {
                lol val = a[e.first];
                for (lol i = e.first + 1; i <= e.second; i++)
                {
                    val &= a[i];
                }
                val &= (~((1ll << (b + 1)) - 1));
                if (val == ans)
                {
                    nvv.push_back(e);
                }
            }
            if (nvv.size())
            {
                v = nvv;
                ans |= (1ll << b);
            }
            else
            {
                q1 = true;
            }
        }
        else
        {
            vector<pair<lol, lol>> nv;
            for (auto e : v)
            {
                lol val = a[e.first];
                for (lol i = e.first + 1; i <= e.second; i++)
                {
                    val &= a[i];
                }
                if ((val & (1ll << b)) == 0)
                {
                    nv.push_back(e);
                }
            }
            if (nv.size())
            {
                v = nv;
            }
            else
            {
                ans |= (1ll << b);
                q2 = true;
            }
        }
    }
    cout << (long long)abs(ans-t);

    return 0;
}
