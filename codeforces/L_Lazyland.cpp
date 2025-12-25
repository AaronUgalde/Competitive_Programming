#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

struct idler{
    int a;
    int b;

    bool operator <(const idler &other){
        if(a != other.a) return a < other.a;
        return b < other.b;
    }
};

void solve(int testcase){
    int n, k; cin >> n >> k;
    vector<idler> idlers(n);
    for(auto &i : idlers) cin >> i.a;
    for(auto &i : idlers) cin >> i.b;
    
    sort(all(idlers));
    set<int> jobs_done;
    vector<int> free_idlers;
    for(int i = 0; i < n; i++){
        jobs_done.insert(idlers[i].a);
        if(i + 1 < n and idlers[i].a == idlers[i + 1].a){
            free_idlers.push_back(idlers[i].b);
        }
    }

    sort(all(free_idlers));
    int jobs_missing = k - sz(jobs_done);
    ll ans = 0;
    for(int i = 0; i < jobs_missing; i++){
        ans += free_idlers[i]; 
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