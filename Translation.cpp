#include <iostream>
#include <algorithm>

using namespace std;
int main()
{ 
    string a,b;
    cin>>a;
    reverse(a.begin(),a.end());
    cin>>b;
    if(a==b)
    cout<<"YES";
    else
    {
        cout<<"NO";
    }
    

}