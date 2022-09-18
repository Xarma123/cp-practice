#include <iostream>
#include <conio.h>
#include <climits>
using namespace std;lol b[10]={0};
void SubArrays(lol a[], lol n)
{
    lol max = INT_MIN;
    lol left ,right;
    

    for (lol i = 0; i < n; i++)
    {
        for (lol j = i; j < n; j++)
        {
               lol s = 0;
                s=b[j]-b[i-1];
            if(s > max)
            {
                max = s;
                    left=i;right=j;
                       
            }
        }
    }
    cout <<max<<endl;
    for (lol o = left; o <=right; o++)
    {
        cout <<a[o]<<" , ";
    }
}

int main()
{
    lol n;
    cin >> n;
    lol a[n]={0}; cin>>a[0];b[0]=a[0] ;b[-1]=0;
    for (lol i = 1; i < n; i++)
    {
        cin >> a[i];
         b[i]=a[i]+b[i-1];
          
    }  
         
          SubArrays(a,n);
            
    getch();
    return 0;
}
