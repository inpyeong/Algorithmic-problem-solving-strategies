#include <iostream>
#include <vector>

using namespace std;

int n;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

vector<int> solve(const vector<int>& recipe, const vector<int>& put) {
    int b = recipe[0];
    for(int i = 1; i < n; ++i)
        b = gcd(b, recipe[i]);
    int a = b;
    for(int i = 0; i < n; ++i)
        a = max(a, ceil(put[i] * b, recipe[i]));
    vector<int> ret(n);
    for(int i = 0; i < n; ++i)
        ret[i] = recipe[i] * a / b - put[i];
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> recipe(n, 0), put(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> recipe[i];
        for(int i = 0; i < n; ++i)
            cin >> put[i];
        vector<int> answer = solve(recipe, put);
        for(int ans : answer)
            cout << ans << " ";
        cout << "\n";
    }
}