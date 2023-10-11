#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

using pii = pair<int, int>;

const double EPS{1e-9};

template <typename T>
bool equals(const T &a, const T &b)
{
    if (std::is_floating_point<T>::value)
        return fabs(a - b) < EPS;
    else
        return a == b;
}

template <typename T>
struct Point
{
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point<T> operator-(const Point &o) const { return {x - o.x, y - o.y}; }
    bool operator==(const Point &o) const { return equals(x, o.x) && equals(y, o.y); }
    bool operator!=(const Point &o) const { return !(*this == o); }
    friend istream &operator>>(istream &stream, Point<T> &p)
    {
        stream >> p.x >> p.y;
        return stream;
    }
};

template <typename T>
double dist(const Point<T> &a, const Point<T> &b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

template <typename T>
T D(const Point<T> &P, const Point<T> &Q, const Point<T> &R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) -
           (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

template <typename T>
struct Line
{
    T a, b, c;

    Line(const Point<T> &P, const Point<T> &Q)
        : a(P.y - Q.y), b(Q.x - P.x), c(P.x * Q.y - Q.x * P.y) {}
};

template <typename T>
class Segment
{
public:
    Point<T> A, B;

    bool contains(const Point<T> &P) const
    {
        double dAB = dist(A, B), dAP = dist(A, P), dPB = dist(P, B);
        return equals(dAP + dPB, dAB);
    }

    bool intersect(const Segment &s) const
    {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);

        if ((equals(d1, 0) && contains(s.A)) || (equals(d2, 0) && contains(s.B)))
            return true;

        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);

        if ((equals(d3, 0) && s.contains(A)) || (equals(d4, 0) && s.contains(B)))
            return true;

        return (d1 * d2 < 0) && (d3 * d4 < 0);
    }
};



int D(const pii &a, const pii &b, const pii &c)
{
    return (a.first * b.second + a.second * c.first + b.first * c.second) -
           (c.first * b.second + c.second * a.first + b.first * a.second);
}

void solve()
{
    int n;
    cin >> n;
    vector<Segment<int>> v(n);
    for (auto &s: v)
        cin >> s.A >> s.B;

    int counter = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            counter += v[i].intersect(v[j]);
    cout << n + counter * 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        if (t)
        cout << '\n';
    }

    return 0;
}
