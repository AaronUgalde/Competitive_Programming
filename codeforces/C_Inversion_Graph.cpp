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
    for(auto &a : A) cin >> a, a--;
    
    vector<int> appeard(n, false);
    int mn_i_not_appeard = 0;
    int ans = 1;
    int greaters = 0;

    for(int i = 0; i < n; i++){
        appeard[A[i]] = true;
        if(A[i] > mn_i_not_appeard){
            //cout << "mn_i_not_appeard: " << mn_i_not_appeard << endl;
            //cout << "A[i]: " << A[i] << endl;
            greaters++;
        }else{
            int cnt = 0;
            int j = mn_i_not_appeard;
            while(j < n and appeard[j] == true){
                j++;
                cnt++;
            }
            mn_i_not_appeard = j;
            greaters -= cnt - 1;
            //cout << "j: " << j << endl;
            //cout << "greaters: " << greaters << endl;
            //cout << "i: " << i << endl;
            if(greaters == 0) ans++;
        }
    }

    cout << ans - 1 << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}