#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    lol t;
    cin >> t;
    for (lol j = 0; j < t; j++)
    {

        long long lol n;
        cin >> n;
        long long lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n < 3)
            cout << "NO" << endl;
        else if (n == 3)
        {
            if (a[0] == a[2])
                cout << "YES" << endl;
            else
            {
                cout << "NO" << endl;
            }
        }
        else if (n > 3)
        {

            lol i,k=0;
            for (i = 0; i < n - 2; i++)
            {
                for (lol j = i + 2; j < n; j++)
                {
                    if (a[j] == a[i])
                      {  cout << "YES" << endl; k=1; break;}
                } if(k)
                   break;
  
                //     if ( s((a + i + 2),( a + n), a[i]) )
                //     {
                //         cout << "YES" << endl;
                //         break;
                //     }
                } if (i == n - 2)
                    cout << "NO" << endl;
               
            } 
        }
    }