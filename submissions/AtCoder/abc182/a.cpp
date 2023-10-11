#include <bits/stdc++.h>
using namespace std;

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
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator==(const Point &o) const { return equals(x, o.x) && equals(y, o.y); }
    bool operator!=(const Point &o) const { return !(*this == o); }

    T x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << (2 * a + 100) - b << '\n';

    return 0;
}
