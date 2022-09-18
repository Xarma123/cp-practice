#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long lol n, k;
    cin >> n >> k;
    if (k <= (n - n / 2))
    {
        cout<<(2*k-1);
    }
    else
    {
        k=k-(n-n/2);
        cout<<2*k;
    }
}