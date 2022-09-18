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

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol s = 0;
        lol e = n - 1;
        lol ex = a[e] - a[e - 1];
        while (a[e] > a[e - 1])
        { 
            if(a[s]<ex)
            {   
                a[s]=0; 

            } 
        }
    }

    return 0;
}