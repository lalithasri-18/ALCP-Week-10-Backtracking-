#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n;
vector<int> col;

bool safe(int row, int c) {
    for (int i = 0; i < row; i++) {
        if (col[i] == c ||
            abs(col[i] - c) == abs(i - row))
            return false;
    }
    return true;
}

bool solve(int row) {
    if (row == n)
        return true;

    for (int c = 0; c < n; c++) {
        if (safe(row, c)) {
            col[row] = c;

            if (solve(row + 1))
                return true;

            col[row] = -1;
        }
    }
    return false;
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid N";
        return 0;
    }

    col.resize(n, -1);

    if (solve(0)) {
        cout << "Solution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (col[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}
