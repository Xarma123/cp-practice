#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol a, b, c;
    cin >> a >> b >> c; 
    lol t = 0,t2=0,t4=0;
    if(a==2)
    t++;
    if(a==3)
    t2++;
    if(b==2)
    t++;
    if(b==3)
    t2++;
    if(c==2)
    t++;
    if(c==3)
    t2++;  
    if(a==4)
    t4++;
    if(b==4)
    t4++;
    if(c==4)
    t4++;
    if(t>=2||t2==3||a==1||b==1||c==1||(t==1&&(t4==2)))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;


    return 0;
}