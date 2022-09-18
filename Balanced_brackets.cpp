#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string a;
    stack<char> s(100);
    cin >> a;
    lol i, f = 1;
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] == '(')
        {
            s.push(a[i]);
        }
        else if (a[i] == ')')
        {
            if (s.empty())
            {
                cout << "NO";
                f = 0;
                break;
            }
            else
            {
                s.pop();
            }
        }
    }
    if (i == a.size() && s.empty())
    {
        cout << "YES";
    }
    else if (f)
        cout << "NO";
}