#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void print_vec(vector<int> v){
    for(auto &x : v) cout << x << ' ';
    cout << endl;
}

void solve(int testcase){
    int n, d, k; cin >> n >> d >> k;
    vector<int> open(n+1, 0), close(n+1, 0);
    for(int i = 0; i<k; i++){
        int l, r; cin >> l >> r; l--, r--;
        open[l]++;
        close[r+1]++;
    }

    int best_mom = 0, best_brother = 0;
    int min_jobs =  accumulate(open.begin(), open.begin()+d, 0);
    int max_jobs =  accumulate(open.begin(), open.begin()+d, 0);
    int curr_jobs = min_jobs; 
    for(int i = 1, j = d; j<n; i++, j++){
        int jobs = curr_jobs + open[j] - close[i];
        if(jobs > max_jobs){
            max_jobs = jobs;
            best_brother = i;
        }
        if(jobs < min_jobs){
            min_jobs = jobs;
            best_mom = i;
        }
        curr_jobs = jobs;
    }

    cout << best_brother+1<< ' ' << best_mom+1<< endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}