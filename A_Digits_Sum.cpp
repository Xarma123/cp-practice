#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        if(n<9)cout<<0<<endl;
        else{
            cout<<(n-9)/10 + 1<<endl;
        }
    }

    return 0;
}