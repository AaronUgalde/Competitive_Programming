#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

struct word_info{
    string word;
    int x; 
    int y;
    int popularity;
    int s;
};


void solve(int testcase){
    int n; cin >> n;

    map<string, word_info> dictionary;
    for(int i = 0; i < n; i++){
        string word; cin >> word;
        int x, y; cin >> x >> y;
        dictionary[word] = {word, x, y, i, 0};
    }

    int m; cin >> m;
    vector<string> knowledge(m);
    for(auto &s : knowledge) cin >> s;

    auto dot = [&](word_info a, word_info b){
        return a.x * b.x + a.y * b.y;
    };

    auto cmp_word_info = [&](const word_info &a, const word_info &b){
        if(a.s != b.s) return a.s > b.s;
        return a.popularity < b.popularity;
    };

    auto search = [&](vector<string> last_k){
        vector<word_info> candidates;
        for(int i = 0; i < sz(knowledge); i++){
            if(knowledge[i] == last_k[0]){
                int j = 1;
                for(; j < sz(last_k); j++) {
                    if(last_k[j] != knowledge[i + j]) break;
                }
                
                //cout << "j: " << j << " i: " << i << " j + i: " << j + i << " knowledge[j]: " << knowledge[j + i] << endl;
                if(j == sz(last_k) && i + j < sz(knowledge) && dictionary.count(knowledge[i + j])) candidates.push_back(dictionary[knowledge[i + j]]);
            }
        }
/*  
        cout << " candidates: " << endl;
        for(auto &s: candidates) cout << s.word << endl;
        cout << endl;
   */
        return candidates;
    };

    int q, k; cin >> q >> k;
    for(int i = 0; i < q; i++){
        int f; cin >> f;
        vector<string> query(f);
        for(auto &word : query) cin >> word, cout << word << ' ';
        vector<word_info> candidates;
        for(int j = k; j >= 1; j--){
            vector<string> last_k;
            for(int l = 0; l < j; l++){
                last_k.push_back(query[f - 1 - l]);
            }
            reverse(all(last_k));

/*             cout << " last_k: " << endl;
            for(auto &s: last_k) cout << s << endl;
            cout << endl;
 */
            candidates = search(last_k);
            if(sz(candidates) != 0) break;
        }

           
        vector<word_info> dictionary_vec;
        for(auto &[word, word_info_d] : dictionary){
            int s = 0;
            for(int j = 0; j < sz(candidates); j++){
                s += dot(candidates[j], word_info_d);
            }
            word_info word_info_copy = word_info_d;
            word_info_copy.s = s;
            //cout << "word_info_copy.word: " << word_info_copy.word << " s: " << word_info_copy.s << endl; 
            dictionary_vec.push_back(word_info_copy);
        }
        
        sort(all(dictionary_vec), cmp_word_info);
        if(sz(candidates) == 0) cout << '*' << endl;
        else cout << dictionary_vec[0].word << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}