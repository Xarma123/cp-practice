#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol d[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    string s;
    cin >> s;
    lol ans = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        priority_queue<lol> x;
        x.push(d[i]);
        lol j = i + 1;
        if (j < n)
        {
            while (s[j] == s[i])
            {
                x.push(d[j]);
                j++;
                if (j == n)
                    break;
            }
        }
        lol c = k;
        while (c-- && !x.empty())
        {
            ans += x.top();
            x.pop();
        }

        i = j - 1;
    }
    cout << ans;

    return 0;
}