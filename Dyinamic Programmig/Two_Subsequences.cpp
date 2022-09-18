#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{ 

 lol t; cin>>t;
 while (t--)
 {
    string a;
    cin>>a;
    lol k =0 ;
     for (lol i = 1; i < a.size(); i++)
     {
        if(a[i]<a[k])
        {
            k=i;
        }
     } 

     cout<<a[k]<<" ";
     for (lol i = 0; i <a.size(); i++)
     {     if(i!=k)
        cout<<a[i];
     } 
     cout<<endl;
     

     


 }
 


return 0;
}