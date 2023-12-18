#include <iostream>
#include <vector>
int mod_inverse(int x);
void extended_gcd(int a, int b, int &x, int &y, int &gcd);

using namespace std;

const int MOD = 1e9 + 7;
int mod_inverse(int x)
{
    int result, _, gcd;
    extended_gcd(x, MOD, result, _, gcd);
    return (result % MOD + MOD) % MOD;
}

void extended_gcd(int a, int b, int &x, int &y, int &gcd)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        gcd = a;
        return;
    }

    int x1, y1;
    extended_gcd(b, a % b, x1, y1, gcd);

    x = y1;
    y = x1 - (a / b) * y1;
}

vector<int> solve_test_case(int n, vector<pair<int, int>> &probabilities, vector<int> &h_values)
{
    vector<int> ans;
    int prefix_sum = 0;
    int total_probability = 1;

    for (int i = 0; i < n; ++i)
    {
        int xi = probabilities[i].first;
        int yi = probabilities[i].second;
        int p = (1LL * xi * mod_inverse(yi)) % MOD;
        total_probability = (1LL * total_probability * mod_inverse((1 - p + MOD) % MOD) % MOD) % MOD;
        prefix_sum = (prefix_sum + p) % MOD;
        int expected_score = (1LL * prefix_sum * mod_inverse(total_probability) % MOD) * h_values[i] % MOD;
        ans.push_back(expected_score);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> probabilities(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> probabilities[i].first >> probabilities[i].second;
        }

        vector<int> h_values(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            cin >> h_values[i];
        }

        vector<int> result = solve_test_case(n, probabilities, h_values);

        for (int i : result)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
