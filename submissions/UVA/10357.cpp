#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const double EPS{1e-9};

struct Player
{
    int x, y, v;

    bool can_reach(int xv, int yv, int t) const
    {
        double dist = hypot(x - xv, y - yv);
        return dist <= v * t;
    }
};

struct Ball
{
    int a, b, c, d, e, f, g;

    int y(int t) const { return f * t + g; }
    int x(int t) const { return d * t + e; }
    int z(int t) const { return a * t * t + b * t + c; }
    int time_to_land() const
    {
        if (!a)
            return ceil(-c / (double)b);
        return max(ceil((-b + sqrt(b * b - 4 * a * c)) / (2 * a)),
                   ceil((-b - sqrt(b * b - 4 * a * c)) / (2 * a)));
    }
};

void solve()
{
    int n;
    cin.ignore(8);
    cin >> n;
    vector<Player> players(n);
    for (auto &player : players)
        cin >> player.x >> player.y >> player.v;

    int m;
    cin.ignore(7);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        Ball ball;
        cin >> ball.a >> ball.b >> ball.c >> ball.d >> ball.e >> ball.f >> ball.g;

        int t = ball.time_to_land();
        int ball_x = ball.x(t), ball_y = ball.y(t);
        string status = "safe";

        for (auto &player : players)
        {
            if (player.can_reach(ball_x, ball_y, t))
                status = "caught";
        }
        if (ball_x < 0 || ball_y < 0)
            status = "foul";

        cout << "Ball " << i << " was " << status << " at (" << ball_x << "," << ball_y << ")\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
