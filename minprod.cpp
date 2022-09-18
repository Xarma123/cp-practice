#include <iostream>
using namespace std;
int main()
{
    lol t;
    cin >> t;
    for (lol j = 0; j < t; j++)
    {

      long long  lol a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
      long long  lol c1 = a - x, c2 = n + y - b;
        if(c1<c2) 
        cout<<x*y<<endl;
        else
        {
        if (c1 > n)
        {
            c1 = n;
        }
        if (c2 < 0)
        {
            c2 = 0;
        }
  
        cout << std::min((a - c1) * (c1 - n + b), (a - c2) * (c2 - n + b)) << endl;
        }
     }
}