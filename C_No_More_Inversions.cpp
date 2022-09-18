#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;

        lol i = 1, j = k;
        while (i <= k)
        {
            if (i < k - (n - k))
                cout << i << " ";
            else
            {
                cout << j << " ";
                j--;
            }
            i++;
        }
        cout << endl;
    }

    return 0;
}