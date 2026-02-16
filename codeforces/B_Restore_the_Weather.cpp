#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct temp{
    int id;
    int a;
    int b;
};

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<temp> temps(n);
    for(int i = 0; i < n; i++){
        temps[i].id = i;
        cin >> temps[i].a;
    }
    vector<int> B(n);
    for(auto &b : B) cin >> b;

    sort(all(B));
    auto comp_a = [&](const temp &a, const temp &b){
        return a.a < b.a;
    };
    auto comp_id = [&](const temp &a, const temp &b){
        return a.id < b.id;
    };
    sort(all(temps), comp_a);
    for(int i = 0; i < n; i++){
        temps[i].b = B[i];
    }
    sort(all(temps), comp_id);

    for(auto &t : temps){
        cout << t.b << ' ';
    }
    cout << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}