#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const double EPS{1e-9};

void translate(vector<pair<int, int>> &v, pair<int, int> center)
{
    for (auto &p : v)
        p = make_pair(p.first - center.first, p.second - center.second);
}

void rotate_90(vector<pair<int, int>> &v)
{
    for (auto &p : v)
        p = make_pair(-p.second, p.first);
}

ostream &operator<<(ostream &os, const pair<int, int> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> as(n);
    for (auto &x : as)
        cin >> x.first >> x.second;
    vector<pair<int, int>> bs(n);
    for (auto &x : bs)
        cin >> x.first >> x.second;

    translate(as, *min_element(as.begin(), as.end()));
    translate(bs, *min_element(bs.begin(), bs.end()));
    sort(bs.begin(), bs.end());

    auto ans = "NOT MATCHED";
    for (int i = 0; i < 4; i++)
    {
        rotate_90(as);
        translate(as, *min_element(as.begin(), as.end()));
        sort(as.begin(), as.end());

        if (as == bs)
        {
            ans = "MATCHED";
            break;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
