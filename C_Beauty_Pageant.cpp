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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (lol i = n - 1; i >= 1; i--)
    {
        for (lol k1 = 0; k1 < i; k1++)
        {
            cout << n - i + 1 << " ";
            for (lol j = n - 1; j >= i; j--)
            {
                cout << a[j] << " ";
            }
            cout << a[k1] << endl;
            k--;
            if (k == 0)
                break;
        }
        if (k == 0)
            break;
    }
    lol i = 0;
    while (k--)
    {
        cout << 1 << " " << a[i] << endl;
        i++;
    }

    return 0;
}