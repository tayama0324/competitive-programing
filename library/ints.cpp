template<ll MOD> class MInt {
  ll value;
public:
  MInt() : value(0) {}
  MInt(int v) : value(v) {}
  MInt(ll v) : value(v) {}
  MInt& operator+=(const MInt<MOD> &r) {
    value += r.value; if (value > MOD) value -= MOD; return *this;
  }
  MInt& operator-=(const MInt<MOD> &r) {
    value -= r.value; if (value < 0) value += MOD; return *this;
  }
  MInt& operator*=(const MInt<MOD> &r) {
    value *= r.value; value %= MOD; return *this;
  }
  MInt& operator/=(const MInt<MOD> &r) {
    (*this) *= r.inv(); return *this;
  }
  MInt operator+(const MInt<MOD> &r) const { MInt result = *this; result += r; return result; }
  MInt operator-(const MInt<MOD> &r) const { MInt result = *this; result -= r; return result; }
  MInt operator*(const MInt<MOD> &r) const { MInt result = *this; result *= r; return result; }
  MInt operator/(const MInt<MOD> &r) const { MInt result = *this; result /= r; return result; }
  MInt pow(ll p) const {
    MInt result = 1, x = *this;
    for (;p;p >>= 1) {
      if (p & 1) result *= x;
      x *= x;
    }
    return result;
  }
  MInt inv() const { return this->pow(MOD - 2); }
  operator ll() const { return value; }
  
};

typedef MInt<1000000007> Int;

class C_cls {
  static const int N = 1000000;
  vector<Int> facts;
public:
  C_cls() : facts(vector<Int>(N, 1)){
    FOR(i,1,N) facts[i] = facts[i-1] * Int(i);
  }
  Int choose(int n, int r) { return facts[n] / (facts[r] * facts[n-r]); }
};

C_cls C;

