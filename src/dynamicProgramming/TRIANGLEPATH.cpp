#include <iostream>
#include <cstring>

using namespace std;

int n;
int triangle[101][101];
int cache[101][101];

int memoized(int h, int r) {
  if (h > n || r > n) return -1;
  
  int& ret = cache[h][r];
  if (ret != -1) return ret;

  if (h == n) return ret = triangle[n][r];
  
  int down = triangle[h][r] + memoized(h + 1, r);
  int downRight = triangle[h][r] + memoized(h + 1, r + 1);
  
  return ret = down >= downRight ? down : downRight;
}

void solve() {
  memset(cache, -1, sizeof(cache));
  
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= i; ++j) cin >> triangle[i][j];
  
  cout << memoized(0, 0) << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}