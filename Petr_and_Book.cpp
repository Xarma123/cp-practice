#include <iostream>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[7];
    for (lol i = 0; i < 7; i++)
    {
        cin >> a[i];
    } 
    lol s = 0; lol i = 0,ans;
    while (s!=n)
    {    if(n-s<a[i])
            n=s;
            else
            s+=a[i];

            ans=i;


        i++;
        if(i==7)
        i=0;
         
    } 
    cout<<ans+1;
    
}