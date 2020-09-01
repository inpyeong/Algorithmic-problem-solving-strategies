#include <cstdio>
#include <cstring>
using namespace std;

int numOfPeople, numOfFriends;
bool isFriend[10][10];
bool hasTeam[10];

int bruteForce() {
  int now = -1;
  for (int i = 0; i < numOfPeople; i++) {
    if (!hasTeam[i]) {
      now = i;
      break;
    }
  }

  // Base case
  if (now == -1) return 1;
  
  int ret = 0;
  for (int i = now + 1; i < numOfPeople; i++) {
    if (!hasTeam[i] && isFriend[now][i] && isFriend[i][now]) {
      hasTeam[now] = hasTeam[i] = true;
      ret += bruteForce();
      hasTeam[now] = hasTeam[i] = false;
    }
  }
  return ret;
}

void solve() {
  memset(isFriend, false, sizeof(isFriend));
  memset(hasTeam, false, sizeof(hasTeam));

  scanf("%d %d", &numOfPeople, &numOfFriends);
  for (int i = 0; i < numOfFriends; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    isFriend[x][y] = true;
    isFriend[y][x] = true;
  }

  printf("%d\n", bruteForce());
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}