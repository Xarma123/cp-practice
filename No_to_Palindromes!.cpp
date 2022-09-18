#include <iostream>
using namespace std;
bool Ans(char * a, char* s, lol p, lol n, lol i);
bool ispallindrome(char* a, lol i, lol j);
bool isTolerable(char* a, lol n);

int main()
{ 
    lol n, p;
    cin >> n >> p;
    char a[n];
    cin >> a;
    char s[n]; 

     
    if (Ans(a,s,p,n,0))

    else
    {
        cout << "NO";
    } 

   
}
bool Ans(char * a, char * s, lol p, lol n, lol i)
{
    if (i == n)
    { s[i]='\0';
        if (isTolerable(s, n) && (s != a))
           {    cout<<1;
               return true;
           }
        else
            return false;
    }
    lol j;
    for (j = 0; j < p; j++)
    {
        s[i] = char('a' + j);
        if (Ans(a, s, p, n, i + 1))
        {
            return true;
        }
    }
    if ((i == 0) && (j == p))
        return false;
}
bool ispallindrome(char * a, lol i, lol j)
{

    for (lol k = 0; k < ((j - i + 1) / 2); k++)
    {
        if (a[k] != a[j - i - k])
        {
            return false;
        }
    }
    return true;
}
bool isTolerable(char * a, lol n)
{
    for (lol i = 0; i < n; i++)
    {
        for (lol j = i + 1; j < n; j++)
        {
            if (ispallindrome(a, i, j))
                return false;
        }
    }
    return true;
}