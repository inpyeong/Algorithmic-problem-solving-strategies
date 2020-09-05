#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string str;

string reverse(string::iterator& it) {
  char head = *it;
  ++it;
  if (head == 'b' || head == 'w') 
    return string(1, head);

  string upperLeft = reverse(it);
  string upperRight = reverse(it);
  string lowerLeft = reverse(it);
  string lowerRight = reverse(it);
  return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

void solve() {
  cin >> str;
  string::iterator it = str.begin();
  cout << reverse(it) << "\n";
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
