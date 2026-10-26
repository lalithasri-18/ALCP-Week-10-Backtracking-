#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<char> > a;
vector<vector<int> > visited;
string word;

bool search(int i, int j, int k) {
    if (k == (int)word.length())
        return true;

    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;

    if (visited[i][j] == 1 || a[i][j] != word[k])
        return false;

    visited[i][j] = 1;

    bool found =
        search(i + 1, j, k + 1) ||
        search(i - 1, j, k + 1) ||
        search(i, j + 1, k + 1) ||
        search(i, j - 1, k + 1);

    visited[i][j] = 0;

    return found;
}

int main() {
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    if (n <= 0 || m <= 0) {
        cout << "Invalid dimensions";
        return 0;
    }

    a.resize(n, vector<char>(m));
    visited.resize(n, vector<int>(m, 0));

    cout << "Enter matrix characters:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter word: ";
    cin >> word;

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (search(i, j, 0)) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (found)
        cout << "Word found";
    else
        cout << "Word not found";

    return 0;
}
