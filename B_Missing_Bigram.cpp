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
        string a[n - 2];
        for (lol i = 0; i < n - 2; i++)
        {
            cin >> a[i];
        }
        char ans[n];
        lol polol = 0;
        bool check = true;
        for (lol i = 0; i < n - 2; i++)
        {
            if (i == 0)
            {
                ans[polol] = a[i][0];
                polol++;
            }
            if (i < n - 3)
            {
                if (a[i][1] == a[i + 1][0])
                {
                    ans[polol] = a[i][1];
                    polol++;
                }
                else
                {
                    check = false; 
                    ans[polol]=a[i][1];
                    polol++;
                   ans[polol]=a[i+1][0];
                   polol++;
                   
                }
            }
            else
            {   
                ans[polol]=a[i][1];
                polol++;
               
            }
        }
        if (check)
        {
            ans[polol]='a';
        }
         for (lol i = 0; i < n; i++)
         {
             cout<<ans[i];
         }
         cout<<endl;
    }

    return 0;
}