#include <iostream>

using namespace std;

int main() {
    int profit[12];
    int l, r;

    for (int i = 0; i < 12; i++) {
        cout << "Profit for month " << i + 1 << ": ";
        cin >> profit[i];
    }

    cout << "Enter range of months (1-12): ";
    cin >> l >> r;
    l--; r--;

    int min = profit[l], max = profit[l];
    int minMonth = l, maxMonth = l;

    for (int i = l + 1; i <= r; i++) {
        if (profit[i] < min) {
            min = profit[i];
            minMonth = i;
        }
        if (profit[i] > max) {
            max = profit[i];
            maxMonth = i;
        }
    }

    cout << "Max profit: " << max << " (month " << maxMonth + 1 << ")" << endl;
    cout << "Min profit: " << min << " (month " << minMonth + 1 << ")" << endl;

    return 0;
}
