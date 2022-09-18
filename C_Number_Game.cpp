#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> divisors(lol n)
{
    vector<lol> v;
    for (lol i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {

            if (n / i == i)
                v.push_back(i);
            else
            {
                v.push_back(i);

                v.push_back(n / i);
            }
        }
    }
    return v;
}
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        if (n & 1)
        {
            if (n != 1)
                cout << "Ashishgup" << endl;
            else
                cout << "FastestFinger" << endl;
        }
        else
        {
            vector<lol> divisor = divisors(n);

            sort(divisor.begin(), divisor.end());

            lol d = 2;
            for (lol i = 0; i < divisor.size(); i++)
            {

                if (!(divisor[i] & (divisor[i] - 1)))
                {
                    d = divisor[i];
                }
            }

            n = n / d;

            if (n == 1)
            {
                if (d != 2)
                    cout << "FastestFinger" << endl;
                else
                {
                    cout << "Ashishgup" << endl;
                }
            }
            else
            {
                divisor.clear();
                divisor = divisors(n);

                if (divisor.size() == 2)
                {
                    if (d == 2)
                    {
                        cout << "FastestFinger" << endl;
                    }
                    else
                    {
                        cout << "Ashishgup" << endl;
                    }
                }
                else
                {
                    cout << "Ashishgup" << endl;
                }
            }
        }
    }

    return 0;
}