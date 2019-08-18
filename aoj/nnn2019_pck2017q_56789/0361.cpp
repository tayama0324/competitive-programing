#include <iostream>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main() {
  ll x, y;
  while (cin >> x >> y) {
    ll result = x + y + 2 - (gcd(x, y) + 1);
    cout << result << endl;
  }
}
