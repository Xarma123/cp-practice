#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        if (d1 < d2)
            swap(d1, d2);
        if ((n % 3 != 0) || d1 > n / 3 || d2 > n / 3)
            cout << "no" << endl;
        else
        {
            if (k - 2 * 1ll * d1 - d2 >= 0 && (k - 2 * 1ll * d1 - d2) % 3 == 0&&((k - 2 * 1ll * d1 - d2)/3)+d1+d2<=n/3)
                cout << "yes" << endl;
            else if (k - 2 * 1ll * d1 + d2 >= 0 && (k - 2 * 1ll * d1 + d2) % 3 == 0&&((k - 2 * 1ll * d1 + d2)/3)+d1<=n/3&&((k - 2 * 1ll * d1 + d2)/3)+d1-d2>=0)
                cout << "yes" << endl;
            else if (k + 2 * 1ll * d1 - d2 >= 0 && (k + 2 * 1ll * d1 - d2) % 3 == 0&&((k + 2 * 1ll * d1 - d2)/3)<=n/3&&((k + 2 * 1ll * d1 - d2)/3)+d2-d1<=n/3&&((k + 2 * 1ll * d1 - d2)/3)-d1>=0)
                cout << "yes" << endl;
            else if (k + 2 * 1ll * d1 + d2 >= 0 && (k + 2 * 1ll * d1 + d2) % 3 == 0&&((k + 2 * 1ll * d1 + d2)/3)<=n/3&&((k + 2 * 1ll * d1 + d2)/3)-d1-d2>=0)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }

    return 0;
}