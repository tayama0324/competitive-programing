
const int MATRIX_DIMENSION = 4;

template<int N, typename T> class Matrix {
public:
  T value[N][N];
  Matrix() { fill(0); }

  void fill(T t) { REP(i,N) REP(j,N) value[i][j] = t; }
  void identity() { fill(0); REP(i,N) value[i][i] = 1; }
  Matrix<N, T>& operator*=(const Matrix<N, T> &that) {
    static Matrix<N, T> tmp;
    tmp.fill(0);
    REP(i,N) REP(j,N) REP(k,N) tmp.value[i][j] += value[i][k] * that.value[k][j];
    *this = tmp;
    return *this;
  }
  Matrix<N, T> operator*(const Matrix<N, T> &that) const {
    Matrix<N, T> result = *this;
    result *= that;
    return result;
  }
  vector<T> operator*(const vector<T> &v) const {
    assert(v.size() == N);
    vector<T> result(N);
    REP(i,N) REP(j,N) result[i] += value[i][j] * v[j];
    return result;
  }
  T& operator()(int i, int j) { return value[i][j]; }

  Matrix<N, T> pow(ll p) const {
    assert(0 <= p);
    static Matrix<N, T> result, sq;
    sq = *this;
    result.identity();
    for (; p; p >>= 1) {
      if (p & 1) result = result * sq;
      sq *= sq;
    }
    return result;
  }

  void print() const { REP(i,N) pp(value[i], N); }
};

typedef Matrix<MATRIX_DIMENSION, MInt> Mat;
