#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int n = 10;
    int a[n];
    int l, r, sum = 0;

    srand(time(0));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Enter range: ";
    cin >> l >> r;

    for (int i = 0; i < n; i++) {
        if (a[i] >= l && a[i] <= r) {
            sum += a[i];
        }
    }

    cout << "Sum = " << sum << endl;

    return 0;
}
