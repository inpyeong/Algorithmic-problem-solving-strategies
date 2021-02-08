#include <iostream>
#include <list>

using namespace std;

int N, K;

struct ListNode {
    int element;
    ListNode *prev, *next;
};

void solve() {
    cin >> N >> K;
    list<int> survivors;
    for(int i = 1; i <= N; ++i)
        survivors.push_back(i);
    list<int>::iterator kill = survivors.begin();
    while(N > 2) {
        kill = survivors.erase(kill);
        if(kill == survivors.end())
            kill = survivors.begin();
        --N;
        for(int i = 0; i < K-1; ++i) {
            ++kill;
            if(kill == survivors.end())
                kill = survivors.begin();
        }
    }    
    cout << survivors.front() << " " << survivors.back() << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}