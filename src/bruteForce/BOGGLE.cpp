#include <cstdio>
#include <cstring>

char board[5][5];
char word[10];
bool v[5][5][10];

int dx[] = { 0, 1, 1,  1,  0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1,  0,  1 };

bool isInBoard(int x, int y) {
  bool checkX = false, checkY = false;
  if ((x >= 0) && (x <= 4)) checkX = true;
  if ((y >= 0) && (y <= 4)) checkY = true;
  return checkX && checkY;
}

bool hasWord(int x, int y, int idx) {
  v[x][y][idx] = 1;
  if (board[x][y] != word[idx]) return 0;
  if (idx == strlen(word) - 1) return 1;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (isInBoard(nx, ny)) {
      if (v[nx][ny][idx + 1]) continue;
      if (hasWord(nx, ny, idx + 1)) return 1;
    }
  }
  return 0;
}

void solve() {
  for (int i = 0; i < 5; i++) scanf("%s", board[i]);
  int n;
  scanf("%d", &n);
  for (int t = 0; t < n; t++) {
    memset(v, 0, sizeof(v));
    scanf("%s", word);
    printf("%s ", word);
    bool res = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (hasWord(i, j, 0)) res = 1;
        if (res) break;
      }
      if (res) break;
    }
    if (res) puts("YES");
    else puts("NO");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
