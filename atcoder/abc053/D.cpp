#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    int rm = v.end() - it;
    if (rm % 2 == 1) rm++;
    cout << n - rm << endl;
  }
}
