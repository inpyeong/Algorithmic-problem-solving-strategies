#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321, MAXN = 12;
int n, k, m, l;
int prerequisite[MAXN];
int classes[10];
int cache[10][1<<MAXN];

int bitCount(int n) {
    if(n == 0) return 0;
    return n % 2 + bitCount(n / 2);
}

// 이번 학기가 semester이고, 지금까지 들은 과목의 집합이 taken일 때
// k개 이상의 과목을 모두 들으려면 몇 학기나 더 있어야 하는가?
// 불가능한 경우 INF를 반환한다.
int graduate(int semester, int taken) {
    if(bitCount(taken) == n) return 0;
    if(semester == m) return INF;

    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;

    // 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾는다.
    int canTake = (classes[semester] & ~taken);
    // 선수 과목을 다 듣지 않은 과목들을 걸러낸다.
    for(int i = 0; i < n; ++i)
        if((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
            canTake &= ~(1 << i);
    
    // 이 집합의 모든 부분집합을 순회한다.
    for(int take = canTake; take > 0; take = ((take - 1) & canTake)) {
        if(bitCount(take) > l) continue;
        ret = min(ret, graduate(semester+1, taken | take) + 1);
    }
    // 이번 학기에 아무 것도 듣지 않는 경우
    ret = min(ret, graduate(semester+1, taken));
    return ret;
}

void solve() {
    cin >> n >> k >> m >> l;
    memset(prerequisite, 0, sizeof(prerequisite));
    memset(classes, 0, sizeof(classes));
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n; ++i) {
        int preNum;
        cin >> preNum;
        for(int j = 0; j < preNum; ++j) {
            int subject;
            cin >> subject;
            prerequisite[i] |= (1 << subject);
        }
    }
    for(int i = 0; i < m; ++i) {
        int classNum;
        cin >> classNum;
        for(int j = 0; j < classNum; ++j) {
            int subject;
            cin >> subject;
            classes[i] |= (1 << subject);
        }
    }
    int answer = graduate(0, 0);
    if(answer == INF)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << answer << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}