#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef vector<int> vint;

const int N = 9;

typedef int Face[N][N];
typedef int Cube[N][N][N];

Face faces[6];
Cube cube;
int n;

const int BROKEN = 2;
const int INCOMPLETE = 1;
const int OK = 0;

int check() {
  int cnt[3] = { 0, 0, 0 };
  REP(i,n) REP(j,n) REP(k,n) {
    int f = (i == 0 || i == n-1) + (j == 0 || j == n-1) + (k == 0 || k == n-1);
    if (f >= 2) cnt[min(2, cube[i][j][k])]++;
  }
  if (cnt[2]) return BROKEN;
  else if (cnt[0]) return INCOMPLETE;
  else return 0;
}

void put(Face v, int at, int sign) {
  REP(i,n) REP(j,n) {
    int value = v[i][j] * sign;
    switch(at) {
    case 0: cube[0][i][j] += value; break;
    case 1: cube[n-1][i][j] += value; break;
    case 2: cube[i][0][j] += value; break;
    case 3: cube[i][n-1][j] += value; break;
    case 4: cube[i][j][0] += value; break;
    case 5: cube[i][j][n-1] += value; break;
    }
  }
}

void rotate(Face v) {
  static Face tmp;
  REP(i,n) REP(j,n) tmp[n-1-j][i] = v[i][j];
  REP(i,n) REP(j,n) v[i][j] = tmp[i][j];
}

void flip(Face v) {
  REP(i,n) reverse(v[i], v[i] + n);
}

bool DFS(int depth, vint &done) {
  if (depth == 6) {
    int value = check();
    return value == OK;
  }

  REP(_,2) {
    REP(__, 4) {
      REP(t,6) if (!done[t]) {
        put(faces[depth], t, 1);
        done[t] = true;
        int value = check();
        if (!(value & BROKEN) && DFS(depth + 1, done)) return true;
        done[t] = false;
        put(faces[depth], t, -1);
      }
      rotate(faces[depth]);
    }
    flip(faces[depth]);
  }
  return false;
}

int main() {
  while (cin >> n && n) {
    REP(i,n) REP(j,n) REP(k,n) cube[i][j][k] = 0;
    REP(f,6) REP(i,n) REP(j,n) {
      char ch; cin >> ch;
      faces[f][i][j] = (ch == 'X' ? 1 : 0);
    }

    vint done(6);
    bool result = DFS(0, done);
    cout << (result ? "Yes" : "No") << endl;
  }
}
