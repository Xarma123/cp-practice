#include <bits/stdc++.h>
using namespace std;

#define SUCCESS true
#define FAILED false

bool E(), Edash(), T(), Tdash(), F();
int cursor;
string s;

int main()
{
    cout << "Enter the string" << endl;
    cin >> s;
    cursor = 0;

    if (E() && cursor == s.size())
    {
        cout << "String is successfully parsed" << endl;
    }
    else
    {

        cout << "Error in parsing String" << endl;
    }
    return 0;
}

// Grammar rule: E -> T E'
bool E()
{
    if (cursor == s.size())
        return FAILED;
    cout << s.substr(cursor) << " E -> T E'\n";
    if (T())
    {
        if (Edash())
            return SUCCESS;
        else
            return FAILED;
    }
    else
        return FAILED;
}

// Grammar rule: E' -> + T E' | $
bool Edash()
{
    if (cursor != s.size() && s[cursor] == '+')
    {
        cout << s.substr(cursor) << " E' -> + T E'\n";
        cursor++;
        if (T())
        {                // Call non-terminal T
            if (Edash()) // Call non-terminal E'
                return SUCCESS;
            else
                return FAILED;
        }
        else
            return FAILED;
    }
    else
    {
        cout << s.substr(cursor) << " E' -> $\n";
        return SUCCESS;
    }
}

// Grammar rule: T -> F T'
bool T()
{
    if (cursor == s.size())
        return FAILED;
    cout << s.substr(cursor) << " T -> F T'\n";
    if (F())
    {                // Call non-terminal F
        if (Tdash()) // Call non-terminal T'
            return SUCCESS;
        else
            return FAILED;
    }
    else
        return FAILED;
}

// Grammar rule: T' -> * F T' | $
bool Tdash()
{
    if (cursor != s.size() && s[cursor] == '*')
    {
        cout << s.substr(cursor) << " T' -> * F T'\n";
        cursor++;
        if (F())
        {                // Call non-terminal F
            if (Tdash()) // Call non-terminal T'
                return SUCCESS;
            else
                return FAILED;
        }
        else
            return FAILED;
    }
    else
    {
        cout << s.substr(cursor) << " T' -> $\n";
        return SUCCESS;
    }
}

// Grammar rule: F -> ( E ) | id
bool F()
{
    if (cursor != s.size() && s[cursor] == '(')
    {
        cout << s.substr(cursor) << " F -> ( E )\n";
        cursor++;
        if (E())
        { // Call non-terminal E
            if (cursor != s.size() && s[cursor] == ')')
            {
                cursor++;
                return SUCCESS;
            }
            else
                return FAILED;
        }
        else
            return FAILED;
    }
    else if (cursor + 1 != s.size() && s[cursor] == 'i' && s[cursor + 1] == 'd')
    {
        cout << "id"
             << " F -> id\n";
        cursor += 2;
        return SUCCESS;
    }
    else
        return FAILED;
}
