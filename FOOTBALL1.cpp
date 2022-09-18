#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string str1 = "1111111";
    string str2 = "0000000";
      bool a1,a2;
    lol found = str.find(str1);
    if (found != string::npos)
        a1=true;
    else
        a1=false;
      lol found2 = str.find(str2);
    if (found2 != string::npos)
        a2=true;
    else
    a2=false;
    
   if(a1||a2) 
   cout<<"YES";
   else
   cout<<"NO";
            return 0;
}