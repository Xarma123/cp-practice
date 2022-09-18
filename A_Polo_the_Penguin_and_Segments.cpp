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
    lol c = 0;
    while (n--)
    {
        lol l, r;
        cin >> l >> r;
        c += r - l + 1;
    }
    if (c % k == 0)
        cout << 0;
    else
        cout << k - c % k; 
        
    return 0;
}