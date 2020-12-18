#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, capacity;
int volume[100], need[100];
int cache[1001][100];
string name[100];

int pack(int capacity, int item) {
  // 기저사례
  if(item == n) return 0;
  int& ret = cache[capacity][item];
  if(ret != -1) return ret;
  // 물건을 담지 않는 경우
  ret = pack(capacity, item+1);
  // 물건을 담을 경우
  if(capacity >= volume[item])
    ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
  return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) {
  if(item == n) return;
  // 물건을 담지 않는 경우
  if(pack(capacity, item) == pack(capacity, item+1))
    reconstruct(capacity, item+1, picked);
  // 물건을 담는 경우
  else {
    picked.push_back(name[item]);
    reconstruct(capacity - volume[item], item+1, picked);
  }
}

void solve() {
  memset(cache, -1, sizeof(cache));
  cin >> n >> capacity;
  for(int i = 0; i < n; ++i)
    cin >> name[i] >> volume[i] >> need[i];

  vector<string> picked;
  reconstruct(capacity, 0, picked);
  cout << pack(capacity, 0) << " " << picked.size() << "\n";
  for(int i = 0; i < picked.size(); ++i) 
    cout << picked[i] << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
