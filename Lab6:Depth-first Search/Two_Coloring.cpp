#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

list<int> adj[1000];
int color[1000];
bool mark[1000];

void dfs(int n,int s, int current_color)
{
    mark[s] = true;
    color[s] = current_color;

    for (int u : adj[s])
    {
        if (!mark[u])
        {
            dfs(n, u, 1 - current_color);
        }

    }
}


bool two_color(int n)
{
    fill(color, color + n, -1);
    fill(mark, mark + n, false);

    for (int i = 0; i < n; i++)
    {
        if (!mark[i])
        {
            dfs(n,i, 0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int u : adj[i])
        {
            if (color[i] == color[u])
            {
                return false;
            }
        }
    }

    return true;

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
        adj[b].push_back(a);
    }
    if (two_color(n))
    {
        cout << "true" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << color[i] << endl;
        }
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}