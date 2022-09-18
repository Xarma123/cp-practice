#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol minJumps(lol arr[], lol n)
{
    lol farprv = arr[0];
    lol fnew = INT_MIN;
    lol jump = 0; 
    lol i ;
    for ( i = 1; i < n; i++)
    {
        if (i <= farprv)
        {
            fnew = max(fnew, arr[i] + i);
        }
        else
        {
            if (fnew <= farprv)
                break;
            else
            {
                jump++;
            } 
            farprv=fnew;
            fnew=max(fnew,arr[i]+i);

        }
    } 
    if(i==n)
    return jump;
    else
    return -1;
}
int main()
{

    return 0;
}