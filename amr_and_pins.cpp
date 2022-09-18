#include <bits/stdc++.h>
using namespace std;
int main()
{
    double r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;
    double dis = sqrt( pow(x-x1,2)+pow(y-y1,2));
       cout<<ceil(dis/(2*r));
       

}