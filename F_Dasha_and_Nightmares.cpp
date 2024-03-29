#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
#define int long long
#define sz(s) (int)s.size()
#define all(v) (v).begin(), (v).end()

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p)
{
    cin >> p.first;
    return cin >> p.second;
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ", ";
        cout << v[i];
    }
    return cout << "]";
}
template <typename A>
istream &operator>>(istream &cin, vector<A> &x)
{
    for (int i = 0; i < x.size() - 1; i++)
        cin >> x[i];
    return cin >> x[x.size() - 1];
}
template <typename A, typename B>
A amax(A &a, B b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename A, typename B>
A amin(A &a, B b)
{
    if (b < a)
        a = b;
    return a;
}

const long long mod = 1e9 + 7;
const long long inf = 1e18;

void solve()
{
    int n;
    cin >> n;

    int ans = 0;

    map<tuple<int, int>, int> mp;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int l = sz(s);

        vector<int> cnt(26);
        for (auto u : s)
            cnt[u - 'a']++;

        int mask = 0;
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] & 1)
                mask = mask | (1 << j);
        }

        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] == 0)
                mp[{mask, j}]++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] > 0)
                continue;
            int nw = 1 << 26;
            nw--;

            nw ^= mask;

            nw ^= (1 << j);

            ans += mp[{nw, j}];
        }
    }

    cout << ans << enl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int testcases = 1;
    // cin>>testcases;
    while (testcases--)
        solve();
    return 0;
}