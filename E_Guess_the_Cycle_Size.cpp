#include <bits/stdc++.h>
#define lol long long
using namespace std;
long long ask(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    long long x;
    cin >> x;
    return x;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i <= 26; i++)
    {
        long long x = ask(1, i);
        long long y = ask(i, 1);
        if (x == -1)
        {
            cout << "! " << i - 1 << endl;
            break;
        }
        if (x != y)
        {
            cout << "! " << x + y << endl;
            break;
        }
    }


return 0;
}