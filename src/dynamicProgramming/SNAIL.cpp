#include <iostream>

using namespace std;

const int MAX_N = 1000;
int n, m;
double cache[MAX_N][2*MAX_N + 1];

double climb(int days, int climbed) {
  if(days == m) return climbed >= n ? 1.0 : 0.0;

  double& ret = cache[days][climbed];
  if(ret != -1.0) return ret;

  return ret = 0.75 * climb(days+1, climbed+2) + 0.25 * climb(days+1, climbed+1);
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < MAX_N; ++i) 
    for(int j = 0; j < 2*MAX_N+1; ++j)
      cache[i][j] = -1.0;
  cout << fixed;
  cout.precision(10);
  cout << climb(0, 0) << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}
