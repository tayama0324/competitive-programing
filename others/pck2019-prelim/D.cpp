#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef vector<int> vint;
typedef long long ll;

ll unpop(ll a) {
  return a & (a - 1);
}

int main() {
  int n;
  while (cin >> n) {
    vint v(n);
    REP(i,n) cin >> v[i];
    sort(v.begin(), v.end());
    int result = 1 << 20;
    REP(i,2001) {
      int ans = 0;
      REP(j,v.size()) ans = max(ans, abs(i - v[j]));
      result = min(result, ans);
    }
    cout << result << endl;
  }
}
