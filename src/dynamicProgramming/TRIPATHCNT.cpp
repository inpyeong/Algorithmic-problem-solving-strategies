#include <iostream>
#include <cstring>

using namespace std;

int n, triangle[100][100];
int cache[100][100];
int cntCache[100][100];

int memoized(int h, int r) {
  int& ret = cache[h][r];
  if (ret != -1) return ret;

  if (h == n-1) return ret = triangle[h][r];
  
  int down = triangle[h][r] + memoized(h + 1, r);
  int downRight = triangle[h][r] + memoized(h + 1, r + 1);
  
  return ret = down >= downRight ? down : downRight;
}

int cntMemoized(int h, int r) {
  int& ret = cntCache[h][r];
  if(ret != -1) return ret;

  if(h == n-1) return 1;

  ret = 0;
  if(cache[h+1][r] >= cache[h+1][r+1]) ret += cntMemoized(h+1, r);
  if(cache[h+1][r] <= cache[h+1][r+1]) ret += cntMemoized(h+1, r+1);
  return ret;
}

void solve() {
  memset(cache, -1, sizeof(cache));
  memset(cntCache, -1, sizeof(cntCache));

  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j <= i; ++j)
      cin >> triangle[i][j];

  memoized(0, 0);
  cout << cntMemoized(0, 0) << "\n";


}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}
