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

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int n, m;
  while (cin >> n >> m) {
    ll result = n;
    FOR(i,n,n+m+1) result = lcm(result, i);
    cout << result << endl;
  }
}
