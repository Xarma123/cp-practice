#include <iostream>
#include <cmath>

#define ll long long
#define MOD 1000000007

using namespace std;

lol n;
long double ans;

void solve() {
    cin >> n;
    cout << (lol) sqrt(n) + (lol) pow(n, 1.0l / 3) - (lol) pow(n, 1.0l / 6) << "\n";
}

int main() {
    lol t;
    cin >> t;
    while (t--) solve();
}
