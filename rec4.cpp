#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void permut(char *a, lol i)
{
    if (a[i] == '\0')
    {
        cout << a << " ,";
        return;
    }
    for (lol k = i; a[k] != '\0'; k++)
    {

        swap(a[i], a[k]);

        permut(a, i + 1);
        swap(a[i], a[k]);
    }

    return;
}

int main()
{
    char a[100];
    cin >> a;

    permut(a, 0);
}