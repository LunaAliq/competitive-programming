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

int n;
char s[2001];

// start with this
int main(){
  cin >> n;
  cin >> s;

  int top = 0;
  int btm = n - 1;
  int now = 0;

  while (btm >= top) {
    REP(i, btm - top + 1) {
      if (s[top + i] < s[btm - i]) {
        cout << s[top];
        now++;
        top++;
        break;
      } else if (s[top + i] > s[btm - i]) {
        cout << s[btm];
        now++;
        btm--;
        break;
      } if (top + i >= btm - i) {
        cout << s[top];
        now++;
        top++;
        break;
      }
      else {
        continue;
      }
    }
  }

  cout << "\n";

  return 0;
}
