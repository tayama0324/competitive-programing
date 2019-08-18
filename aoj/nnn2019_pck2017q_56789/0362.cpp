#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vint;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

bool solve(const vint &v) {
  int best = v[0];
  REP(i,v.size()) {
    if (best >= i * 10) {
      best = max(best, i * 10 + v[i]);
    }
  }
  return best >= ((int)v.size() - 1) * 10;
}

int main() {
  int n;
  while (cin >> n) {
    vint v(n);
    REP(i,n) cin >> v[i];
    bool result = solve(v);
    reverse(v.begin(), v.end());
    result = result && solve(v);
    cout << (result ? "yes" : "no") << endl;
  }
}
