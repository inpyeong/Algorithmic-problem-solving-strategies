#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int n;
int board[100][100];
int cache[100][100];

int jump(int y, int x) {
  // 기저 사례 처리
  if (y >= n || x >= n) return 0;
  if (y == n - 1 && x == n - 1) return 1;

  int& ret = cache[y][x];
  if (ret != -1) return ret;

  int jumpSize = board[y][x];
  return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

void solve() {
  memset(board, 0, sizeof(board));
  memset(cache, -1, sizeof(cache));
  
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      scanf("%d", &board[i][j]);
  }
  if (jump(0, 0)) printf("YES");
  else printf("NO");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}