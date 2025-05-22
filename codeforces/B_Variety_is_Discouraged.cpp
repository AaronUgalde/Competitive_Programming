#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void printvec(vector<int> vec){
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] << ' ';
    }
    cout << endl;
}


void solve(int testcase){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    map<int, pair<int, int>> x_cnt_pos;
    for(int i = 0; i<n; i++){
       x_cnt_pos[a[i]].first++;
       x_cnt_pos[a[i]].second = i;
    }

    vector<int> pos;
    for(auto &[x, cnt_pos] : x_cnt_pos){
        if(cnt_pos.first == 1){
            pos.push_back(cnt_pos.second);
        }
    }

    //cout << "pos size: " << pos.size() << endl;
    if(pos.size() == 0){
        cout << "0" << endl;
        return;
    }

    sort(all(pos));
    //cout << "vec: " << endl;
    //printvec(pos);

    int max_l = 0, max_n = 1;
    int l = 0; int n_i = 1;
    while(l + n_i <= pos.size()){
        //cout << "primer while: " << endl;
        while(l + n_i < pos.size() && pos[l+n_i] - n_i == pos[l]){
            //cout << "pos l + n_i " << pos[l+n_i] << ' ';
            n_i++;
        }
        if(n_i > max_n){
            max_l = l;
            max_n = n_i;
        }
        l += n_i;
        n_i = 1;
    }

    cout << pos[max_l] + 1 << ' ' << pos[max_l] + max_n  << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        //cout << "test: " << i << endl;
        solve(i);
    }
}