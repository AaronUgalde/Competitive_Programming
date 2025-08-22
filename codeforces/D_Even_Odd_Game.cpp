#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){   
    int n; cin >> n;
    vector<ll> A(n);
    for(auto &a : A) cin >> a;

    vector<ll> even, odd;
    for(int i = 0; i<n; i++){
        if(A[i] % 2 == 0){
            even.push_back(A[i]);
        }else{
            odd.push_back(A[i]);
        }
    }

    sort(all(even)); sort(all(odd));
    ll sum_alice = 0, sum_bob = 0;
    bool alice_turn = true;
    for(int i = 0; i<n; i++){
        if(alice_turn){
            if(odd.size() == 0 || (even.size() != 0 && even[even.size()-1] >= odd[odd.size()-1])){
                sum_alice += even[even.size()-1];
                even.pop_back();
            }else{
                odd.pop_back();
            }
        }else{
            if(odd.size() == 0 || (even.size() != 0 && even[even.size()-1] >= odd[odd.size()-1])){
                even.pop_back();
            }else{
                sum_bob += odd[odd.size()-1];
                odd.pop_back();
            }
        }
        alice_turn = !alice_turn;
    }

    cout << (sum_alice > sum_bob ? "Alice" : (sum_bob > sum_alice ? "Bob" : "Tie")) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}