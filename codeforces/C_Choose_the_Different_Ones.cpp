#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n, m, k; cin >> n >> m >> k;
    vector<int> exists(k+1, -1);
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        if(x <= k) exists[x] = 1;
    }

    for(int i = 0; i<m; i++){
        int x; cin >> x;
        if(x <= k) exists[x] = (exists[x] == -1 ? 2 : (exists[x] == 1 ? 3 : (exists[x] == 3 ? 3 : 2))); 
    }

    int one = 0, two = 0;
    for(int i = 0; i<k; i++){
        if(exists[i+1] == 1){
            one++;
        }else if(exists[i+1] == 2){
            two++;
        }else if(exists[i+1] == -1){
            cout << "NO"<< endl;
            return;
        }
    }

    cout << (one <= k/2 && two <= k/2 ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}