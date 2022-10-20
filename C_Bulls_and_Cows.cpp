#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<pair<string, pair<lol, lol>>> co;
    while (n--)
    {
        string a;
        lol b, c;
        cin >> a >> b >> c;
        co.push_back({a, {b, c}});
    }
    vector<lol> ans;
    for (lol i = 0; i < 10; i++)
    {
        for (lol j = 0; j < 10; j++)
        {
            for (lol k = 0; k < 10; k++)
            {
                for (lol l = 0; l < 10; l++)
                {
                    if (i != j &&
                        i != k &&
                        i != l &&
                        j != k &&
                        j != l &&
                        k != l)
                    {
                        bool check = true;
                        for (auto e : co)
                        {
                            string s = e.first;
                            lol bull = e.second.first;
                            lol cow = e.second.second;
                            lol b1 = 0, c1 = 0;
                            if (s[0] - '0' == i)
                                b1++;
                            else if (s[0] - '0' == j || s[0] - '0' == k || s[0] - '0' == l)
                            {
                                c1++;
                            }
                            if (s[1] - '0' == j)
                                b1++;
                            else if (s[1] - '0' == i || s[1] - '0' == k || s[1] - '0' == l)
                            {
                                c1++;
                            }
                            if (s[2] - '0' == k)
                                b1++;
                            else if (s[2] - '0' == j || s[2] - '0' == i || s[2] - '0' == l)
                            {
                                c1++;
                            }
                            if (s[3] - '0' == l)
                                b1++;
                            else if (s[3] - '0' == j || s[3] - '0' == k || s[3] - '0' == i)
                            {
                                c1++;
                            }
                            if (!(bull == b1 && cow == c1))
                            {
                                check = false;
                                break;
                            }
                        }
                        if (check)
                        {
                            ans.push_back(i);
                            ans.push_back(j);
                            ans.push_back(k);
                            ans.push_back(l);
                        }
                    }
                }
            }
        }
    }
    if (ans.size() == 0)
    {
        cout << "Incorrect data";
    }
    else if (ans.size() == 4)
    {
        for (auto e : ans)
            cout << e;
    }
    else
        cout << "Need more data";

    return 0;
}