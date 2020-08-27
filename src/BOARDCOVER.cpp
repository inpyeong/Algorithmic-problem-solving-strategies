#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int height, width;
vector <vector <int>> board(20, vector<int>(20, 0));

const int coverType[4][3][2] = {
  { { 0, 0 }, { 1, 0 }, { 0, 1 } },
  { { 0, 0 }, { 0, 1 }, { 1, 1 } },
  { { 0, 0 }, { 1, 0 }, { 1, 1 } },
  { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

bool set(vector <vector <int>> &board, int y, int x, int type, int delta) {
  bool ok = true;
  for (int i = 0; i < 3; ++i) {
    const int ny = y + coverType[type][i][0];
    const int nx = x + coverType[type][i][1];
    if (ny < 0 || ny >= height || nx < 0 || nx >= width)
      ok = false;
    else if ((board[ny][nx] += delta) > 1)
      ok = false;
  }
  return ok;
}

int cover(vector <vector <int>> &board) {
  int y = -1, x = -1;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j)
      if (board[i][j] == 0) {
        y = i;
        x = j;
        break;
      }
    if (y != -1) break;
  }

  if (y == -1) return 1;
  int ret = 0;
  for (int type = 0; type < 4; ++type) {
    if (set(board, y, x, type, 1))
      ret += cover(board);
    set(board, y, x, type, -1);
  }
  return ret;
}

void solve() {
  // fill(board.begin(), board.end(), 0);
  height = width = 0;

  scanf("%d %d", &height, &width);
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      char c;
      scanf(" %c", &c);
      if (c == '#') board[h][w] = 1;
      else board[h][w] = 0;
    }
  }
  printf("%d", cover(board));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
