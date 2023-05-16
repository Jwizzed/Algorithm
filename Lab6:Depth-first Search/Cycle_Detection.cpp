#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

list<int> adj[1000];

int pre[1000];
int post[1000];
bool mark[1000];

int dfs_clock = 0;

void dfs(int n, int s)
{
    mark[s] = true;
    pre[s] = dfs_clock;
    dfs_clock++;
    for (int u : adj[s])
    {
        if (!mark[u])
        {
            dfs(n, u);
        }
    }
    post[s] = dfs_clock;
    dfs_clock++;
}

bool has_cycle(int n)
{
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            dfs(n, i);
        }
    }
    for (int i = 0; i < n; i++){
        for (int u : adj[i])
        {
            if (pre[u] < pre[i] && post[i] < post[u])

            {
                return true;
            }

        }
    }
    return false;

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

    if (has_cycle(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}