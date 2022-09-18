#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k1, k2;
        cin >> n >> k1 >> k2;
        lol w, b;
        cin >> w >> b;
        if (k1 < k2)
            swap(k1, k2);

        if(((k1 - k2) / 2 + k2 >=w)&&( (k1 - k2) / 2 +n-k1 >=b))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;


    }

    return 0;
}