#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void printvec(vector<int> v){
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}


void solve(int testcase){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> pos_b(n+1);
    vector<int> pos_a(n+1);
    int cnt_b = 0;
    int cnt_a = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == 'B'){
            cnt_b++;
            pos_b[cnt_b] = i+1;
        }else{
            cnt_a++;
            pos_a[cnt_a] = i+1;
        }
    }

    int diff = abs(cnt_b - k);
    if(diff == 0){
        cout << 0 << endl; 
        return;
    }

    cout << 1 << endl;
    cout << (cnt_b > k ? pos_b[diff] : pos_a[diff]) << ' ' << (cnt_b > k ? 'A' : 'B') << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}