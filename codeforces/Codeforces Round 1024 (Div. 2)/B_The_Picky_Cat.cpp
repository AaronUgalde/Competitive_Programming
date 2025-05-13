#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int n;

bool is_media(int &first, vector<int> &a){
    int joker = 0;
    int under = 0;
    int above = 0;
    for(auto &x : a){
        if(first == 0 && x == 0) joker++;
        else if(x >= first && -x >= first) above++;
        else if(x <= first && -x <= first) under++;
        else if((x >= first && -x <= first) || (x <= first && -x >= first)) joker++;
    }

    if(under <= (n/2) && above <= (n/2 - n%2==0)) return true;
    return false;
}

void solve(int testcase){
    cin >> n;
    vector<int> a(n-1);
    int first; cin >> first;
    int n_first = -first;
    for(auto &x : a) cin >> x;

    bool original = is_media(first, a);
    bool negated = is_media(n_first, a);
    cout << (original || negated ? "YES" :  "NO") << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}