#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
int main()
{     
   lol t ; cin>>t;
   for (lol j = 0; j < t; j++)
   {    lol n;
        cin >> n;
        lol a[n];
        lol c=0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                c++;
            }
            
        }

        if ((c % 2) == 0)
            cout << "YES";

        else
        { lol i;
            sort(a,a+n);
            for ( i = 0; i < n; i++)
            {
                if(    binary_search(a+i,a+n, a[i]+1 ) )
                 { cout<<"YES";
                    break;
                 }

            } if(i==n)
               cout<<"NO";
         } 
        cout<<endl;
   }
}