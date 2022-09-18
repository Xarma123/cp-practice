#include <bits/stdc++.h>
using namespace std;

lol make_string_length_equal(string &x, string &y)
{
    lol n = (lol)(x.size()) - (lol)(y.size());
    if (n > 0)
    {
        reverse(y.begin(), y.end());
        while (n > 0)
        {
            n--;
            y.push_back('0');
        }
        reverse(y.begin(), y.end());
    }
    else if (n < 0)
    {
        reverse(x.begin(), x.end());
        while (n < 0)
        {
            n++;
            x.push_back('0');
        }
        reverse(x.begin(), x.end());
    }
    return (lol)(x.size());
}

char multiply_single_bit(char x, char y)
{
    lol res = (lol)(x - '0') * (lol)(y - '0');
    return (char)(res + '0');
}

string add_zeroes(string x, lol n)
{
    while (n > 0)
    {
        x.push_back('0');
        n--;
    }
    return x;
}

string add_strings(string x, string y)
{
    string res;
    lol n = make_string_length_equal(x, y);
    lol carry = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        lol num = (lol)(x[i] - '0') + (lol)(y[i] - '0') + carry;
        if (num > 1)
            carry = 1;
        else
            carry = 0;
        num %= 2;
        res.push_back((char)(num + '0'));
    }
    if (carry)
        res.push_back((char)(carry + '0'));
    while (!res.empty() and res.back() == '0')
        res.pop_back();
    reverse(res.begin(), res.end());
    if (res.empty())
        res = "0";
    return res;
}

string multiply(string x, string y)
{
    lol n = make_string_length_equal(x, y);
    string ans = "0";
    if (n == 0)
        return ans;
    if (n == 1)
    {
        ans = multiply_single_bit(x[0], y[0]);
        return ans;
    }

    string Xl = x.substr(0, n / 2);
    string Xr = x.substr(n / 2);
    string Yl = y.substr(0, n / 2);
    string Yr = y.substr(n / 2);
    string XlYl = multiply(Xl, Yl);
    string XrYr = multiply(Xr, Yr);
                
    string XlYr = multiply(Xl, Yr);
    string XrYl = multiply(Xr, Yl);

    string middle = add_strings(XlYr, XrYl);
    ans = add_strings(add_zeroes(XlYl, 2 * (n - n / 2)), XrYr);
    ans = add_strings(ans, add_zeroes(middle, n - n / 2));
    return ans;
} 


int main()
{
    string x, y;
    cin >> x >> y;
    cout << multiply(x, y);
    return 0;
}