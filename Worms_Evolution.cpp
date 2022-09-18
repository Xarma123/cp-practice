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
    lol sum;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (j != i)
            {
                sum = a[i] - a[j];
                for (lol k = 0; k < n; k++)
                {
                    if (k != j)
                    {

                        if (k != i)
                        {
                            if (sum == a[k])
                            {
                                cout << i+1 << " " << j+1 << " " << k+1;
                                goto a;
                            }
                        }
                    }
                }
            }
        }
    } 
    cout<<-1;
a:
    return 0;
}