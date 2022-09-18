#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ans;
void solve(lol N);
void solve2(lol N)
{
    if (N == 0)
        return;
    if (N % 4 == 0 && N > 8)
    {

        N--;
    }
    else if (N % 2 == 0)
    {

        N = N / 2;
    }
    else
    {

        N--;
    }
    solve(N);
}
void solve(lol N)
{
    if (N == 0)
        return;
    if (N % 4 == 0 && N > 8)
    {
        ans++;
        N--;
    }
    else if (N % 2 == 0)
    {
        ans += N / 2;
        N = N / 2;
    }
    else
    {
        ans++;
        N--;
    }
    solve2(N);
}
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        lol N;
        cin >> N;
        solve(N);
        cout << ans << endl;
    }

    return 0;
}