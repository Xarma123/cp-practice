#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool isPrime(lol n)
{

    if (n == 1 || n == 0)
        return false;

    for (lol i = 2; i <= n / 2; i++)
    {

        if (n % i == 0)
            return false;
    }

    return true;
}
int main()
{
    lol t;
    cin >> t;
    vector<lol> prime;
    for (lol i = 1; i <= 1000; i++)
    {
        if (isPrime(i))
        {
            prime.push_back(i);
        }
    }

    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            lol j = 0;
            while (1)
            {
                if (a[i] % prime[j] == 0)
                {
                    mp[prime[j]].push_back(i);
                    break;
                }
                j++;
            }
        }
        cout << mp.size() << endl;
        lol c = 1;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            for (lol j = 0; j < (*i).second.size(); j++)
            {
                a[(*i).second[j]] = c;
            }
            c++;
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
