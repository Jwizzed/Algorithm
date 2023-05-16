#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
list<int> adj[1000];
int top_order[1000];
bool mark[1000];
queue<int> top_queue;


void dfs(int n, int s)
{
    mark[s] = true;
    for (int u : adj[s])
    {
        if (!mark[u])
        {
            dfs(n, u);
        }
    }
    top_queue.push(s);
}


void top_sort(int n)
{
    fill(mark, mark + n, false);
    for (int i = 0; i < n; i++){
        {
            if (!mark[i]){
                dfs(n, i);
            }
        }
    }
    for (int i = n - 1 ; i >= 0 ; i--){
        top_order[i] = top_queue.front();
        top_queue.pop();
    }
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
    }
    top_sort(n);
    for (int i = 0; i < n; i++)
    {
        cout << top_order[i] << endl;
    }
}