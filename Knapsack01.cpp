#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int W = 7;

    int weights[6] = {0, 2, 3, 5, 1, 2};
    int values[6]  = {0, 20, 40, 40, 50, 50};

    int dp[6][8]; // dp[i][w] = max value with i items and capacity w

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i] + dp[i - 1][w - weights[i]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value: " << dp[n][W] << endl;

    cout << "Items selected: ";
    int i = n, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weights[i];
        }
        i--;
    }

    return 0;
}
