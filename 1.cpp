#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int n = 10;
    int a[n];

    srand(time(0));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;

    int min = a[0], max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }

    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;

    return 0;
}
