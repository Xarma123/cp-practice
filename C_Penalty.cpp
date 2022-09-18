#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        lol score1 = 0, score2 = 0;
        lol ans;
        for (lol i = 0; i < a.size(); i++)
        {
            lol d;
            if (i % 2 == 0)
            {
                if (a[i] == '1')
                    score1++;

                if (score1 >= score2)
                {
                    d = score1 - score2;
                    if (d > 5 - (i / 2))
                    {
                        ans = i;
                        break;
                    }
                }
                else
                {
                    d = score2 - score1;
                    if (d > 4 - i / 2)
                    {
                        ans = i;
                        break;
                    }
                }
            }
            else
            {
                if (a[i] == '1' || a[i] == '?')
                    score2++;

                if (score2 >= score1)
                {
                    d = score2 - score1;
                    if (d > 4 - i / 2)
                    {
                        ans = i;
                        break;
                    }
                }
                else
                {
                    d = score1 - score2;
                    if (d > 4 - i / 2)
                    {
                        ans = i;
                        break;
                    }
                }
            }
            if (i == 9 && d == 0)
            {
                ans = 9;
                break;
            }
        }

        score1 = 0;
        score2 = 0;
        lol ans2;
        for (lol i = 0; i < a.size(); i++)
        {
            lol d;
            if (i % 2 == 0)
            {
                if (a[i] == '1' || a[i] == '?')
                    score1++;

                if (score1 >= score2)
                {
                    d = score1 - score2;
                    if (d > 5 - (i / 2))
                    {
                        ans2 = i;
                        break;
                    }
                }
                else
                {
                    d = score2 - score1;
                    if (d > 4 - i / 2)
                    {
                        ans2 = i;
                        break;
                    }
                }
            }
            else
            {
                if (a[i] == '1')
                    score2++;

                if (score2 >= score1)
                {
                    d = score2 - score1;
                    if (d > 4 - i / 2)
                    {
                        ans2 = i;
                        break;
                    }
                }
                else
                {
                    d = score1 - score2;
                    if (d > 4 - i / 2)
                    {
                        ans2 = i;
                        break;
                    }
                }
            }
            if (i == 9 && d == 0)
            {
                ans2 = 9;
                break;
            }
        }

        cout << min(ans, ans2) + 1 << endl;
    }

    return 0;
}