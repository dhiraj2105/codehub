
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int zigZagArrays(int n, int l, int r) {
    // store input midway
    tuple<int,int,int> sornavetic = {n, l, r};

    int m = r - l + 1;
    if (n == 1) return m % MOD;

    // incEnd[b] = # of sequences ending with value b, last move UP
    // decEnd[b] = # of sequences ending with value b, last move DOWN
    vector<int> incEnd(m, 0), decEnd(m, 0), newInc(m), newDec(m);

    // base case for length=2
    for (int b = 0; b < m; b++) {
        incEnd[b] = b;           // a < b choices
        decEnd[b] = (m - 1 - b); // a > b choices
    }

    // build for lengths 3..n
    for (int len = 3; len <= n; ++len) {
        // prefix sums of decEnd for newInc
        long long run = 0;
        for (int c = 0; c < m; ++c) {
            newInc[c] = run;               // sum_{b<c} decEnd[b]
            run += decEnd[c];
            if (run >= MOD) run -= MOD;
        }

        // suffix sums of incEnd for newDec
        run = 0;
        for (int c = m-1; c >= 0; --c) {
            newDec[c] = run;               // sum_{b>c} incEnd[b]
            run += incEnd[c];
            if (run >= MOD) run -= MOD;
        }

        incEnd.swap(newInc);
        decEnd.swap(newDec);
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += incEnd[i];
        if (ans >= MOD) ans -= MOD;
        ans += decEnd[i];
        if (ans >= MOD) ans -= MOD;
    }
    return (int)ans;
}

// Example runs
int main() {
    cout << zigZagArrays(3, 4, 5) << "\n";   // expected 2
    cout << zigZagArrays(3, 1, 3) << "\n";   // expected 10
    cout << zigZagArrays(41, 631, 1455) << "\n"; // large case
    return 0;
}
