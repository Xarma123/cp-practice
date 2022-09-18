#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(string s, lol sco)
{
    if (sco == -1)
        return false;
    if (sco == 0)
    {
        lol i = 0;
        while (s[i] == '0')
        {
            i++;
            if (i == s.size())
                return true;
        }
        lol j = s.size() - 1;
        while (s[j] == '0')
        {
            j--;
        }

        while (i <= j)
        {
            if (s[i] == '0')
                return false;
            i++;
        }
        return true;
    }
    lol o = 0;
    deque<lol> points;
    points.push_back(0);
    lol z = 0;
    lol c[s.size() + 1];
    c[0] = 0;
    for (lol i = 1; i <= s.size(); i++)
    {
        c[i] = c[i - 1];
        if (s[i - 1] == '1')
            c[i]++;
    }

    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            z++;
            points.push_back(i);
            if (points.size() == sco + 1)
            {
                lol j = i + 1;
                if (j < s.size())
                {
                    while (s[j] == '1')
                    {
                        j++;
                        if (j == s.size())
                            break;
                    }
                }
                points.push_back(j - 1);
                i = j - 1;
                if (c[points[0]] + c[s.size()] - c[points[sco + 1] + 1] <= sco)
                    return true;
                points.pop_front();
                points[0]++;
                points.pop_back();
            }
        }
        else
            o++;
    }

    if (z <= sco && o >= sco)
    {
        return true;
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol z = 0, o = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                z++;
            else
                o++;
        }
        lol st = -1;
        lol e = max(z, o);

        while (st != e - 1)
        {
            lol m = (st + e) / 2;
            bool f = check(s, m);

            if (check(s, m) == true)
                e = m;
            else
                st = m;
        }
        cout << e << endl;
    }

    return 0;
}