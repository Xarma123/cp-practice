#include <bits/stdc++.h>
using namespace std;
long long lol getPairsCount(long long arr[], long long n, long long k)
{
    unordered_map<long long, long long> m;
    long long count = 0;
    for (long long i = 0; i < n; i++)
    {
        if (m.find(k - arr[i]) != m.end())
        {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        long long s = 0;
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        if ((2 * s) % n != 0)
        {
            cout << 0 << endl;
        }
        else
        { 
            long long c = getPairsCount(a,n,(2*s)/n);
            cout<<c<<endl;
        }
    }

    return 0;
}