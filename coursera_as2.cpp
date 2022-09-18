#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long max1 = LONG_LONG_MIN, max2 = LONG_LONG_MIN;
    for (long long i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        if(t==max1)
        {
            max2=max1;
        }
        else if(t>max1)
        {
            max2=max1;
            max1=t;
        }
        else if(max2<t)
        {
            max2=t;
        }
    } 
    cout<<max1*max2;

    return 0;
}