#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string x = a[0];
    for (lol i = 1; i < n; i++)
    {
        string b = "";
        for (lol j = (long long)x.size() - 1; j >= 0 && j >= (long long)x.size() - (long long)a[i].size(); j--)
        {
            b += x[j];
        }
        reverse(b.begin(), b.end());
        b = a[i] + "$" + b;
        lol lps[b.size()];
        lps[0] = 0;
        lol j = 1;
        lol l = 0;
        // lps array ?
        while (j < b.size())
        {
            if (b[j] == b[l])
            {
                lps[j] = l + 1;
                l++;
                j++;
            }
            else if (l)
            {
                l = lps[l - 1];
            }
            else
            {
                l = 0;
                lps[j] = l;
                j++;
            }
        }
        lol mx = lps[b.size() - 1];
        if (mx < a[i].size())
        {
            b = a[i].substr(mx);
            for (j = 0; j < b.size(); j++)
            {
                x += b[j];
            }
        }
    }
    cout << x;
}