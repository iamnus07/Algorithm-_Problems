#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    int n = 4; // Number of matrices = n - 1
    int p[] = {2, 3, 5, 7}; // Matrix dimensions

    int m[4][4]; // DP table

    // Initialize diagonal to 0 (cost of multiplying one matrix)
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // l is chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    // Print minimum multiplication cost
    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;

    // Print DP table (non-zero values)
    cout << "\nMCM Table (non-zero values):\n";
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i > j)
                cout << setw(6) << " ";
            else if (i == j)
                cout << setw(6) << "0";
            else
                cout << setw(6) << m[i][j];
        }
        cout << endl;
    }

    return 0;
}
