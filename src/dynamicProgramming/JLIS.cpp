#include <iostream>
#include <cstring>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int n, m, A[100], B[100];
int cache[101][101];

int JLIS(int indexA, int indexB) {
  int& ret = cache[indexA+1][indexB+1];
  if(ret != -1) return ret;


  long long a = indexA == -1 ? NEGINF : A[indexA];
  long long b = indexB == -1 ? NEGINF : B[indexB];
  long long maxElement = max(a, b);

  ret = 2;
  for(int nextA = indexA + 1; nextA < n; ++nextA) 
    if(maxElement < A[nextA])
      ret = max(ret, JLIS(nextA, indexB) + 1);
  for(int nextB = indexB + 1; nextB < m; ++nextB) 
    if(maxElement < B[nextB])
      ret = max(ret, JLIS(indexA, nextB) + 1);
  return ret;
}

void solve() {
  memset(cache, -1, sizeof(cache));
  cin >> n >> m;
  for(int i = 0; i < n; ++i) 
    cin >> A[i];
  for(int i = 0; i < m; ++i) 
    cin >> B[i];    

  cout << JLIS(-1, -1) << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) solve();
}