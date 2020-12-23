#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;

int concat(const vector<int>& lengths) {
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i = 0; i < lengths.size(); ++i)
    pq.push(lengths[i]);
  int ret = 0;
  while(pq.size() > 1) {
    int min1 = pq.top(); pq.pop();
    int min2 = pq.top(); pq.pop();
    pq.push(min1 + min2);
    ret += min1 + min2;
  }
  return ret;
}

void solve() {
  cin >> n;
  vector<int> lengths(n, 0);
  for (int i = 0; i < n; ++i)
    cin >> lengths[i];
  cout << concat(lengths) << "\n";
}

// void solve() {
//   cin >> n;
//   vector<int> length(n, 0);
//   for (int i = 0; i < n; ++i)
//     cin >> length[i];
// 
//   int answer = 0;
//   while(length.size() > 1) {
//     sort(length.begin(), length.end());
//     int sum = length[0] + length[1];
//     length.erase(length.begin(), length.begin()+2);
//     length.push_back(sum);
//     answer += sum;
//   }
//   cout << answer << "\n";
// }

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
