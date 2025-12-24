#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1000 || n > 9999) {
        cout << "Error";
        return 0;
    }

    int a = n / 1000;
    int b = n / 100 % 10;
    int c = n / 10 % 10;
    int d = n % 10;

    int result = b * 1000 + a * 100 + d * 10 + c;
    cout << result;

    return 0;
}
