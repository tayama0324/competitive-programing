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
  ll n;
  while (cin >> n) {
    while (unpop(n) != 0) n = unpop(n);
    cout << n << endl;
  }
}
