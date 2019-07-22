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
  REP(x,n) {
    cnt[min(2, cube[0][0][x])]++;
    cnt[min(2, cube[0][n-1][x])]++;
    cnt[min(2, cube[n-1][0][x])]++;
    cnt[min(2, cube[n-1][n-1][x])]++;
    
    cnt[min(2, cube[0][x][0])]++;
    cnt[min(2, cube[0][x][n-1])]++;
    cnt[min(2, cube[n-1][x][0])]++;
    cnt[min(2, cube[n-1][x][n-1])]++;
    
    cnt[min(2, cube[x][0][0])]++;
    cnt[min(2, cube[x][0][n-1])]++;
    cnt[min(2, cube[x][n-1][0])]++;
    cnt[min(2, cube[x][n-1][n-1])]++;
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
  REP(i,n) tmp[n-1][i] = v[i][0];
  REP(i,n) tmp[0][i] = v[i][n-1];
  REP(j,n) tmp[n-1-j][0] = v[0][j];
  REP(j,n) tmp[n-1-j][n-1] = v[n-1][j];
  REP(i,n) {
    if (i == 0 || i + 1 == n) REP(j,n) v[i][j] = tmp[i][j];
    else { v[i][0] = tmp[i][0]; v[i][n-1] = tmp[i][n-1]; }
  }
}

void flip(Face v) {
  REP(i,n) {
    if (i == 0 || i + 1 == n) reverse(v[i], v[i] + n);
    else swap(v[i][0], v[i][n-1]);
  }
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
