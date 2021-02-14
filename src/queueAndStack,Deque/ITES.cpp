#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int K, N;

struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};

int countRanges() {
    RNG rng;
    queue<int> range; 
    int ret = 0, rangeSum = 0;
    for(int i = 0; i < N; ++i) {
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        while(rangeSum > K) {
            rangeSum -= range.front();
            range.pop();
        }
        if(rangeSum == K) ret++;
    }
    return ret;
}

vector<unsigned> makeSignals() {
    vector<unsigned> ret(N+1);
    unsigned seed = 1983;
    for(int i = 0; i <= N; ++i) {
        ret[i] = (int)(seed % 10000 + 1);
        seed = (seed * 214013u + 2531011u);
    }
    return ret;
}

int optimized(const vector<unsigned>& signals) {
    int ret = 0, tail = 0, rangeSum = signals[0];
    for(int head = 0; head < signals.size(); ++head) {
        while(rangeSum < K && tail + 1 < signals.size())
            rangeSum += signals[++tail];
        if(rangeSum == K) ret++;
        rangeSum -= signals[head];
    }
    return ret;
}



void solve() {
    cin >> K >> N;
    // vector<unsigned> signals = makeSignals();
    // cout << optimized(signals) << endl;
    cout << countRanges() << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}