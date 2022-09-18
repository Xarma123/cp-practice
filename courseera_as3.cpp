#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a = 0, b = 1, c,cf;
    if (n <= 1)
    {
        cout << n;
    }
    else
    {

        for (long long i = 2; i <= n; i++)
        { c= (a+b)%10;
          a=b;
          b=c;
          cf = (a+b)%10;
        }
        cout<<(c*cf)%10;
    }

    return 0;
}