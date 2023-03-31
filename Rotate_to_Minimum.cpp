#include <bits/stdc++.h>
#define lol long long
using namespace std;
typedef std::tuple<int, char, char> key_t;

struct key_hash : public std::unary_function<key_t, std::size_t>
{
    std::size_t operator()(const key_t &k) const
    {
        return std::get<0>(k) ^ std::get<1>(k) ^ std::get<2>(k);
    }
};
unordered_map<tuple<lol, lol, lol>, string> mp;
string solve(string s, lol i, lol p, lol q)
{
    if (i == s.size())
        return "";
    if (mp.find(make_tuple(i, p, q)) == mp.end())
        return mp[make_tuple(i, p, q)];
    string r = "";
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (q >= s[i] - c && p >= 26 - (s[i] - c))
        {
            r += c;
            string a1 = solve(s, i + 1, p, q - (s[i] - c));
            string a2 = solve(s, i + 1, p - (26 - (s[i] - c)), q);
            if (a1 <= a2)
                r = r + a1;
            else
                r = r + a2;
            break;
        }
        else if (q >= s[i] - c)
        {
            r += c;
            string a1 = solve(s, i + 1, p, q - (s[i] - c));
            r = r + a1;
            break;
        }
        else if (p >= 26 - (s[i] - c))
        {
            r += c;
            string a2 = solve(s, i + 1, p - (26 - (s[i] - c)), q);
            r = r + a2;
            break;
        }
    }
    return mp[make_tuple(i, p, q)] = r;
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
        // mp.clear();
        lol n, p, q;
        cin >> n >> p >> q;
        string s;
        cin >> s;
        cout << solve(s, 0, p, q) << '\n';
    }

    return 0;
}