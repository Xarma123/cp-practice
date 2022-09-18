// #include <bits/stdc++.h>
// #define lol long long
// using namespace std;
// bool isPrime(lol n)
// {
//     if (n <= 1)
//         return false;

//     for (lol i = 2; i <= sqrt(n); i++)
//         if (n % i == 0)
//             return false;

//     return true;
// }
// lol subset(lol a[], lol n)
// {
//     vector<lol> ans;
//     vector<lol> temp;
//     lol cmax = INT_MIN; lol x = pow(2,n);
//     for (lol i = 1; i <= x; i++)
//     {
//         lol sum = 0, c = 0;
//         for (lol j = 0; j < n; i++)
//         {
//             if ( (i >> j) && 1 )
//             {
//                 sum += a[j];
//                 c++;
//                 temp.push_back(a[j]);
//             }
//         }
//         if ((c > cmax ) && (!isPrime(sum)))
//         {   if(!ans.empty())
//             ans.clear();
//             while (!temp.empty())
//             {
//                 ans.push_back(temp.back());
//                 temp.pop_back();
//             }

//             cmax = c;
//         } 
//         if(!temp.empty())
//         temp.clear();
//     } 
//     cout<<cmax<<endl;
//     while (!ans.empty())
//     {
//        cout<<ans.back()<<" ";
//        ans.pop_back();
//     }
//     return cmax;
// }
// int main()
// {
//     lol t;
//     cin >> t;
//     while (t--)
//     {
//         lol n;
//         cin >> n;
//         lol a[n];
//         for (lol i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         } 
//          subset(a,n);
//     }

//     return 0;
// }
#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
   cout<<pow(2,100);
return 0;
}