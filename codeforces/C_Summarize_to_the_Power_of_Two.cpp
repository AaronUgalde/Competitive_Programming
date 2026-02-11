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
    map<int, int> bucket;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        bucket[x]++;
    }

    auto get_complement = [&](int x){
        int first = false;
        int complement = 0;
        for(int i = 1; i <= x; i <<= 1){
            if((x & i) == 0){
                if(first) complement += i;
            }else if(!first){
                complement += i;
                first = true;
            }
        }
        return complement;
    };

    ll ans = 0;
    for(auto &[x, frec] : bucket){
        int y = get_complement(x);
        int pot2 = x + y;
        bool find = false;
        while(frec and y <= 1e9){
            if(x != y){
                if(bucket[y]){
                    find = true;
                    break;
                }
            }else{
                if(bucket[y] >= 2){
                    find = true;
                    break;
                }
            }
            y += pot2;
            pot2 <<= 1;
        }
        if(!find){
            ans += frec;
        }
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