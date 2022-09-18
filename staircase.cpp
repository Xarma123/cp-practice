#include <iostream>
using namespace std;
int main()
{
    lol r, c;
    cin >> r >> c;
    lol a[r][c];
    for (lol i = 0; i < r; i++)
    {
        for (lol j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
         lol i = r-1, j =c-1;
         
    lol s ; cin>>s;
        while (a[i][j]!=s)
        {
             if (s<a[i][j])
             {
                  j--;
             }
             else if (s>a[i][j])
             {
                 i++;
             }
                if(!(0<=i&&i<r&&j>=0&&j<c))
                {
                    cout<<"NOT FOUND";
                    break;
                }
             
        }  
           if(0<=i&&i<r&&j>=0&&j<c)
         cout<<i<<" "<<j;

}