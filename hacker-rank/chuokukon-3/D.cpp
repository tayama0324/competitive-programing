#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <set>
#include <queue>
#include <map>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i,b,e) for (int i = (b); i < (int)(e); ++i)

const int DI[] = { -1, 0, 1, 0 };
const int DJ[] = { 0, 1, 0, -1 };

using namespace std;

const int N = 20000000;
const long long MOD = 1000000007;

int sieve[N];

void factorize(int n, vector< pair<int,int> > &result) {
  while (n > 1) {
    int p = sieve[n];
    if (result.size() == 0 || result.back().first != p) {
      result.push_back(make_pair(p, 1));
    } else {
      result.back().second++;
    }
    n /= p;
  }
}

int main() {
  REP(i,N) sieve[i] = i;
  for (int i = 2; i * i < N; ++i) {
    if (sieve[i] == i) {
      for (int j = 2; i * j < N; ++j) {
        sieve[i * j] = i;
      }
    }
  }

  int n;
  while (cin >> n) {
    vector<int> result(N);
    vector< pair<int,int > > f;
    FOR(i,2,n+1) {
      f.clear();
      factorize(i, f);
      for (const auto& it: f) result[it.first] = max(result[it.first], it.second);
    }
    long long lcm = 1;
    FOR(i,2,N) REP(iter,result[i]) {
      lcm *= i; lcm %= MOD;
    }
    cout << lcm << endl;
  }
}
