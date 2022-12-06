#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol a, b;
bool check(lol ans)
{
    string s = to_string(ans);
    string q = "";
    for (auto e : s)
    {
        if (e == '4' || e == '7')
            q.push_back(e);
    }
    if (q.size() == 0)
        return false;
    return stol(q) == b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    lol ans = a + 1;
    while (!check(ans))
    {
        ans++;
    }
    cout << ans;

   

    return 0;
}