#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

const double p = 0.2316419;
const double PI = acos(-1.0);
const double B[] = {0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429};

void solve()
{
  for (int n, T = 1; cin >> n; T++)
  {
    vector<double> v(n);
    double mu = 0, sigma = 0;
    for (auto &x : v) cin >> x, mu += x;
    mu /= n;
    for (auto x : v)
    {
      auto tmp = x - mu;
      sigma += tmp * tmp;
    }
    sigma = sqrt(sigma / (n-1));

    if (T > 1) cout << '\n';
    cout << "Data Set #" << T << '\n';
    cout << fixed << setprecision(4) << "Mean = " << mu << '\n';
    cout << fixed << setprecision(4) << "Standard Deviation = " << sigma << '\n';

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
      double x; cin >> x;
      double z = (x - mu) / sigma;
      double t = (1 / (1 + p * fabs(z)));

      double fz = exp(-z*z/2) / sqrt(2*PI);
      double Q = fz * (B[0]*t+B[1]*t*t+B[2]*t*t*t+B[3]*t*t*t*t+B[4]*t*t*t*t*t);

      cout << fixed << setprecision(4)<< "P(z) = " << 1-Q << ", "
        << "Q(z) = " << Q << ", T = " << Q * n << '\n';
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

