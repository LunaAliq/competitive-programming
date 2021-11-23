#include <bits/stdc++.h>
using namespace std;

// repeat
// i: variable name
// n: times
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// reversed repeat
#define RREP(i, n) for(int i=n-1; i>=0; --i)

// memset
// var: variant name
// val: fill with
#define MEMSET(var, val) memset((var), val, sizeof(var))

// only if this is executed in the LOCAL machine,
// eprintf and epf output debug print to stderr
#ifdef LOCAL
  #define eprintf(...) fprintf(stderr, __VA_ARGS__)
  #define epf(...) fprintf(stderr, __VA_ARGS__)
#else
  #define eprintf(...) 42
  #define epf(...) 42
#endif

// types
typedef long long ll;
typedef pair<int, int> P;

// type modint
// define a with order 3 like
// `modint<3> a = 4;`
template<std::uint_fast64_t mod> class modint {
private:
  using u64 = std::uint_fast64_t;
  u64 _num;
  modint set(u64 num){ _num = num % mod; return *this; }
public:
  modint(){ _num = 0; }
  modint(u64 num){ _num = num % mod; }

  modint operator= (u64 x){ return set(x % mod); }
  modint operator+ (u64 x){ return modint<mod>(_num + (x % mod)); }
  modint operator- (u64 x){
    u64 _x = (x % mod);
    if (_num >= _x) {
      return modint<mod>(_num - _x);
    } else {
      return modint<mod>(mod - _x + _num);
    }
  }
  modint operator* (u64 x){ return modint<mod>(_num * (x % mod)); }
  modint operator+=(u64 x){ return set(_num + (x % mod)); }
  modint operator-=(u64 x){ return set(_num - (x % mod)); }
  modint operator*=(u64 x){ return set(_num * (x % mod)); }
  bool operator==(u64 x){ return bool(_num == (x % mod)); }

  explicit operator u64() { return _num; }
  friend ostream& operator<<(ostream &os, const modint<mod> &x){ os << x._num; return os; }
};

// change `a` to max of (a, b)
// a: variable name
// b: value
template<class T>bool chmax(T &a, const T &b){
  if(a < b){
    a = b;
    return 1;
  }
  return 0;
}

// change `a` to min of (a, b)
template<class T>bool chmin(T &a, const T &b){
  if(b < a){
    a = b;
    return 1;
  }
  return 0;
}

// gcd
int gcd(int a, int b){
  return b?gcd(b,a%b):a;
}

// grid diff: go to x
int dx[4] = {1, 0, -1, 0};
// grid diff: go to y
int dy[4] = {0, 1, 0, -1};

// start with this
int inf = 100000000;
int n, m;
char maze[100][101];

int d[100][101];

P search(char c) {
  REP(i, n) {
    REP(j, m) {
      if (maze[i][j] == c) return P(i, j);
    }
  }
  return P(-1, -1);
}

int bfs() {
  queue<P> que;
  P ps = search('S');
  P pg = search('G');

  REP(i, n) {
    REP(j, m) {
      d[i][j] = inf;
    }
  }

  d[ps.first][ps.second] = 0;
  que.push(ps);

  epf("ps: (%d, %d)\n", ps.first, ps.second);
  epf("pg: (%d, %d)\n", pg.first, pg.second);
  epf("que-size: %d, que-front: (%d, %d)\n", que.size(), que.front().first, que.front().second);

  while (que.size()) {
    P p = que.front(); que.pop();

    // end if goal
    if (p == pg) break;

    REP(i, 4) {
      // next point
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (nx > -1 && ny > -1 && nx < m && ny < n) {
        if (maze[nx][ny] != '#' && d[nx][ny] == inf) {
          int nd = d[p.first][p.second] + 1;
          d[nx][ny] = nd;
          epf("next: (%d, %d) - %d\n", nx, ny, nd);
          que.push(P(nx, ny));
        }
      }
    }
  }

  return d[pg.first][pg.second];
}

int main() {
  cin>>n;
  cin>>m;

  REP(i, n) {
    cin>>maze[i];
  }

  printf("%d\n", bfs());
  return 0;
}
