#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int labeledTrees(int N, vector<int>& D) {
    // Initialize a 2D DP table to store the counts
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    // Base case: There's only one way to create a tree with one vertex
    dp[1][0] = 1;

    // Iterate through the number of vertices
    for (int i = 2; i <= N; ++i) {
        // Iterate through the possible outdegrees for vertex i
        for (int j = 0; j < N; ++j) {
            if (dp[i - 1][j]) {
                // If there's a way to reach vertex i-1 with outdegree j,
                // we can create a tree with vertex i having outdegree k
                for (int k = 0; k <= D[i - 1]; ++k) {
                    if (j + k <= N) {
                        dp[i][j + k] += dp[i - 1][j];
                        dp[i][j + k] %= MOD;
                    }
                }
            }
        }
    }

    // The final result is stored in dp[N][N-1], which represents the
    // number of labeled trees with N vertices and outdegree N-1
    return dp[N][N - 1];
}

int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    // Calculate and print the answer
    int result = labeledTrees(N, D);
    cout << result << endl;

    return 0;
}
