#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    string q[3];
    q[0] = to_string(a[n - 1]);
    q[1] = to_string(a[n - 2]);
    q[2] = to_string(a[n - 3]);
    sort(q, q + 3);
    cout << q[2] << q[1] << q[0];

    return 0;
}