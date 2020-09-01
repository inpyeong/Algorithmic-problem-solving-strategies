#include <cstdio>
#include <cstring>

#define MIN(a, b) ((a < b) ? a : b)

const int NUMOFWATCHES = 16, NUMOFSWITCHES = 10, INF = 9999;
const char switches[NUMOFSWITCHES][NUMOFWATCHES+1] = {
  "xxx.............",
  "...x...x.x.x....",
  "....x.....x...xx",
  "x...xxxx........",
  "......xxx.x.x...",
  "x.x...........xx",
  "...x..........xx",
  "....xx.x......xx",
  ".xxxxx..........",
  "...xxx...x...x.."
};
int watches[16];

int areAligned() {
  bool ret = true;
  for (int i = 0; i < NUMOFWATCHES; ++i)
    if (watches[i] != 12) {
      ret = false;
      break;
    }
  return ret;
}

// swtch번 스위치를 누른다.
void push(int swtch) {
  for (int i = 0; i < NUMOFWATCHES; ++i)
    if (switches[swtch][i] == 'x') {
      watches[i] += 3;
      if (watches[i] == 15) watches[i] = 3;
    }
}

// swtch: 이번에 누를 스위치 번호
int bruteForce(int swtch) {
  if (swtch == NUMOFSWITCHES) return areAligned() ? 0 : INF;

  // 해당 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다.
  int ret = INF;
  for (int i = 0; i < 4; ++i) {
    ret = MIN(ret, i + bruteForce(swtch + 1));
    push(swtch);
  }
  // push가 4번 호출됐기 때문에 시계는 초기 상태와 같다.
  return ret;
}

void solve() {
  for (int i = 0; i < NUMOFWATCHES; ++i) scanf("%d", &watches[i]);
  printf("%d", bruteForce(0));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}