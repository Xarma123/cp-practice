#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        string s;
        string t;
        cin >> s;
        cin >> t;
        bool f = true;
        deque<pair<lol, lol>> qa;
        deque<pair<lol, lol>> qb;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                lol j = i + 1;
                if (j < n)
                {
                    while (s[i] == s[j])
                    {
                        j++;
                        if (j == n)
                            break;
                    }
                }
                qa.push_back({i, j - i});
                i = j - 1;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == 'b')
            {
                lol j = i + 1;
                if (j < n)
                {
                    while (s[i] == s[j])
                    {
                        j++;
                        if (j == n)
                            break;
                    }
                }
                qb.push_back({i, j - i});
                i = j - 1;
            }
        }

        for (lol i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                if (t[i] == 'a')
                {
                    f = false;
                    break;
                }
                else if (t[i] == 'b')
                {
                    if (s[i] == 'a')
                    {
                        lol j = qa.front().second + i;
                        if (j < n)
                        {
                            if (s[j] == 'b')
                            {
                                qb.front().second--;
                                if (qb.front().second == 0)
                                    qb.pop_front();
                                else
                                    qb.front().first++;
                                swap(s[i], s[j]);
                                pair<lol, lol> x = qa.front();
                                x.first = i + 1;
                                qa.pop_front();
                                if (!qa.empty())
                                {
                                    if (qa.front().first == j + 1)
                                    {
                                        qa.front().first = i + 1;
                                        qa.front().second += x.second;
                                    }
                                    else
                                        qa.push_front(x);
                                }
                                else
                                    qa.push_front(x);
                              
                                continue;
                            }
                            else
                            {
                                f = false;
                                break;
                            }
                        }
                        else
                        {
                            f = false;
                            break;
                        }
                    }
                    else
                    {
                        f = false;
                        break;
                    }
                }
                else
                {

                    if (s[i] == 'b')
                    {
                        lol j = qb.front().second + i;

                        if (j < n)
                        {
                            if (s[j] == 'c')
                            {
                                swap(s[i], s[j]);
                                pair<lol, lol> x = qb.front();
                                x.first = i + 1;
                                qb.pop_front();
                                if (!qb.empty())
                                {
                                    if (qb.front().first == j + 1)
                                    {
                                        qb.front().first = i + 1;
                                        qb.front().second += x.second;
                                    }
                                    else
                                        qb.push_front(x);
                                }
                                else
                                    qb.push_front(x);
                              
                                continue;
                            }
                            else
                            {
                                f = false;
                                break;
                            }
                        }
                        else
                        {
                            f = false;
                            break;
                        }
                    }
                    else
                    {
                        f = false;
                        break;
                    }
                }
            }
            if (!qa.empty())
            {
                if (i == qa.front().first)
                {
                    qa.front().second--;
                    if (qa.front().second == 0)
                        qa.pop_front();
                    else
                        qa.front().first++;
                }
            }
            if (!qb.empty())
            {
                if (i == qb.front().first)
                {
                    qb.front().second--;
                    if (qb.front().second == 0)
                        qb.pop_front();
                    else
                        qb.front().first++;
                }
            }
            
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}