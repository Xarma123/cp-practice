#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    char a[101];
    cin.getline(a,101,'\n');
    lol i = 0;
    while (a[i]!='\0')
    {
        i++;
    }
    
    while (1)
    {    if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
           break;
        i--;
    }

    if (a[i] == 'a' ||
        a[i] == 'A' ||
        a[i] == 'e' ||
        a[i] == 'E' ||
        a[i] == 'i' ||
        a[i] == 'I' ||
        a[i] == 'o' ||
        a[i] == 'O' ||
        a[i] == 'u' ||
        a[i] == 'U' ||
        a[i] == 'y' ||
        a[i] == 'Y')
    {
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}