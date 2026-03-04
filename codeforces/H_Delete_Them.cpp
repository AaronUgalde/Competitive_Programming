#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<string> file_names(n);
    for(auto &file : file_names) cin >> file;
    vector<string> del_file(m);
    vector<bool> del(n, false);
    int mx_size = 0;
    for(int i = 0; i < m; i++){
        int a; cin >> a; a--;
        del[a] = true;
        del_file[i] = file_names[a];
        mx_size = max(mx_size, sz(del_file[i]));
    }

    string pattern = "";
    for(int j = 0; j < mx_size; j++){
        bool all_equal = true;
        for(int i = 0; i < m - 1; i++){
            if(j >= sz(del_file[i]) or j >= sz(del_file[i + 1])){
                cout << "No" << endl;
                return;
            }
            if(del_file[i][j] != del_file[i + 1][j]){
                all_equal = false;
                break;
            }
        }

        if(all_equal){
            pattern += del_file[0][j];
        }else{
            pattern += '?';
        }
    }

    for(int i = 0; i < n; i++){
        if(del[i]) continue;
        if(sz(pattern) != sz(file_names[i])) continue;
        bool match = true;
        for(int j = 0; j < sz(file_names[i]); j++){
            if(file_names[i][j] != pattern[j] and pattern[j] != '?'){
                match = false;
                break;
            }
        }

        if(match){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    cout << pattern << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}