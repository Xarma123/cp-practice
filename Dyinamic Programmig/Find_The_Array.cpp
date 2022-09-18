#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol l = INT_MAX;
        lol sum = 0;
        lol x2 = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];

            sum += a[i];

            if ((a[i] == 1 ))
            {
                 sum-=1;
                for (lol j = x2; j < i; j++)
                {
                    a[j] = (sum) / (i - x2);
                }
                sum = 0;
                x2 = i + 1;
            }
            else if (i == n - 1)
            {
                for (lol j = x2; j <= i; j++)
                {   
                    a[j] = (sum) / (i - x2 + 2);
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {    
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}