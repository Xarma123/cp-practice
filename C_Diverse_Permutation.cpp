#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    cout << 1 << " ";
    bool f = true;
    lol l = 1;
    set<lol> use;
    use.insert(l);
    for (lol i = k; i >= 1; i--)
    {
        if (f)
        {
            cout << l + i << " ";
            l = l + i;
            f = false;
        }
        else
        {
            cout << l - i << " ";
            l = l - i;
            f = true;
        }
        use.insert(l);
    }
    for (lol i = 1; i <= n; i++)
    {
        if (!use.count(i))
            cout << i << " ";
    }

    return 0;
}