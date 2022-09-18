#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a = 5, b = 10, c = 15;
    int arr[3] = {(int)&a, (int)&b, (int)&c};
    cout << *arr[*((*int)arr[1]) - 8];
    return 0;
}