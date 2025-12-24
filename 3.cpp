#include <iostream>
using namespace std;

int main() {
    int x, max;
    cin >> max;

    for (int i = 1; i < 7; i++) {
        cin >> x;
        if (x > max)
            max = x;
    }

    cout << max;
    return 0;
}
