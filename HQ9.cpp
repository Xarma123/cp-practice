#include <bits/stdc++.h>

using namespace std;
int main()
{ 
    string a;
    cin>>a;lol i;
    for ( i = 0; a[i]!='\0'; i++)
    {
       if(a[i]=='H'||a[i]=='Q'||a[i]=='9'||a[i]=='+')
       {cout<<"YES";
         break;
       }

    }
    if(i==a.size())
      cout<<"NO";

}