#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        map<char, lol> mpa;
        for (lol i = 0; i < n; i++)
        {
            mpa[a[i]]++;
        }

        string b;
        cin >> b;
        map<char, lol> mpb;
        for (lol i = 0; i < n; i++)
        {
            mpb[b[i]]++;
        }
        bool f = true;
        map<char, lol> extra;
        map<char, lol> need;

        for (auto i = mpa.begin(); i != mpa.end(); i++)
        {
            auto it = mpb.find((*i).first);
            if (it == mpb.end())
            {
                if ((*i).second % k != 0)
                {
                    f = false;
                    break;
                }
                else
                {
                    extra[(*i).first] += (*i).second / k;
                }
            }
            else
            {
                if ((*i).second == (*it).second)
                {
                }
                else if ((*i).second < (*it).second)
                {
                    if (((*it).second - (*i).second) % k != 0)
                    {
                        f = false;
                        break;
                    }
                    else
                    {
                        need[(*it).first] += ((*it).second - (*i).second) / k;
                    }
                }
                else
                {
                    if ((-(*it).second + (*i).second) % k != 0)
                    {
                        f = false;
                        break;
                    }
                    else
                    {
                        extra[(*i).first] += (-(*it).second + (*i).second) / k;
                    }
                }
            }
        }
        for (auto i = mpb.begin(); i != mpb.end(); i++)
        {
            if (mpa.find((*i).first) == mpa.end())
            {
                if ((*i).second % k != 0)
                {
                    f = false;
                    break;
                }
                else
                {
                    need[(*i).first] += (*i).second / k;
                }
            }
        }

        if (!f)
        {
            cout << "No" << endl;
        }
        else
        {

            for (auto i = extra.rbegin(); i != extra.rend(); i++)
            {
                while ((*i).second != 0)
                {
                    char h = (*i).first;
                    auto u = need.lower_bound(h);
                    if (u == need.end())
                    {
                        f = false;
                        break;
                    }
                    else
                    {
                        lol d = (*u).second;
                        if ((*i).second <= d)
                        {
                            d = d - (*i).second;
                            (*i).second = 0;
                            (*u).second = d;
                            if (d == 0)
                                need.erase(u);
                        }
                        else
                        {
                            (*i).second = (*i).second - d;
                            need.erase(u);
                        }
                    }
                }
            }

            if (f && need.size() == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}