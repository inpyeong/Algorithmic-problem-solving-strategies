#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> h;

int divideAndConquer(int left, int right) {
  // 기저사례: 판자가 1개일 때
  if (left == right) return h[left];

  // 먼저 두 구간으로 나누어 생각한다.
  int mid = (left + right) / 2;
  // 분할문제 각개격파
  int ret = max(divideAndConquer(left, mid), divideAndConquer(mid + 1, right));

  // 두 부분을 걸치는 직사각형 중 가장 큰 것을 찾는 로직
  int lo = mid, hi = mid + 1;
  // 판자가 2개인 경우 먼저 계산
  int height = min(h[lo], h[hi]);
  ret = max(ret, 2 * height);

  // 직사각형의 크기를 증가시키면서, 가장 큰 직사각형을 찾는다.
  while (left < lo || hi < right) {
    if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
      ++hi;
      height = min(height, h[hi]);
    }
    else {
      --lo;
      height = min(height, h[lo]);
    }
    ret = max(ret, (hi - lo + 1) * height);
  }
  return ret;
}

void solve() {
  scanf("%d", &n);
  h.clear();
  for (int i = 0; i < n; ++i) {
    int height;
    scanf("%d", &height);
    h.push_back(height);
  }
  printf("%d", divideAndConquer(0, n - 1));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}