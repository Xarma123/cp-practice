#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = n - 1; i > 0; i--)
    {
        for (lol j = 0; j < i; j++)
        {
            if (i % 2 == 0)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
            }
            else
            {
                if (a[j] < a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }

    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}