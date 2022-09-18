#include <iostream>
using namespace std;
int main()
{
    string b;
    cin >> b;
    string a; a[0]='\0';
    lol i = 0;
     while (b[i] != '\0')
    {

        tolower(b[i]);

        if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')
           {
              i++; continue;
           }
        else
        {
            a = a + '.';
            a = a + b[i];  
            i++;
        } 
    }

    cout << a;
}