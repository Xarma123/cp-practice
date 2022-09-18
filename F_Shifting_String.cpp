#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol minr(string a)
{
    string b = a;
    lol c = 1;
    string q = "";
    q.push_back(b.back());
    b.pop_back();
    b = q + b;

    while (b != a)
    {
        c++;
        q = "";
        q.push_back(b.back());
        b.pop_back();
        b = q + b;
    }
    return c;
}
lol LcmOfArray(vector<lol> &arr, lol idx)
{

    if (idx == arr.size() - 1)
    {
        return arr[idx];
    }
    lol a = arr[idx];
    lol b = LcmOfArray(arr, idx + 1);
    return (a * 1ll * b / __gcd(a, b));
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
        lol n;
        cin >> n;
        string s;
        cin >> s;

        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol p;
            cin >> p;
            mp[i] = p - 1;
        }
        bool visit[n];
        vector<lol> w;
        memset(visit, false, sizeof(visit));
        for (lol i = 0; i < n; i++)
        {
            lol j = i;
            string q = "";
            while (!visit[j])
            {
                q.push_back(s[j]);
                visit[j] = true;
                j = mp[j];
            }
            if (q.size() > 1)
                w.push_back(minr(q));
        }
        if (w.size() == 0)
            cout << 1 << endl;
        else
            cout << LcmOfArray(w, 0) << endl;
    }

    return 0;
}