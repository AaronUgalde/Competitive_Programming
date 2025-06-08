#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int n; int k; cin >> n >> k;
    k *= 2;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    vector<int> bucket(n+1, 0);
    for(int i = 0; i<n; i++){
        bucket[a[i]]++;
    }

    stack<int> one, zero, two;
    for(int i = 1; i<=n; i++){
        if(bucket[i] == 1) one.push(i);
        else if(bucket[i] == 2) two.push(i);
        else zero.push(i);
    }

    vector<int> k_a, k_b;
    while(k && !two.empty()){
        k_a.push_back(two.top());
        k_a.push_back(two.top());
        two.pop();
        k_b.push_back(zero.top());
        k_b.push_back(zero.top());
        zero.pop();
        k -= 2;
    }

    while(k){
        k_a.push_back(one.top());
        k_b.push_back(one.top());
        one.pop();
        k--;
    }

    for(int i = 0; i<k_a.size(); i++){
        cout << k_a[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i<k_b.size(); i++){
        cout << k_b[i] << ' ';
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