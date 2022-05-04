#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> path;
vector<vector<int>> ans;

void graph_init(vector<vector<int>> &graph) {
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            cin >> graph[i][j];
        }
    }
}

void dfs(vector<vector<int>> &graph, vector<bool> &used, int v, int start) {
    if(used[v]) {
        if(v == start) {
            vector<int> path1 = path;
            path1.push_back(v);
            ans.push_back(path1);
        }
        return;
    }

    used[v] = 1;

    path.push_back(v);
    for(int i = 0; i < graph[v].size(); ++i)
        if(graph[v][i] == 1)
            dfs(graph, used, i, start);

    used[v] = 0;

    path.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int> (n));
    graph_init(graph);
    vector<bool> used(n, false);

    for(int i = 0; i < n; i++) {
        used.resize(n, 0);
        dfs(graph, used, i, i);
        path.clear();
    }

    sort(ans.begin(),ans.end(),
     [](vector<int>& a, vector<int>& b)
     { return a.size() > b.size(); });
    cout << "The longest cycle:\n";
    for (auto elem : ans[0]) {
        cout << elem << ' ';
    }
}