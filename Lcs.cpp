#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char X[] = "PRESIDENT";
    char Y[] = "PROVIDENCE";

    int m = strlen(X);
    int n = strlen(Y);

    int dp[100][100]; // DP table

    // Initialize the first row and first column
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // Now reconstruct the LCS from the dp table
    int index = dp[m][n];
    char lcs[100]; // to store LCS string
    lcs[index] = '\0'; // null-terminate the string

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; // Put character in result
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "Length of LCS is " << dp[m][n] << endl;
    cout << "LCS is " << lcs << endl;

    return 0;
}
