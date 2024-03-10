#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll m1, m2;
ll t1, t2;
vl P(14);

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> m1;
  m2 = m1;
  t1 = 0;
  t2 = 0;

  for (auto&& x : P) {
    cin >> x;
  }

  auto cinc = 0;
  auto cdec = 0;
  for (auto i = 0; i < 14; ++i) {
    const auto& q = m1 / P[i];
    t1 += q;
    m1 -= q * P[i];

    if (0 < i) {
      if (P[i - 1] < P[i]) {
        cinc += 1;
        cdec = 0;
      } else if (P[i] < P[i - 1]) {
        cdec += 1;
        cinc = 0;
      } else {
        cdec = 0;
        cinc = 0;
      }
    }

    if (3 <= cinc) {
      m2 += t2 * P[i];
      t2 = 0;
    }

    if (3 <= cdec) {
      const auto& q = m2 / P[i];
      t2 += q;
      m2 -= q * P[i];
    }
  }

  const auto& ca1 = m1 + t1 * P.back();
  const auto& ca2 = m2 + t2 * P.back();

  if (ca1 == ca2) {
    cout << "SAMESAME";
  } else if (ca1 < ca2) {
    cout << "TIMING";
  } else {
    cout << "BNP";
  }

  return 0;
}