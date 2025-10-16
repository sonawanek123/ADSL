#include <iostream>
#include <vector>
using namespace std;

int countWaysToMakeSum(vector<int>& coins, int sum) {
    int N = coins.size();
    vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));

    // Base case: sum = 0 → 1 way (choose nothing)
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    // Fill dp table
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << "Number of ways to make sum " << sum << " : " 
         << countWaysToMakeSum(coins, sum) << endl;

    return 0;
}
