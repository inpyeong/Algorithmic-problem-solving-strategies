#include <iostream>

using namespace std;

long long L = 2000000000;
long long games, won;

int calcRatio(long long b, long long a) {
    return (a * 100) / b;
}

int solve() {
    cin >> games >> won;
    // 불가능하면 -1 출력
    if(calcRatio(games+L, won+L) == calcRatio(games, won))
        return -1;

    long long lo = 0, hi = L;
    while(lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if(calcRatio(games + mid, won + mid) == calcRatio(games, won))
            lo = mid;
        else
            hi = mid;
    }
    return hi;
}

int main() {
    int t;
    cin >> t;
    while(t--) 
        cout << solve() << "\n";
}