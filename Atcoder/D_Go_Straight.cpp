#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct node {
    int i;
    int j;
    int last_dir;

    bool operator==(const node &other) const {
        return i == other.i && j == other.j && last_dir == other.last_dir;
    }

    bool operator!=(const node &other) const {
        return !(*this == other);
    }

    bool operator<(const node &other) const {
        if (i != other.i) return i < other.i;
        if (j != other.j) return j < other.j;
        return last_dir < other.last_dir;
    }
};

void solve() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (auto &s : grid) cin >> s;

    node start{-1, -1, 0};
    node goal{-1, -1, 0};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j, 0};
            } else if (grid[i][j] == 'G') {
                goal = {i, j, 0};
            }
        }
    }

    auto id = [&](int i, int j, int d) {
        return ((i * W + j) * 4 + d);
    };

    auto decode = [&](int x) {
        int d = x % 4;
        x /= 4;
        int j = x % W;
        int i = x / W;
        return node{i, j, d};
    };

    int total = H * W * 4;
    vector<char> visited(total, 0);
    vector<int> parent(total, -1);

    vector<int> diri = {0, 1, 0, -1};   // L, D, R, U
    vector<int> dirj = {-1, 0, 1, 0};

    auto dfs = [&](auto &&self, node u) -> void {
        int uid = id(u.i, u.j, u.last_dir);
        visited[uid] = 1;

        for (int dir = 0; dir < 4; dir++) {
            node v = {
                u.i + diri[dir],
                u.j + dirj[dir],
                dir
            };

            if (
                v.i < 0 || v.i >= H || v.j < 0 || v.j >= W ||
                grid[v.i][v.j] == '#' ||
                visited[id(v.i, v.j, v.last_dir)] ||
                (
                    grid[u.i][u.j] == 'o' &&
                    v.last_dir != u.last_dir
                ) ||
                (
                    grid[u.i][u.j] == 'x' &&
                    v.last_dir == u.last_dir
                )
            ) continue;

            int vid = id(v.i, v.j, v.last_dir);
            parent[vid] = uid;
            self(self, v);
        }
    };

    dfs(dfs, goal);

    bool start_reached = false;
    node start_state;

    for (int d = 0; d < 4; d++) {
        int sid = id(start.i, start.j, d);
        if (visited[sid]) {
            start_reached = true;
            start_state = {start.i, start.j, d};
            break;
        }
    }

    if (!start_reached) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    string path;
    node cur = start_state;

    while (!(cur.i == goal.i && cur.j == goal.j)) {
        int cur_id = id(cur.i, cur.j, cur.last_dir);
        int par_id = parent[cur_id];
        node nxt = decode(par_id);

        int di = nxt.i - cur.i;
        int dj = nxt.j - cur.j;

        if (di == 0 && dj == -1) path.push_back('L');
        else if (di == 1 && dj == 0) path.push_back('D');
        else if (di == 0 && dj == 1) path.push_back('R');
        else if (di == -1 && dj == 0) path.push_back('U');

        cur = nxt;
    }

    cout << path << endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve();
    }
}