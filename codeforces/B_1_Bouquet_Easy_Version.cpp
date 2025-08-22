#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int spend(int key, int key2, int m, map<int, int> &bucket){
    int sum = min(bucket[key], m/key) * key;
    m -= sum*key;
    sum += min(bucket[key2], m/key2) * key2;
    return sum;
}

void solve(int testcase){
    int n, m; cin >> n >> m;
    vector<int> flowers(n);
    for(auto &flower : flowers) cin >> flower;

    map<int, int> bucket;
    for(auto &flower : flowers){
        bucket[flower]++;
    }
    
    int ans = INT_MIN;
    for(auto &[key, frec] : bucket){
        int sum = 0;
        if(bucket.count(key+1)){
            int mn = INT_MIN;
            for(int i = 0; i<=frec; i++){
                
            }
        }else{
            sum = min(bucket[key], m/key) * key;
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        cout << "test: " << i << endl;
        solve(i);
    }
}