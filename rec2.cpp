#include <iostream>
using namespace std;

lol str(string a, lol n)
{
    if (n == 0)
    {
        return 0;
    }

    return ((a[n - 1] - 48) + 10 * str(a, n - 1));
}
int main()
{
    while (1)
    {
        string a;
        cin >> a;

        cout << str(a, a.size());
    }
}