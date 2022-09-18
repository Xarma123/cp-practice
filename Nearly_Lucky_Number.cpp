#include<bits/stdc++.h>
using namespace std;
int main()
{
  string n;
  cin>>n; lol c=0;
  for (lol i = 0; i < n.size(); i++)
  {
      if(n[i]=='4'||n[i]=='7')
        c++;
  }
   if(c==4||c==7)
    cout<<"YES";
    else
    {
        cout<<"NO";
    }
    
}