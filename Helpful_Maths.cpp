#include <bits/stdc++.h>

using namespace std;
int main()
{
    string a;
    cin >> a;
    lol n = a.size();
    for (lol i = 0; i < n; i = i + 2)
    {
        for (lol j = i + 2; j < n; j = j + 2)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }

    cout << a;
}
