#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ 
    string a; cin>>a; lol n = a.size();
    sort(a.begin(),a.end());lol ans=1;
    for (lol i = 1; i <n ; i++)
    {   
         if(a[i]!=a[i-1])
         ans++;
        
    }
     
   if(ans&1!=0)
   cout<<"IGNORE HIM!";
   else
   {
       cout<<"CHAT WITH HER!";
   }
   
}