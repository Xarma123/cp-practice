#include <bits/stdc++.h>
#define lol long long
using namespace std;

bool isPrime(lol n)
{
   
    if (n <= 1)
        return false;
 
 
    for (lol i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}


int main()
{

    lol t;
    cin >> t;

    while (t--)
    {  lol n ; cin>>n;
         lol sum = 0, arr[n];

        for (lol i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % 2 == 0 || !isPrime(sum))
        {
            cout << n << endl;
            for (lol i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        lol temp = -1;
        for (lol i = 0; i < n; i++)
        {
            if ((sum - arr[i]) % 2 == 0)
            {
                temp = arr[i];
                break;
            }
        }
        bool flag = 1;
        cout << n - 1 << endl;
        for (lol i = 0; i < n; i++)
        {
            if (flag && arr[i] == temp)
            {
                flag = 0;
            }
            else
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}