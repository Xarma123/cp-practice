#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bool arr[3] = {false, false, false};
    lol a ; cin>>a;
    if(a>=1&&a<=3)
    arr[a-1]=true; 
    a=3;
    while (a--)
    {
       lol a1,a2;
       cin>>a1>>a2; 
     
       swap(arr[a1-1],arr[a2-1]);
    }
    if(arr[0])cout<<1;
    if(arr[1])cout<<2;
    if(arr[2])cout<<3;

    return 0;
}