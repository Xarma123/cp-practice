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
    lol a[n], b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    string a1 = "";
    string a2 = "";

    for (lol i = 0; i < n; i++)
    {
        a1.push_back('0');
        a2.push_back('0');
        lol y = lower_bound(b, b + n, a[i]) - b;
        if (i + y < n || i < n / 2)
            a1.back() = '1';
        y = lower_bound(a, a + n, b[i]) - a;
        if (i + y < n || i < n / 2)
            a2.back() = '1';
    }
    cout << a1 << endl;
    cout << a2 << endl;

    return 0;
}