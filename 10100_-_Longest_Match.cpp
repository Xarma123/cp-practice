#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcs(string a, string b)
{
    lol dp[a.size() + 1][b.size() + 1];
    for (lol i = 0; i <= a.size(); i++)
    {
        for (lol j = 0; j <= b.size(); j++)
        {
            dp[i][j] = 0;
        }
    }
    lol mx = 0;
    lol e = -1;
    for (lol i = 0; i <= a.size(); i++)
    {
        for (lol j = 0; j <= b.size(); j++)
        {
            if (!(i == 0 || j == 0))
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            if (mx < dp[i][j])
            {
                e = i;
            }
            mx = max(mx, dp[i][j]);
        }
    }
    if (e != -1)
    {
        lol c = 0;
        for (lol i = e; i > e - mx; i--)
        {
            if (a[i - 1] != ' ')
            {
                lol j = i - 1;
                while (j > e - mx && a[j - 1] != ' ')
                {
                    j--;
                }
                c++;
                i = j + 1;
            }
            else
            {
                lol j = i - 1;
                while (j > e - mx && a[j - 1] == ' ')
                {
                    j--;
                }
                i = j + 1;
            }
        }
        return c;
    }

    return mx;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;

    lol c = 1;
    while (getline(cin, a))
    {
        getline(cin, b);
        cout << c << ". ";
        for (lol i = 0; i < a.size(); i++)
        {
            if (!((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'B') || isdigit(a[i])))
                a[i] = ' ';
        }
        for (lol i = 0; i < b.size(); i++)
        {
            if (!((b[i] >= 'a' && b[i] <= 'z') || (b[i] >= 'A' && b[i] <= 'B') || isdigit(b[i])))
                b[i] = ' ';
        }
        if (a == "" || b == "")
            cout << "Blank!" << endl;
        else
        {
            lol q = -1;
            while (q + 1 < a.size() && a[q + 1] == ' ')
                q++;
            lol q2 = -1;
            while (q2 + 1 < b.size() && b[q2 + 1] == ' ')
                q2++;

            if (q == a.size() - 1 || q2 == b.size() - 1)
            {
                cout << "Blank!" << endl;
            }
            else
            {
                cout << "Length of longest match: " << lcs(a, b) << endl;
            }
        }
        c++;
    }

    return 0;
}