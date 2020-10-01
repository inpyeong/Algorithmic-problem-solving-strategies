#include <iostream>
#include <cstring>

using namespace std;

int n;
int cache[101];

int tiling(int width) {
  if(width <= 1) return 1;

  int& ret = cache[width];
  if(ret != -1) return ret;

  return ret = (tiling(width-2) + tiling(width-1)) % 1000000007;
}

void solve() {
  memset(cache, -1, sizeof(cache));
  cin >> n;

  // cache[1] = 1;
  // cache[2] = 2;
  // for(int i = 3; i <= 100; ++i) { 
  //   cache[i] = cache[i-1] + cache[i-2];
  //   cache[i] %= 1000000007;
  // }

  // cout << cache[n] << "\n";
  cout << tiling(n) << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}
