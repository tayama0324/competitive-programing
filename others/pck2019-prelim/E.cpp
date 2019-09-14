#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef vector<int> vint;
typedef long long ll;

void solve(vint v, int n) {
  vint st;
  REP(i,n) {
    if (v[i] > 0) {
      if (count(st.begin(), st.end(), v[i])) { cout << i + 1 << endl; return; };
      st.push_back(v[i]);
    } else {
      int b = st.back();
      if (-v[i] != b) { cout << i + 1 << endl; return; }
      st.pop_back();
    }
  }
  cout << "OK" << endl;
}

int main() {
  int n;
  while (cin >> n) {
    vint v(n);
    REP(i,n) cin >> v[i];
    solve(v, n);
  }
}
