#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 8

int n;
double dist[MAX][MAX];

double shortestPath(vector<int> &path, vector<bool> &visited, double currentLength)
{
  // 기저 사례:모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다
  if (path.size() == n)
    return currentLength;

  double ret = numeric_limits<double>::max();
  for (int next = 0; next < n; next++)
  {
    if (visited[next])
      continue;
    int here = path.back();
    path.push_back(next);
    visited[next] = true;

    double candidate = shortestPath(path, visited, currentLength + dist[here][next]);
    ret = min(ret, candidate);
    visited[next] = false;
    path.pop_back();
  }
  return ret;
}

void solve()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
      scanf("%lf", &dist[i][j]);
    }

  double answer = numeric_limits<double>::max();
  double result;
  for (int i = 0; i < n; ++i)
  {
    vector<int> path(1, i);
    vector<bool> visited(n, false);
    visited[i] = true;
    result = shortestPath(path, visited, 0.0000000000);
    if (answer > result) answer = result;
  }

  printf("%.10f\n", answer);
}

int main(void)
{
  int T;
  scanf("%d", &T);
  while (T--)
    solve();
}