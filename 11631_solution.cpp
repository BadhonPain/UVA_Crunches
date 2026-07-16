#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<double, ll, ll> tll;

vector<tll> edges;
vector<ll> parent;
vector<ll> component_size;

void initialize(ll N)
{
    parent.resize(N);
    component_size.assign(N, 1);

    for (ll i = 0; i < N; i++)
    {
        parent[i] = i;
    }
}

ll find_set(ll node)
{
    if (node == parent[node])
        return node;
    return parent[node] = find_set(parent[node]);
}

void make_set(ll node1, ll node2)
{
    ll parent1 = find_set(node1);
    ll parent2 = find_set(node2);

    if (parent1 != parent2)
    {
        if (component_size[parent1] > component_size[parent2])
        {
            parent[parent2] = parent1;
            component_size[parent1] += component_size[parent2];
        }
        else
        {
            parent[parent1] = parent2;
            component_size[parent2] += component_size[parent1];
        }
    }
}

int main()
{
    ll m, n;
    cin >> m >> n;

    initialize(m);
    ll total_cost = 0;     // Total Cost
    ll optimized_cost = 0; // MST cost

    while (1)
    {
        ll u, v, w;
        cin >> u >> v;
        if (u == 0 && v == 0)
            break;
        cin >> w;
        total_cost += w;
        edges.push_back({w,u,v});
    }

    sort(edges.begin(), edges.end());

    for (ll i = 0; i < ll(edges.size()); i++)
    {
        ll weight = get<0>(edges[i]);
        ll u = get<1>(edges[i]);
        ll v = get<2>(edges[i]);

        if (find_set(u) != find_set(v))
        {
            make_set(u, v);
            optimized_cost += weight;
        }
    }

    ll savings = total_cost - optimized_cost;
    cout << savings << endl;
}