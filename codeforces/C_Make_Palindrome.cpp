#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i<s.size(); i++){
        mp[s[i]]++;
    }

    int odd = 0;
    for(auto &[_, frequency]: mp){
        if(frequency % 2 == 1){
            odd++;
        }
    }

    deque<char> dq;
    for(auto &[letter, frequency]: mp){
        if(frequency % 2 == 1){
            dq.push_back(letter);
        }
    }

    while(dq.size()>1){
        char front = dq.front();
        dq.pop_front();
        char back = dq.back();
        dq.pop_back();
        mp[front]++;
        mp[back]--;
    }

    string ans = "";
    string center = "";
    for(auto &[letter, frequency]: mp){
        if(frequency % 2 == 1){
            center += letter;
            frequency--;
            ans += string(frequency/2, letter);
        }else{
            ans += string(frequency/2, letter);
            frequency /= 2;
        }
    }

    string ans2 = ans;
    reverse(all(ans2));
    ans += center;
    ans += ans2;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}