#include <iostream>
#include <cstring>

using namespace std;

int n;
long long cache[101];

void solve() {
  memset(cache, 0, sizeof(cache));
  cin >> n;

  cache[1] = 1;
  cache[2] = 2;
  for(int i = 3; i <= 100; ++i) { 
    cache[i] = cache[i-1] + cache[i-2];
    cache[i] %= 1000000007;
  }

  cout << cache[n] << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}
