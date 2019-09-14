#include <iostream>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef vector<int> vint;
typedef long long ll;

int DI[] = { 0, -1, 0, 1 };
int DJ[] = { 1, 0, -1, 0 };

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main() {
  int n;
  while (cin >> n) {
    vector<ll> v(n);
    REP(i,n) cin >> v[i];

    int result = 0;
    REP(s,1<<n) {
      if (s == 0) continue;
      ll p = 1;
      REP(i,n) if (s & (1 << i)) p *= lcm(p, v[i]);
      bool ok = true;      
      REP(i,n) if (!(s & (1 << i)) && p % v[i] == 0) ok = false;
      if (ok) result++;
    }
    cout << result << endl;
  }
}
