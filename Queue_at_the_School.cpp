#include <iostream>
using namespace std;
int main()
{
    lol n, t;
    cin >> n >> t;
    string a;
    cin >> a;

    while (t--)
    {

        for (lol i = 0; i < a.size() - 1; i++)
        {
            if (a[i] == 'B' && a[i + 1] == 'G')
            {
                swap(a[i], a[i + 1]);
                i++;
            }
        }
    }

    cout << a;
}