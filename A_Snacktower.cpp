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
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    lol j = n - 1;
    set<lol> x;
    for (lol i = 0; i < n; i++)
    {
        if (b[i] == a[j])
        {
            cout << b[i] << " ";
            j--;
            while (j >= 0 && x.count(a[j]))
            {
                cout << a[j] << " ";
                x.erase(a[j]);
                j--;
            }
            cout << endl;
        }
        else
        {
            x.insert(b[i]);
            cout << endl;
        }
    }

    return 0;
}