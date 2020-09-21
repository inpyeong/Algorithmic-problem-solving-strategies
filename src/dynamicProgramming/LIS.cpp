#include <iostream>
#include <cstring>

using namespace std;

int n;
int cache[100], S[100];

int memoized(int start) {
  int& ret = cache[start];
  if (ret != -1) return ret;

  ret = 1;
  for(int next = start; next < n; ++next) {
    if(S[start] < S[next])
      ret = max(ret, memoized(next) + 1);
  }
  return ret;
}

void solve() {
  memset(cache, -1, sizeof(cache));

  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> S[i];
  
  int maxLen = 0;
  for(int begin = 0; begin < n; ++begin) {
    maxLen = max(maxLen, memoized(begin));
  }
  cout << maxLen << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}