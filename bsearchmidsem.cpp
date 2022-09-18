#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin>>n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol low = 0;
    lol high = n - 1;
    lol c;
    cin >> c;
    lol ind = -1;
    while (low <= high)
    {
        lol mid = low + (high - low) / 3;
        if (a[mid] == c)
        {
            ind = mid;
            break;
        }
        else if (a[mid] > c)
            high = mid - 1;
        else
            low = mid + 1;
    } 
    cout<<ind;

    return 0;
}