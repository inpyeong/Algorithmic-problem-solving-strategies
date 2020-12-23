#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void solve() {
  cin >> n;
  vector<int> length(n, 0);
  for (int i = 0; i < n; ++i)
    cin >> length[i];

  int answer = 0;
  while(length.size() > 1) {
    sort(length.begin(), length.end());
    int sum = length[0] + length[1];
    length.erase(length.begin(), length.begin()+2);
    length.push_back(sum);
    answer += sum;
  }
  cout << answer << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
