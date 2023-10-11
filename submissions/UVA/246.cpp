#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto y: x) cerr << y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
    for (int first; cin >> first, first;)
    {
        queue<int> cards;
        cards.push(first);
        for (auto i = 1, x = 0; i < 52; i++) cin >> x, cards.push(x);

        vector<deque<int>> dq(7);
        for (auto i = 0; i < 7; i++)
            dq[i].push_back(cards.front()), cards.pop();

        auto ans = 7;
        set<vector<int>> vis;
        for (auto found = false; not found; )
        {
            for (auto i = 0; i < 7; i++)
            {
                if (dq[i].empty()) continue;
                auto &cur_stack = dq[i];
                cur_stack.push_back(cards.front());
                cards.pop();
                ans++;
                for (auto sz = cur_stack.size(); sz >= 3; sz = cur_stack.size())
                {
                    if ((cur_stack[0] + cur_stack[1] + cur_stack[sz-1]) % 10 == 0)
                    {
                        cards.push(cur_stack[0]);
                        cards.push(cur_stack[1]);
                        cards.push(cur_stack[sz-1]);
                        cur_stack.pop_front();
                        cur_stack.pop_front();
                        cur_stack.pop_back();
                    }
                    else if ((cur_stack[0] + cur_stack[sz-1] + cur_stack[sz-2]) % 10 == 0)
                    {
                        cards.push(cur_stack[0]);
                        cards.push(cur_stack[sz-2]);
                        cards.push(cur_stack[sz-1]);
                        cur_stack.pop_front();
                        cur_stack.pop_back();
                        cur_stack.pop_back();
                    }
                    else if ((cur_stack[sz-3] + cur_stack[sz-1] + cur_stack[sz-2]) % 10 == 0)
                    {
                        cards.push(cur_stack[sz-3]);
                        cards.push(cur_stack[sz-2]);
                        cards.push(cur_stack[sz-1]);
                        cur_stack.pop_back();
                        cur_stack.pop_back();
                        cur_stack.pop_back();
                    }
                    else
                        break;
                }
                if (cards.size() == 52)
                {
                    cout << "Win : ";
                    found = true;
                    break;
                }
                else if (cards.size() == 0)
                {
                    cout << "Loss: ";
                    found = true;
                    break;
                }
                vector<int> state;
                for (const auto &d : dq)
                {
                    state.insert(state.end(), all(d));
                    state.push_back(42);
                }
                auto q = cards;
                while (not q.empty())
                    state.push_back(q.front()), q.pop();
                state.push_back(42);
                if (vis.count(state))
                {
                    cout << "Draw: ";
                    found = true;
                    break;
                }
                vis.insert(state);
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;
    //for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

