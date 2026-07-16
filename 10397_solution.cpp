#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<double, ll, ll> tll;

vector<tll> edges;
vector<ll> parent;
vector<ll> component_size;

void initialize(vector<ll> &parent, vector<ll> &component_size, ll N)
{
    for (ll i = 1; i <= N; i++)
    {
        parent[i] = i;
        component_size[i] = 1;
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

double calculate_dist(pll pt1, pll pt2)
{
    ll x_ = pt1.first - pt2.first;
    ll y_ = pt1.second - pt2.second;
    return hypot(x_, y_);
}

int main()
{
    ll N;
    cin >> N;
    vector<pll> points;
    for (ll i = 1; i <= N; i++)
    {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    parent.resize(N + 1);
    component_size.resize(N + 1);
    initialize(parent, component_size, N);

    ll M;
    cin >> M;
    for (ll i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        make_set(u, v);
    }

    for (ll i = 0; i < N; i++)
    {
        for (ll j = i + 1; j < N; j++)
        {
            edges.push_back({calculate_dist(points[i], points[j]), i + 1, j + 1});
        }
    }

    sort(edges.begin(), edges.end());
    double cost = 0;

    for (ll i = 0; i < ll(edges.size()); i++)
    {
        double weight = get<0>(edges[i]);
        ll u = get<1>(edges[i]);
        ll v = get<2>(edges[i]);

        if (find_set(u) != find_set(v))
        {
            make_set(u, v);
            cost += weight;
        }
    }
    cout << setprecision(3) << cost << endl;
}