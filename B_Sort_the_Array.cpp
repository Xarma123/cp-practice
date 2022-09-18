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
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    lol i = 0;
    while (i < n && a[i] == b[i])
        i++;
    if (i == n)
    {
        cout << "yes" << endl;
        cout << 1 << " " << 1;
    }
    else
    {
        lol j = n - 1;
        while (j >= 0 && a[j] == b[j])
            j--;
        lol a1 = i, a2 = j;
        while (i < j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if (is_sorted(a, a + n))
        {
            cout << "yes" << endl;
            cout << a1 + 1 << " " << a2 + 1;
        }
        else
            cout << "no";
    }

    return 0;
}