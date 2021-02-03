#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int TM = 1000*1000*10;
int divisorNum, lo, hi;
int minFactor[TM+1];
int minFactorPower[TM+1];
int factors[TM+1];

void eratosthenes() {
    minFactor[0] = minFactor[1] = -1;
    for(int i = 2; i <= TM; ++i)
        minFactor[i] = i;
    int sqrtn = int(sqrt(TM));
    for(int i = 2; i <= sqrtn; ++i) {
        if(minFactor[i] == i) {
            for(int j = i*i; j <= TM; j += i)
                if(minFactor[j] == j)
                    minFactor[j] = i;
        }
    }
}

void getFactorsSmart() {
    factors[1] = 1;
    for(int n = 2; n <= TM; ++n) {
        if(minFactor[n] == n) {
            minFactorPower[n] = 1;
            factors[n] = 2;
        }
        else {
            int p = minFactor[n];
            int m = n / p;
            if(p != minFactor[m]) 
                minFactorPower[n] = 1;
            else
                minFactorPower[n] = minFactorPower[m] + 1;
            int a = minFactorPower[n];
            factors[n] = (factors[m] / a) * (a + 1);
        }
    }
}

void solve() {
    cin >> divisorNum >> lo >> hi;
    int answer = 0;
    for(int i = lo; i <= hi; ++i)
        if(factors[i] == divisorNum)
            answer++;
    cout << answer << "\n";
}

int main() {
    int t;
    cin >> t;
    eratosthenes();
    getFactorsSmart();
    while(t--) solve();

}