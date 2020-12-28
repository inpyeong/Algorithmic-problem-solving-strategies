#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int boardH, boardW;
vector<string> board;
vector<vector<pair<int, int> > > rotations;
int blockSize;
int covered[10][10];
int best;

vector<string> rotate(const vector<string>& arr) {
  vector<string> ret(arr[0].size(), string(arr.size(), ' '));
  for(int i = 0; i < arr.size(); ++i)
    for(int j = 0; j < arr[0].size(); ++j)
      ret[j][arr.size()-i-1] = arr[i][j];
  return ret;
}

void generateRotations(vector<string> block) {
  rotations.clear();
  rotations.resize(4);
  for(int rot = 0; rot < 4; ++rot) {
    int originY = -1, originX = -1;
    for(int i = 0; i < block.size(); ++i)
      for(int j = 0; j < block[i].size(); ++j)
        if(block[i][j] == '#') {
          if(originY == -1) {
            // 가장 윗줄 맨 왼쪽에 있는 칸이 '원점'이다.
            originY = i;
            originX = j;
          }
          rotations[rot].push_back(make_pair(i - originY, j - originX));
        }
    block = rotate(block);
  }
  // 네 가지 회전 형태 중 중복이 있을 경우 이를 제거한다.
  sort(rotations.begin(), rotations.end());
  rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
  // 블록이 몇 칸 짜리인지 저장해 둔다.
  blockSize = rotations[0].size();
}

bool set(int y, int x, const vector<pair<int, int> >& block, int delta) {
  bool ret = true;
  for(int i = 0; i < block.size(); ++i) {
    int ny = y + block[i].first;
    int nx = x + block[i].second;
    if(ny >= 0 && ny < boardH && nx >= 0 && nx < boardW) {
      covered[ny][nx] += delta;
      ret = ret && (covered[ny][nx] == 1);
    }
    else ret = false;
  }
  return ret;
}

// 5
int blockPrune(int placed) {
  int cnt = 0;
  for(int i = 0; i < boardH; ++i)
    for(int j = 0; j < boardW; ++j)
      cnt += !(covered[i][j]) ? 1 : 0;
  return ((cnt / blockSize) + placed <= best);
}

void search(int placed) {
  if(blockPrune(placed))
    return;
  int y = -1, x = -1;
  for(int i = 0; i < boardH; ++i) {
    for(int j = 0; j < boardW; ++j)
      if(covered[i][j] == 0) {
        y = i;
        x = j;
        break;
      }
    if(y != -1) break;
  }
  // 기저사례: 게임판의 모든 칸을 처리한 경우
  if(y == -1) {
    best = max(best, placed);
    return;
  }
  // 이 칸을 덮는다.
  for(int i = 0; i < rotations.size(); ++i) {
    if(set(y, x, rotations[i], 1))
      search(placed+1);
    set(y, x, rotations[i], -1);
  }
  // 이 칸을 덮지 않고 '막아'둔다.
  covered[y][x] = 1;
  search(placed);
  covered[y][x] = 0;
}

int solve() {
  best = 0;
  for(int i = 0; i < boardH; ++i) {
    for(int j = 0; j < boardW; ++j)
      covered[i][j] = (board[i][j] == '#' ? 1 : 0);
  }
  search(0);
  return best;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    board.clear();
    vector<string> block;
    int blockH, blockW;
    cin >> boardH >> boardW >> blockH >> blockW;
    for(int i = 0; i < boardH; ++i) {
      string temp;
      cin >> temp;
      board.push_back(temp);
    }
    for(int i = 0; i < blockH; ++i) {
      string temp;
      cin >> temp;
      block.push_back(temp);
    }
    generateRotations(block);
    cout << solve() << "\n";
  };
  return 0;
}
