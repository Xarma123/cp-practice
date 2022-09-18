#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol r, g, b;
    cin >> r >> g >> b;
    if (r < g)
        swap(r, g);
    if (r < b)
        swap(r, b);
    cout<<min((r+g+b)/3,g+b);
   
    return 0;
}