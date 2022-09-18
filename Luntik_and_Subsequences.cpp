#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        lol n;
        cin >> n;
        lol ones = 0, zeroes = 0, sum = 0;
        while (n--)
        {

            lol t;
            cin >> t;
            sum += t;
            if (t == 1)
                ones++;
            if (t == 0)
                zeroes++;
        }
        if (sum == 1)
        {
            cout << pow(2, zeroes) << endl;
        }
        else if (sum == 0)
        {
            cout << 0 << endl;
        }
        else if(sum==2) 
        {



        }
        else
        {
            cout << (ones * (pow(2, zeroes))) << endl;
        }
    }

    return 0;
}