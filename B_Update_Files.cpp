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
        if (n == 1)
            cout << 0 << endl;
        else
        {
            lol ans = 1;
            lol c = 2;
            if (c >= n)
            {
                cout << ans << endl;
            }
            else
            {

                if (n <= (long long)pow(2, (long long)log2(k)+1))
                {      
                    if((long long )pow(2,(long long)log2(n))<n )
                    cout<<(long long)log2(n)+1<<endl;
                    else
                      cout<<(long long)log2(n)<<endl;
                          
                }
              
                
                else
                {
                    c = n - (long long)pow(2, (long long)log2(k)+1);
                    ans = (long long)log2(k)+1;
                    ans += ceil(((long double)c) / k);
                    cout << (long long)ans << endl;
                }
            }
        }
    }

    return 0;
}