#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;

        if (n % 2 == k % 2)
        {
            if (k <= n)
                cout << 0 << endl;
            else
                cout << k - n << endl;
        } 
        else
        {
            if(n+1>=k)
            {
                cout<<1<<endl;
            }
            else
            cout<<k-n<<endl;
        }
    }

    return 0;
}