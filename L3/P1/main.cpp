#include <iostream>
#include "Math.h"

void useMathExample() {
    int ia = 3, ib = 5, ic = 12;
    double da = 3.12, db = 5.243, dc = 12.09;
    int n = 5, la = 12, lb = 7, lc = 2, ld = 74, le = 142;
    char ca[] = "ana", cb[] = " are";
    Math math;
    std::cout << math.Add(ia, ib) << '\n';
    std::cout << math.Add(ia, ib, ic) << '\n';
    std::cout << math.Add(da, db) << '\n';
    std::cout << math.Add(da, db, dc) << '\n';
    std::cout << math.Mul(ia, ib) << '\n';
    std::cout << math.Mul(ia, ib, ic) << '\n';
    std::cout << math.Mul(da, db) << '\n';
    std::cout << math.Mul(da, db, dc) << '\n';
    std::cout << math.Add(n, la, lb, lc, ld, le) << '\n';
    std::cout << math.Add(ca, cb);
}

int main() {
    useMathExample();
    return 0;
}
