// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define len(__x) (ll) __x.size()
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define INV(xxxx) \
    for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x) \
    for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), cout << '\n';
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
#define rsz(___x, ___n) resize(___x, ___n)

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

const ll INF = 1e18;

struct node {
    ll ai, bi, li, ri;
    bool operator<(node &b) { return pair<ll, ll>{li, ri} < pair<ll, ll>{b.li, b.ri}; }
    bool operator<(const node &b) const { return pair<ll, ll>{li, ri} < pair<ll, ll>{b.li, b.ri}; }
};

vector<node> unisaporra2(const vector<node> &portals) {
    vector<node> ans;
    ans.pb(portals[0]);
    ll n = portals.size();
    for (int i = 1; i < n; ++i) {
        if (portals[i].li <= ans.back().bi) {
            ans.back().bi = max(ans.back().bi, portals[i].bi);
            ans.back().li = min(ans.back().li, portals[i].li);
            ans.back().ri = max(ans.back().ri, portals[i].ri);
            ans.back().ai = min(ans.back().ai, portals[i].ai);
        } else {
            ans.push_back(portals[i]);
        }
    }

    return ans;
}
void run() {
    ll n;
    cin >> n;
    //  li, ri, ai, bi,
    vector<node> portals(n);
    for (int i = 0; i < n; ++i) {
        cin >> portals[i].li >> portals[i].ri >> portals[i].ai >> portals[i].bi;
    }
    // cerr << "portais novos: " << endl;
    // for (auto &pi : portals) {
    //   cerr << pi.ai << ' ' << pi.bi << ' ' << pi.li << ' ' << pi.ri << endl;
    // }
    // cerr << endl;
    sort(all(portals));
    portals = unisaporra2(portals);

    ll q;
    cin >> q;
    vll starts(q);
    for (int i = 0; i < q; ++i) cin >> starts[i];

    // otmiza sabomba
    for (const auto &qi : starts) {
        ll ans = qi;
        auto it = upper_bound(all(portals), node{INT_MAX, INT_MAX, qi, INT_MAX}) - 1;
        dbg(it - portals.begin());
        if (it < portals.begin()) {
            cout << ans << ' ';
        } else {
          cout << max(ans, it->bi) << ' ';
        }
    }
    cout << endl;
}
int32_t main(void) {
    fastio;
    int t;
    t = 1;
    cin >> t;
    while (t--) run();
}
