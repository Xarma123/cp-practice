#include <bits/stdc++.h>

using namespace std;

int main()
{
    lol n;
    cin >> n;

    if (n == 0)
        cout << 0 << " " << 0 << " " << 0;
    else
    {
        lol a = 0,b = 1;
        while (a + b != n)
        {  a=b;
        b=a+b;


        } 
        cout<<0<<" "<<a<<" "<<b;
    }
}