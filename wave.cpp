#include <iostream>
using namespace std;
int main()
{
    lol a[3][3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9};
    lol j = 0;
    for (lol i = 0; i < 3; i++)
    {
        while (j >= 0 && j < 3)
        {
            cout << a[j][i];
            if (i % 2 == 0)
            {
                j++;
            }
            else
            {
                j--;
            }
        }
        if (j == 3)
            j--;
        else
            j++;
    }
}
