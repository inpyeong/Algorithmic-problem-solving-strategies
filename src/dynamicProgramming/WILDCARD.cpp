#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, n;
string W, S;
int cache[101][101];
vector<string> answer;

int memoized(int w, int s) {
  int& ret = cache[w][s];
  if (ret != -1) return ret;
  
  while (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) {
    ++w;
    ++s;
  }

  if (w == W.size()) return ret = (s == S.size());

  if (W[w] == '*') {
    for (int skip = 0; skip+s <= S.size(); ++skip)
      if (memoized(w+1, s+skip)) return ret = 1;
  }
  
  return ret = 0;
}

void solve() {

  cin >> W >> n;
  for(int i = 0; i < n; ++i) {
    cin >> S;
    memset(cache, -1, sizeof(cache)); 
    if (memoized(0, 0)) answer.push_back(S);
  }

  if (T == 0) {
    sort(answer.begin(), answer.end());
    for(int i = 0; i < answer.size(); ++i) 
      cout << answer[i] << "\n";    
  }
}

int main() {
  cin >> T;
  while (T--) solve();
}