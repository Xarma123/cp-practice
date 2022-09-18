
#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol arraySortedOrNot(lol arr[], lol n)
{

    if (n == 1 || n == 0)
        return 1;

    if (arr[n - 1] > arr[n - 2])
        return 0;

    return arraySortedOrNot(arr, n - 1);
}
lol CeilIndex(vector<lol> &v, lol l, lol r, lol key)
{
    while (r - l > 1)
    {
        lol m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}
lol lis(lol v[], lol n)
{
    if (n == 0)
        return 0;

    vector<lol> tail(n, 0);
    lol length = 1;

    tail[0] = v[0];
    for (lol i = 1; i < n; i++)
    {

        if (v[i] < tail[0])
            tail[0] = v[i];

        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];

        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    return length;
}

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n]; lol m= INT_MIN;
          lol index;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i]; 
            if(m!=a[i])
         {   m = max(a[i],m);
            if(m==a[i])
            index=i;}
        }
        if (n % 2 == 0)
        {
            cout << "YES";
        }
        else
        {
            if (n == 1)
                cout << "NO" << endl;
            else
            {
                lol x = lis(a, n);
                if (x % 2 == 0)
                    cout << "YES" << endl;
                else
                {
                    if (is_sorted(a, a + n))
                    {
                        if (a[0] != a[n - 1])
                            cout << "NO" << endl;
                        else
                            cout << "YES" << endl;
                    }
                    else
                    {
                        if (arraySortedOrNot(a, n))
                            cout << "YES" << endl; 

                            if(a[index-1]<a[index])
                             cout<<"YES"<<endl;
                             else
                             cout<<"NO"<<endl;
                       
                    }
                }
            }
        }
    }

    return 0;
}
