#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        n--;
        lol l, r, c;
        cin >> l >> r >> c;
        cout << c << endl;
        lol cl = c, cr = c;
        while (n--)
        {
            lol a, b, ex;
            if (a == b && l == r)
            {
                if (a == l)
                {
                    cl = min(cl, ex);
                    cr = min(cr, ex);
                    cout << cl << endl;
                }
                else if (a < l)
                {
                    cl = ex;

                    l = a;
                    c = cl + cr;
                    cout << c << endl;
                }
                else
                {
                    r = a;

                    cr = ex;
                    c = cl + cr;
                    cout << c << endl;
                }
            }
            else if (l == r)
            {
                if (a < l && b < l)
                {
                    cl = ex;
                    c = cl + cr;
                    l = a;
                    cout << c << endl;
                }
                else if (a < l && b == l)
                {
                    l = a;
                    c = ex;
                    cout << c << endl;
                    cl = ex;
                    cr = min(cr, ex);
                }
                else if (a == l && b > l)
                {
                    r = b;
                    c = ex;
                    cout << c << endl;
                    cr = ex;
                    cl = min(cl, ex);
                }
                else
                {
                    r = b;
                    cr = ex;
                    c = cl + cr;
                    cout << c << endl;
                }
            }
            else if (a == b)
            {
                if (a < l)
                {
                    cl = ex;
                    l = a;
                    c = cl + cr;
                    cout << c << endl;
                }
                else if (a == l)
                {
                    cl = min(cl, ex);
                    if (cl + cr < c)
                        c = cl + cr;
                    cout << c << endl;
                }
                else if (a > l && a < r)
                {
                    cout << c << endl;
                }
                else if (a == r)
                {
                    cr = min(cr, ex);
                    if (cl + cr < c)
                        c = cl + cr;
                    cout << c << endl;
                }
                else
                {
                    r = a;
                    cr = ex;
                    c = cr + cl;
                    cout << c << endl;
                }
            }
            else
            {
                if (a > l && b < r)
                    cout << c << endl;
                else if (a < l && b > r)
                {
                    cout << ex << endl;
                    cl = ex;
                    cr = ex;
                    c = ex;
                    l = a;
                    r = b;
                }
                else if (a < l && b < r)
                {
                    cl = ex;
                    cout << cl + cr << endl;
                    c = cl + cr;
                    l = a;
                }
                else if (a > l && b > r)
                {
                    cr = ex;
                    cout << cl + cr << endl;
                    c = cl + cr;
                    r = b;
                }
                else if (a == l && b < r)
                {
                    cl = min(cl, ex);
                    if (ex + cr < c)
                    {

                        c = ex + cr;
                        cout << c << endl;
                    }
                    else
                    {

                        cout << c << endl;
                    }
                }
                else if (a == l && b == r)
                {
                    cl = min(cl, ex);
                    cr = min(cr, ex);
                    if (ex < c)
                    {

                        c = ex;
                        cout << c << endl;
                    }
                    else
                    {

                        cout << c << endl;
                    }
                }
                else if (a == l && b > r)
                {
                    c = ex;
                    cout << c << endl;
                    cr = ex;
                    cl = min(cl, ex);
                    r = b;
                }
                else if (a > l && b == r)
                {
                    cr = min(cr, ex);
                    if (cr + cl < c)
                    {
                        c = cr + cl;
                        cout << c << endl;
                    }
                    else
                        cout << c << endl;
                }
                else if (a < l && b == r)
                {
                    c = ex;
                    cout << c << endl;
                    cr = min(cr, ex);
                    cl = ex;
                    l=a;
                }
                
            }
        }
    }

    return 0;
}