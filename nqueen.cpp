#include <iostream>
#include <bitset>
using namespace std;
bool queen(lol arr[], lol r, lol n)
{
    if (r == n)
    {
        for (lol i = 0; i < 3; i++)
        {
            cout << std::bitset<4>(arr[i]);
            cout << endl;
        }
        return true;
    }
    while (1)
    {
        bool a = true;
        for (lol i = 0; i < r; i++)
        {
            if (arr[i] == arr[r])
            {

                a = false;
                break;
            }
            if (((arr[r] << (r - i)) == arr[i]) || ((arr[r] >> (r - i)) == arr[i]))
            {

                a = false;
                break;
            }
        }
        if (a)
        {
            if (queen(arr, r + 1, n))
                return true;
        }
        arr[r] << 1;
    }

}
int main()
{
    lol n;
    cin >> n;
    lol arr[n] = {1};

    queen(arr,0,n);
}