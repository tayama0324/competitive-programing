class DisjointSet {
public:
  vint v;
  DisjointSet(int n) : v(n, -1) {}

  int root(int n) { return v[n] < 0 ? n : (v[n] = root(v[n])); }
  bool unite(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra == rb) return false;
    if (-ra > -rb) swap(ra, rb);
    v[rb] += v[ra];
    v[ra] = rb;
    return true;
  }
  int size() { return count_if(ALL(v), [](int x){ return x < 0; }); }
};
