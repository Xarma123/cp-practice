#include <bits/stdc++.h>
#define lol long long
using namespace std;

vector<long long> A;
vector<long long> cnt;
vector<list<long long>> g;
vector<long long> v;
long long A_sum = 0;
long long mod = 1e9 + 7;

long long dfs(long long i, long long p)
{
    long long path_sum = v[i]; // contribution of current node
    long long cnt_ = 0;
    for (long long x : g[i])
    {
        if (x != p)
        {
            long long t = dfs(x, i) % mod;
            path_sum += (v[i] * 1ll * cnt[x] - t + mod) % mod;
            path_sum %= mod; // contribution of child x
            cnt_ += cnt[x];
        }
    }
    cnt[i] = cnt_ + 1;
    return A[i] = path_sum;
}

void reroot(long long root, long long prev_root)
{
    A_sum += A[root];
    A_sum %= mod;
    for (long long x : g[root])
    {
        if (x != prev_root)
        {
            cnt[root] -= cnt[x];
            A[root] -= (v[root] * 1ll * cnt[x] - A[x] + mod) % mod;
            A[x] += (v[x] * 1ll * cnt[root] - A[root] + mod) % mod;
            cnt[x] += cnt[root];
            reroot(x, root);
            swap(root, x);
            cnt[root] -= cnt[x];
            A[root] -= (v[root] * 1ll * cnt[x] - A[x] + mod) % mod;
            A[x] += (v[x] * 1ll * cnt[root] - A[root] + mod) % mod;
            cnt[x] += cnt[root];
            swap(root, x);
        }
    }
}

void ans()
{
    long long n;
    cin >> n;
    long long v_sum = 0;
    v.resize(n);
    cnt.resize(n);
    for (long long &x : v)
    {
        cin >> x;
        v_sum += x;
    }
    A.resize(n);
    g.resize(n);
    for (long long i = 0; i < n - 1; i++)
    {
        long long p, c;
        cin >> p >> c;

        g[p - 1].push_back(c - 1);
        g[c - 1].push_back(p - 1);
    }

    dfs(0, -1);
    reroot(0, -1);
    cout << (A_sum + mod) % mod << endl;
}

int main()
{
    // long long t; cin >> t; while (t--)
    ans();
}