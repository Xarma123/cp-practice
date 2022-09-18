#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol Length(string &str1, string &str2)
{
    lol len1 = str1.size();
    lol len2 = str2.size();
    if (len1 < len2)
    {
        for (lol i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (lol i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1;
}
lol multiply1(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

string addBitStrings(string first, string second)
{
    string result;

    lol length = Length(first, second);
    lol carry = 0;

    for (lol i = length - 1; i >= 0; i--)
    {
        lol firstBit = first.at(i) - '0';
        lol secondBit = second.at(i) - '0';

        lol sum = (firstBit ^ secondBit ^ carry) + '0';

        result = (char)sum + result;

        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry)
        result = '1' + result;

    return result;
}
lol multiply(string X, string Y)
{

    lol n = Length(X, Y);

    if (n == 0)
        return 0;
    if (n == 1)
        return multiply1(X, Y);

    lol fh = n / 2;
    lol sh = (n - fh);

    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    lol P1 = multiply(Xl, Yl);
    lol P2 = multiply(Xr, Yr);
    lol P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}
int main()
{
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << multiply(a, b);

    return 0;
}