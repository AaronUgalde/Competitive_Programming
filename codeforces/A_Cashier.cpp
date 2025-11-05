#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct service{
    int arrive;
    int time;

    service() = default;
    service(int a, int t) : arrive(a), time(t) {}
};

void solve(int testcase){
    int n, l, a;
    cin >> n >> l >> a;
    vector<service> services(n);
    for(auto &s : services) cin >> s.arrive >> s.time;
    
    services.emplace_back(0, 0);
    services.emplace_back(l, 0);
    sort(all(services), [](const service &a, const service &b){
        return a.arrive < b.arrive;
    });

    int ans = 0;
    for(int i = 1; i <= n + 1; i++){
        ans += (services[i].arrive - services[i - 1].arrive - services[i - 1].time) / a;
    }

    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}