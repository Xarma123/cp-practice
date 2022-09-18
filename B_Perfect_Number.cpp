#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol cal(lol num)
{
    lol ans = 0;
    while (num)
    {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}
int main()
{
    lol k;
    cin >> k;
    lol ans = 0;
    while (k)
    {
        ans++;
        if (cal(ans) == 10)
            k--;
    }
    cout << ans;

    return 0;
}