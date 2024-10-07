#include <iostream>
using namespace std;

int path(int cr, int cc, int er, int ec) {
    int rightways = 0;
    int downways = 0;
    if (cr == er && cc == ec) return 1;
    if (cr == er) {
        rightways += path(cr, cc + 1, er, ec);
    }
    if (cc == ec) {
        downways += path(cr + 1, cc, er, ec);
    }
    if (cr < er && cc < ec) {
        rightways += path(cr, cc + 1, er, ec);
        downways += path(cr + 1, cc, er, ec);
    }
    return rightways + downways;
}

int main() {
    int a, b;
    cout << "Enter the value of row: ";
    cin >> a;
    cout << "Enter the value of column: ";
    cin >> b;
    int ans = path(1, 1, a, b);
    cout << ans << endl;
    return 0;
}
