#include <iostream>
#include <vector>
using namespace std;

int n, target;
vector<int> a;

bool subset(int i, int sum) {
    if (sum == target)
        return true;

    if (i == n || sum > target)
        return false;

    if (subset(i + 1, sum + a[i]))
        return true;

    if (subset(i + 1, sum))
        return true;

    return false;
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid size";
        return 0;
    }

    a.resize(n);

    cout << "Enter positive elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target: ";
    cin >> target;

    if (subset(0, 0))
        cout << "Subset exists";
    else
        cout << "Subset does not exist";

    return 0;
}
