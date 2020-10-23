#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int n, regionCnt;
int dx[] = { 0, 1,  0, -1 };
int dy[] = { 1, 0, -1,  0 };

string solve() {
    cin >> n;

    vector<vector<int> > matrix(n, vector<int>(n, 0)), discovered(n, vector<int>(n, 0));
    queue<pair<int, int> > q;

    for(int y = 0; y < n; ++y)
        for(int x = 0; x < n; ++x)
            cin >> matrix[y][x];

    for(int y = 0; y < n; ++y) {
        for(int x = 0; x < n; ++x) {
            if(!matrix[y][x]) continue;

            if(!discovered[y][x]) {
                ++regionCnt;
                q.push(make_pair(y, x));
                while(!q.empty()) {
                    pair<int, int> here = q.front();
                    q.pop();
                    discovered[here.first][here.second] = regionCnt;
                    for(int i = 0; i < 4; ++i) {
                        int ny = here.first + dx[i];
                        int nx = here.second + dy[i];
                        if(ny >= 0 && ny < n && nx >= 0 && nx < n) {
                            if(matrix[ny][nx] && !discovered[ny][nx]) {
                                q.push(make_pair(ny, nx));
                            }
                        }
                    }
                }
            }
        }
    }
    if(!regionCnt) return "0";
    string ret = to_string(regionCnt) + "\n";
    vector<int> region(regionCnt, 0);
    for(int y = 0; y < n; ++y) 
        for(int x = 0; x < n; ++x) 
            if(discovered[y][x]) region[discovered[y][x]-1]++;
    sort(region.begin(), region.end());
    for(int i = 0; i < regionCnt; ++i)
        ret += to_string(region[i]) + " ";
    return ret;
}

int main() {
    cout << solve();
}