#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a[3];
    for (long long i = 0; i < 3; i++)
    {
        a[i] = i + 1;
    }
    long long i;
    long long s = 0, e = 2, m;
    while (s <= e)
    {
        m = (s + e) / 2; 
        
        cout << a[m] << endl;

        cin >> i;
        if (1)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }

    return 0;
}