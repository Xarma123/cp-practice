#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    multiset<long long> a, b;
    for (long long i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        a.insert(t);
    }
    for (long long i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        b.insert(t);
    }
    long long ans = 0;
    auto ita = a.rbegin();
    auto itb = b.rbegin();
    for (long long i = 0; i < n; i++)
    {
        ans += (*ita) * (*itb);
        ita++;itb++;
    } 
    cout<<ans;

    return 0;
}