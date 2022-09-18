#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k, r;
    cin >> k >> r;
    lol K = k;
    while (K % 10 != 0 && K % 10 != r)
    {

        K += k;
    }
    cout << K / k;

    return 0;
}