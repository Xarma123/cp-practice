#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol b;
    cin >> b;
    lol ans = 0;
    for (lol i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            ans++;
            if (b / i != i)
                ans++;
        }
    }
    cout << ans;

    return 0;
}