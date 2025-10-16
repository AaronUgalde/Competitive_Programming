#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    enum State {ARRIVED, OUT};
    int n_not_arrived = n, n_arrived = 0, n_out = 0;
    int day = 1;
    map<int, pair<State, int>> employe_state_day_out;
    for(int i = 0; i < n; i++){
        employe_state_day_out[abs(A[i])] = {OUT, 0}; 
    }

    vector<int> sizes;
    for(int i = 0, size = 0; i < n; i++, size++){
        bool ok = false;
        if(A[i] < 0){
            if(employe_state_day_out[abs(A[i])].first == ARRIVED){
                employe_state_day_out[abs(A[i])] = {OUT, day};
                n_arrived--;
                ok = true;
            }
        }else{
            if(employe_state_day_out[A[i]].first == OUT && employe_state_day_out[A[i]].second < day){
                employe_state_day_out[A[i]].first = ARRIVED;
                n_arrived++;
                ok = true;
            }
        }
        if(ok){
            if(n_arrived == 0){
                day++;
                sizes.push_back(size + 1);
                size = -1;
            }
        }else{
            cout << -1 << endl;
            return;
        }
    }

    if(n_arrived > 0){
        cout << -1 << endl;
        return; 
    }

    cout << day - 1 << endl;
    for(auto &s : sizes) cout << s << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}