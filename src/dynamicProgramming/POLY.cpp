#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10000000;
int n;
int cache[101][101];

int poly(int n, int first) {
  if(n == first) return 1;

  int& ret = cache[n][first];
  if(ret != -1) return ret;

  ret = 0;
  for(int second = 1; second <= n - first; ++second) {
    int add = (second + first - 1) * poly(n - first, second);
    add %= MOD;
    ret += add;
    ret %= MOD;
  }
  return ret;
}

void solve() {
  memset(cache, -1, sizeof(cache));
  cin >> n;
  int answer = 0;
  for(int first = 1; first <= n; ++first) {
    answer += poly(n, first);
    answer %= MOD;
  }
  cout << answer << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}
