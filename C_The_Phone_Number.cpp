#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol c = 1;
    for (lol i = 0; i < n; i++)
    {
        a[i] = n - (c++) + 1;
    }
    lol s = sqrt(n);
    for (lol i = 0; i < n; i += s)
    {
        lol r = min(i + s - 1, n - 1);
        lol l = i;
        while (l < r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}