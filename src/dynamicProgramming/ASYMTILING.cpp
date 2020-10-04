#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int n;
int cache[101], asymCache[101];

int tiling(int width) {
  if(width <= 1) return 1;

  int& ret = cache[width];
  if(ret != -1) return ret;

  return ret = (tiling(width-2) + tiling(width-1)) % MOD;
}

int asymmetric(int width) {
  if(width % 2 == 1)
    return (tiling(width) - tiling(width / 2) + MOD) % MOD;
  int ret = tiling(width);
  ret = (ret - tiling(width / 2) + MOD) % MOD;
  ret = (ret - tiling((width - 1) / 2) + MOD) % MOD;
  return ret;
}

void solve() {
  memset(cache, -1, sizeof(cache));
  cin >> n;
  cout << asymmetric(n) << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}
