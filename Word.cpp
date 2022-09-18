#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a;
  cin>>a; lol u=0;
  lol l = 0;
  for (lol i = 0; i < a.size(); i++)
  {  if (a[i]>='a'&&a[i]<='z')
  {
      l++;
  }
  if (a[i]>='A'&&a[i]<='Z')
  {
      u++;
  }
  
  
        
  } 
  if (u>l)
  { 
       transform(a.begin(),a.end(),a.begin(),::toupper);
       cout<<a;
      
  }
  else 
  {  transform(a.begin(),a.end(),a.begin(),::tolower);
       cout<<a;
      
      
  } 
  
  
  
  


}


