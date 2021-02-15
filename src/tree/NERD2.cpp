#include <iostream>
#include <map>

using namespace std;

int N;

// 현재 다른 점에 지배당하지 않는 점들에 지배당하는지 확인한다.
// coords[x] = y;
map<int, int> coords;
// 새로운 점 (x, y)가 기존의 다른 점들에 지배당하는지 확인한다.
bool isDominated(int x, int y) {
    // x보다 오른쪽에 있는 점 중 가장 왼쪽에 있는 점을 찾는다.
    map<int, int>::iterator it = coords.lower_bound(x);
    // 그런 점이 없으면 (x, y)는 지배당하지 않는다.
    if(it == coords.end()) return false;
    // 이 점은 x보다 오른쪽에 있는 점 중 가장 위에 있는 점이므로,
    // (x, y)가 어느 점에 지배되려면 이 점에도 지배되어야 한다.
    return y < it->second;
}

void removeDominated(int x, int y) {
    map<int, int>:: iterator it = coords.lower_bound(x);
    if(it == coords.begin()) return;
    --it;
    while(true) {
        // it가 표시하는 점이 (x, y)에 지배되지 않는다면 곧장 종료
        if(it->second > y) break;
        if(it == coords.begin()) {
            coords.erase(it);
            break;
        } 
        else {
            map<int, int>:: iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if(isDominated(x, y)) return coords.size();
    removeDominated(x, y);
    coords[x] = y;
    return coords.size();
}

void solve() {
    cin >> N;
    int answer = 0;
    coords.clear();
    for(int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        answer += registered(x, y);
    }
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}