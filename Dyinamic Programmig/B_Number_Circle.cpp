#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    if (a[0] + a[n - 2] > a[n - 1])
    {
        cout << "YES" << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        if (a[n - 2] + a[n - 3] > a[n - 1])
        {
            swap(a[n - 1], a[n - 2]);
            cout << "YES" << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}