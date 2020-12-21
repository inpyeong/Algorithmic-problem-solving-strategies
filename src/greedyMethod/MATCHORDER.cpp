#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

void solve() {
  cin >> N;
  vector<pair<int, int> > russia, korea;

  int rating;
  for(int i = 0; i < N; ++i) {
    cin >> rating;
    russia.push_back(make_pair(rating, i));
  }
  for(int i = 0; i < N; ++i) {
    cin >> rating;
    korea.push_back(make_pair(rating, false));
  }

  sort(russia.begin(), russia.end());
  sort(korea.begin(), korea.end());

  int answer = 0;
  for(int rusIdx = 0; rusIdx < N; ++rusIdx)
    for(int i = 0; i < N; ++i) {
      int korRating = korea[i].first;
      int rusRating = russia[rusIdx].first;
      bool ordered = korea[i].second;
      if(ordered) continue;
      if(korRating >= rusRating) {
        korea[i].second = true;
        answer++;
        break;
      }
    }

  cout << answer << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
