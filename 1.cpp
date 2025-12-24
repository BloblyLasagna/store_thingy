#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 100000 || n > 999999) {
        cout << "Error";
        return 0;
    }

    int a = n / 100000;
    int b = n / 10000 % 10;
    int c = n / 1000 % 10;
    int d = n / 100 % 10;
    int e = n / 10 % 10;
    int f = n % 10;

    if (a + b + c == d + e + f)
        cout << "Lucky";
    else
        cout << "Not lucky";

    return 0;
}
