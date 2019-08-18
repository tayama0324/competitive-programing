#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vint;

const int inf = 1 << 20;

template<class T> void gs(T &a, T b) { a = max(a, b); }

class SegmentTree {
  vint v;
  int base() { return v.size() / 2; }
  int parent(int n) { return n / 2;}
  int left(int n) { return n * 2; }
  int right(int n) { return n * 2 + 1; }

  int rec(int root, int l, int len, int lo, int hi) {
    int r = l + len - 1;
    if (l <= lo && r <= hi) return v[root];
    int a = rec(left(root), l, len / 2, lo, hi);
    int b = rec(right(root), l + len, len / 2, lo, hi);
    return min(a, b);
  }
  
public:
  SegmentTree(int n) : v(vint(n * 2)) {
    while (v.size() & (v.size() - 1)) { v.push_back(1 << 20); }
  }
  int value(int lo, int hi) {
    return rec()
  }
  
};


int main() {
  int li, lj, n;
  while (cin >> li >> lj >> n) {
  }
}
