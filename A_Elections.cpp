#include<iostream>

using namespace std;
int main()
{
    int t; 
    cin >> t;

    while (t--)
    {
    int a,b,c,maxi;
    cin >> a>>b>>c;
    

        if(a>b && a>c )
        {
            maxi= a;
        }
        if(b>c && b>a)
        {
             maxi= b;
        }
        if(c>a && c>b)
        {
            maxi= c;
        }

    if(a==b==c==maxi)
    {
        cout <<maxi -a +1<<" "<<maxi - b +1<<" "<<maxi - c +1<<endl;
    }
    else if(a==maxi)
    {
        cout <<"0"<<" "<<maxi - b +1<<" "<<maxi - c +1<<endl;
    }
    else if(b==maxi)
    {
        cout <<maxi - a +1<<" "<<"0"<<" "<<maxi - c +1<<endl;
    }
    else if(c==maxi)
    {
        cout <<maxi - a +1<<" "<<maxi - b +1<<" "<<"0"<<endl;
    }
    

 }

 return 0;
}