#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <numeric>
typedef long long lol ll;
using namespace std;
#define FORa(a, n) for (lol i = a; i < n; i++)
#define FORx(x, a, n) for (lol x = a; x < n; x++)
#define FOR(n) for (lol i = 0; i < n; i++)
#define FORj(n) for (lol j = 0; j < n; j++)
#define FORja(a, n) for (lol j = a; j < n; j++)
#define vect vector<ll>
#define el cout << endl;
#define mod 1000000007
#define it(v) v.begin(), v.end()
bool isEven(ll n)
{
    // n&1 is 1, then odd, else even
    return (!(n & 1));
}
void show(vect v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    el
}
vect get_digits(ll n)
{
    vect v;
    while (n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(it(v));
    return v;
}
ll binpow(ll n, ll k)
{
    n %= mod;
    ll res = 1;
    while (k > 0)
    {
        if (k & 1)
            res = res * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return res;
}
lol binary_search(vect v, ll search)
{
    lol lo = 0;
    lol hi = v.size() - 1;
    lol mid = (lo + hi) / 2;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (v[mid] < search)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] == search)
        return lo;
    if (v[hi] == search)
        return hi;
    else
        return -1;
}
vect primes;
bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    if (n % 2 == 0)
        return false;
    if (n == 2 || n == 3)
        return true;
    for (lol i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
void sieve(ll m)
{
    vector<bool> v(m, true);
    for (ll i = 2; i * i < m; i++)
    {
        if (v[i])
            for (ll j = i * i; j < m; j += i)
                v[j] = false;
    }
    for (ll i = 2; i < m; i++)
        if (v[i])
            primes.push_back(i);
}
ll GCD(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
bool is_palindrome(string s, lol n)
{
    ll i = 0, j = n - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
// ll ncr(ll n,ll r){
//     if(n<r)return 0;
//     if(n==r)return 1;
//     ll f[n+1];
//     f[0]=1,f[1]=1;
//     for(lol i=2;i<=n;i++)f[i]=i*f[i-1];
//     ll ans= (f[n])/(f[n-r]*f[r]);
//     return ans;
// }

void solve()
{

    lol n, k, count = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    lol l = str.length();
    bool flag = false;
    if (is_palindrome(str, l))
    {
            flag = true;
    }
    if(k==0 || flag){
        cout << "1" << endl;
    }else{
        cout << "2" << endl;
    }
}
int main()
{
    lol t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}