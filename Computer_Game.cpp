#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
         string a; cin>>a;
      
        long long i; 
           string t;
            cin >> t;
        for (i = 0; i < n; i++)
        {
         
            if (a[i] == t[i] &&t[i]=='1')
            {
          
                break;
            }
        } 

        if (i == n)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}