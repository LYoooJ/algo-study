#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

struct Trie {
    map<string, Trie*> child;

    void insert(vector<string>& words, int idx) {
        if (idx == words.size()) return;

        string nxt_word = words[idx];
        if (child.find(nxt_word) == child.end()) child[nxt_word] = new Trie();

        child[nxt_word]->insert(words, idx + 1);
    }

    void print(int depth) {
        for (auto& node : child) {
            for (int i = 0; i < depth; ++i) cout << "--";
            cout << node.first << '\n';
            node.second->print(depth + 1);
        }
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    Trie t;
    while (n--) {
        int m;
        cin >> m;
        
        vector<string> words(m);
        for (int i = 0; i < m; ++i) cin >> words[i];

        t.insert(words, 0);
    }

    t.print(0);

    return 0;
}