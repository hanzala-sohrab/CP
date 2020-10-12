#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define G Graph
#define E Edge
#define S Subset

class S {
    public:
        ll parent;
        ll rank;
};

class E {
    public:
        ll source;
        ll destination;
        ll weight;
};

class G {
    public:
        ll vertex;
        ll edge;
        E *e;
};

G *create_graph(ll vertex, ll edge) {
    G *g = new G;
    g -> e = new E[edge];
    g -> edge = edge;
    g -> vertex = vertex;
    return g;
}

ll find(S subs[], ll i) {
    if (subs[i].parent != i)
        subs[i].parent = find(subs, subs[i].parent);
    return subs[i].parent;
}

void _union(S subs[], ll x, ll y) {
    ll xr, yr;
    
    xr = find(subs, x);
    yr = find(subs, y);

    if (subs[xr].rank > subs[yr].rank)
        subs[yr].parent = xr;
    else if (subs[xr].rank < subs[yr].rank)
        subs[xr].parent = yr;
    else
    {
        subs[yr].parent = xr;
        ++subs[xr].rank;
    }
}

int foo(const void *a, const void *b) {
    E *c = (E*)a;
    E *d = (E*)b;
    return c -> weight < d -> weight;
}

ll weight_of_maximum_spanning_tree(G *g) {
    ll vertex = g -> vertex;
    E res[vertex];
    ll i = 0, j = 0, v;

    qsort(g -> e, g -> edge, sizeof(g -> e[0]), foo);

    S *subs = new S[vertex * sizeof(S)];

    F(v,0,vertex-1)
    {
        subs[v].parent = v;
        subs[v].rank = 0;
    }

    while (i < vertex - 1 and j < g -> edge)
    {
        E ne = g -> e[j++];
        ll x = find(subs, ne.source);
        ll y = find(subs, ne.destination);
        if (x != y)
        {
            res[i++] = ne;
            _union(subs, x, y);
        }
    }
    ll weight_of_mst = 0;
    F(j,0,i-1)
        weight_of_mst += res[j].weight;
    return weight_of_mst;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll N, D, i, j, k = 0, l, wt, M;
    I >> N >> D;
    ll points[N][D];
    F(i,0,N-1)
        F(j,0,D-1)
            I>>points[i][j];
    if (D == 1)
    {
        ll M1 = INT_MIN, m1 = INT_MAX;
        ll Mi1 = -1, mi1 = -1;
        F(i,0,N-1)
        {
            if (M1 < points[i][0])
            {
                M1 = points[i][0];
                Mi1 = i;
            }
            if (m1 > points[i][0])
            {
                m1 = points[i][0];
                mi1 = i;
            }
        }
        G *g = create_graph(N, 2 * N);
        k = 0;
        F(i,0,N-1)
        {
            if (i == mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        O << weight_of_maximum_spanning_tree(g) << '\n';
    }
    else if (D == 2)
    {
        ll M1 = INT_MIN, m1 = INT_MAX, M2 = INT_MIN, m2 = INT_MAX;
        ll Mi1 = -1, mi1 = -1, Mi2 = -1, mi2 = -1;
        F(i,0,N-1)
        {
            if (M1 < points[i][0] + points[i][1])
            {
                M1 = points[i][0] + points[i][1];
                Mi1 = i;
            }
            if (M2 < points[i][0] - points[i][1])
            {
                M2 = points[i][0] - points[i][1];
                Mi2 = i;
            }

            if (m1 > points[i][0] + points[i][1])
            {
                m1 = points[i][0] + points[i][1];
                mi1 = i;
            }
            if (m2 > points[i][0] - points[i][1])
            {
                m2 = points[i][0] - points[i][1];
                mi2 = i;
            }
        }
        G *g = create_graph(N, 4 * N);
        k = 0;
        F(i,0,N-1)
        {
            if (i == mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        O << weight_of_maximum_spanning_tree(g) << '\n';
    }
    else if (D == 3)
    {
        V<ll> p(8);
        ll M1 = INT_MIN, m1 = INT_MAX, M2 = INT_MIN, m2 = INT_MAX, M3 = INT_MIN, m3 = INT_MAX, M4 = INT_MIN, m4 = INT_MAX;
        ll Mi1 = -1, mi1 = -1, Mi2 = -1, mi2 = -1, Mi3 = -1, mi3 = -1, Mi4 = -1, mi4 = -1;
        F(i,0,N-1)
        {
            if (M1 < points[i][0] + points[i][1] + points[i][2])
            {
                M1 = points[i][0] + points[i][1] + points[i][2];
                Mi1 = i;
            }
            if (M2 < points[i][0] + points[i][1] - points[i][2])
            {
                M2 = points[i][0] + points[i][1] - points[i][2];
                Mi2 = i;
            }
            if (M3 < points[i][0] - points[i][1] + points[i][2])
            {
                M3 = points[i][0] - points[i][1] + points[i][2];
                Mi3 = i;
            }
            if (M4 < points[i][0] - points[i][1] - points[i][2])
            {
                M4 = points[i][0] - points[i][1] - points[i][2];
                Mi4 = i;
            }

            if (m1 > points[i][0] + points[i][1] + points[i][2])
            {
                m1 = points[i][0] + points[i][1] + points[i][2];
                mi1 = i;
            }
            if (m2 > points[i][0] + points[i][1] - points[i][2])
            {
                m2 = points[i][0] + points[i][1] - points[i][2];
                mi2 = i;
            }
            if (m3 > points[i][0] - points[i][1] + points[i][2])
            {
                m3 = points[i][0] - points[i][1] + points[i][2];
                mi3 = i;
            }
            if (m4 > points[i][0] - points[i][1] - points[i][2])
            {
                m4 = points[i][0] - points[i][1] - points[i][2];
                mi4 = i;
            }
        }

        G *g = create_graph(N, 8 * N);
        k = 0;
        F(i,0,N-1)
        {
            if (i == mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi3)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi3;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi3][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi3)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi3;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi3][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi4)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi4;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi4][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi4)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi4;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi4][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        O << weight_of_maximum_spanning_tree(g) << '\n';
    }
    else if (D == 4)
    {
        ll M1 = INT_MIN, m1 = INT_MAX, M2 = INT_MIN, m2 = INT_MAX, M3 = INT_MIN, m3 = INT_MAX, M4 = INT_MIN, m4 = INT_MAX;
        ll M5 = INT_MIN, m5 = INT_MAX, M6 = INT_MIN, m6 = INT_MAX, M7 = INT_MIN, m7 = INT_MAX, M8 = INT_MIN, m8 = INT_MAX;
        ll Mi1 = -1, mi1 = -1, Mi2 = -1, mi2 = -1, Mi3 = -1, mi3 = -1, Mi4 = -1, mi4 = -1;
        ll Mi5 = -1, mi5 = -1, Mi6 = -1, mi6 = -1, Mi7 = -1, mi7 = -1, Mi8 = -1, mi8 = -1;
        F(i,0,N-1)
        {
            if (M1 < points[i][0] + points[i][1] + points[i][2] + points[i][3])
            {
                M1 = points[i][0] + points[i][1] + points[i][2] + points[i][3];
                Mi1 = i;
            }
            if (M2 < points[i][0] + points[i][1] + points[i][2] - points[i][3])
            {
                M2 = points[i][0] + points[i][1] + points[i][2] - points[i][3];
                Mi2 = i;
            }
            if (M3 < points[i][0] + points[i][1] - points[i][2] + points[i][3])
            {
                M3 = points[i][0] + points[i][1] - points[i][2] + points[i][3];
                Mi3 = i;
            }
            if (M4 < points[i][0] + points[i][1] - points[i][2] - points[i][3])
            {
                M4 = points[i][0] + points[i][1] - points[i][2] - points[i][3];
                Mi4 = i;
            }
            if (M5 < points[i][0] - points[i][1] + points[i][2] + points[i][3])
            {
                M5 = points[i][0] + points[i][1] + points[i][2] + points[i][3];
                Mi5 = i;
            }
            if (M6 < points[i][0] - points[i][1] + points[i][2] - points[i][3])
            {
                M6 = points[i][0] - points[i][1] + points[i][2] - points[i][3];
                Mi6 = i;
            }
            if (M7 < points[i][0] - points[i][1] - points[i][2] + points[i][3])
            {
                M7 = points[i][0] - points[i][1] - points[i][2] + points[i][3];
                Mi7 = i;
            }
            if (M8 < points[i][0] - points[i][1] - points[i][2] - points[i][3])
            {
                M8 = points[i][0] - points[i][1] - points[i][2] - points[i][3];
                Mi8 = i;
            }
            

            if (m1 > points[i][0] + points[i][1] + points[i][2] + points[i][3])
            {
                m1 = points[i][0] + points[i][1] + points[i][2] + points[i][3];
                mi1 = i;
            }
            if (m2 > points[i][0] + points[i][1] + points[i][2] - points[i][3])
            {
                m2 = points[i][0] + points[i][1] + points[i][2] - points[i][3];
                mi2 = i;
            }
            if (m3 > points[i][0] + points[i][1] - points[i][2] + points[i][3])
            {
                m3 = points[i][0] + points[i][1] - points[i][2] + points[i][3];
                mi3 = i;
            }
            if (m4 > points[i][0] + points[i][1] - points[i][2] - points[i][3])
            {
                m4 = points[i][0] + points[i][1] - points[i][2] - points[i][3];
                mi4 = i;
            }
            if (m5 > points[i][0] - points[i][1] + points[i][2] + points[i][3])
            {
                m5 = points[i][0] + points[i][1] + points[i][2] + points[i][3];
                mi5 = i;
            }
            if (m6 > points[i][0] - points[i][1] + points[i][2] - points[i][3])
            {
                m6 = points[i][0] - points[i][1] + points[i][2] - points[i][3];
                mi6 = i;
            }
            if (m7 > points[i][0] - points[i][1] - points[i][2] + points[i][3])
            {
                m7 = points[i][0] - points[i][1] - points[i][2] + points[i][3];
                mi7 = i;
            }
            if (m8 > points[i][0] - points[i][1] - points[i][2] - points[i][3])
            {
                m8 = points[i][0] - points[i][1] - points[i][2] - points[i][3];
                mi8 = i;
            }
        }

        G *g = create_graph(N, 16 * N);
        k = 0;
        F(i,0,N-1)
        {
            if (i == mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi3)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi3;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi3][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi3)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi3;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi3][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi4)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi4;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi4][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi4)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi4;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi4][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi5)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi5;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi5][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi5)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi5;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi5][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi6)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi6;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi6][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi6)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi6;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi6][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi7)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi7;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi7][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi7)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi7;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi7][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi8)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi8;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi8][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi8)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi8;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi8][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        O << weight_of_maximum_spanning_tree(g) << '\n';
    }
    else if (D == 5)
    {
        ll M1 = INT_MIN, m1 = INT_MAX, M2 = INT_MIN, m2 = INT_MAX, M3 = INT_MIN, m3 = INT_MAX, M4 = INT_MIN, m4 = INT_MAX;
        ll M5 = INT_MIN, m5 = INT_MAX, M6 = INT_MIN, m6 = INT_MAX, M7 = INT_MIN, m7 = INT_MAX, M8 = INT_MIN, m8 = INT_MAX;
        ll M9 = INT_MIN, m9 = INT_MAX, M10 = INT_MIN, m10 = INT_MAX, M11 = INT_MIN, m11 = INT_MAX, M12 = INT_MIN, m12 = INT_MAX;
        ll M13 = INT_MIN, m13 = INT_MAX, M14 = INT_MIN, m14 = INT_MAX, M15 = INT_MIN, m15 = INT_MAX, M16 = INT_MIN, m16 = INT_MAX;
        ll Mi1 = -1, mi1 = -1, Mi2 = -1, mi2 = -1, Mi3 = -1, mi3 = -1, Mi4 = -1, mi4 = -1;
        ll Mi5 = -1, mi5 = -1, Mi6 = -1, mi6 = -1, Mi7 = -1, mi7 = -1, Mi8 = -1, mi8 = -1;
        ll Mi9 = -1, mi9 = -1, Mi10 = -1, mi10 = -1, Mi11 = -1, mi11 = -1, Mi12 = -1, mi12 = -1;
        ll Mi13 = -1, mi13 = -1, Mi14 = -1, mi14 = -1, Mi15 = -1, mi15 = -1, Mi16 = -1, mi16 = -1;
        F(i,0,N-1)
        {
            if (M1 < points[i][0] + points[i][1] + points[i][2] + points[i][3] + points[i][4])
            {
                M1 = points[i][0] + points[i][1] + points[i][2] + points[i][3] + points[i][4];
                Mi1 = i;
            }
            if (M2 < points[i][0] + points[i][1] + points[i][2] + points[i][3] - points[i][4])
            {
                M2 = points[i][0] + points[i][1] + points[i][2] + points[i][3] - points[i][4];
                Mi2 = i;
            }
            if (M3 < points[i][0] + points[i][1] + points[i][2] - points[i][3] + points[i][4])
            {
                M3 = points[i][0] + points[i][1] + points[i][2] - points[i][3] + points[i][4];
                Mi3 = i;
            }
            if (M4 < points[i][0] + points[i][1] + points[i][2] - points[i][3] - points[i][4])
            {
                M4 = points[i][0] + points[i][1] + points[i][2] - points[i][3] - points[i][4];
                Mi4 = i;
            }
            if (M5 < points[i][0] + points[i][1] - points[i][2] + points[i][3] + points[i][4])
            {
                M5 = points[i][0] + points[i][1] - points[i][2] + points[i][3] + points[i][4];
                Mi5 = i;
            }
            if (M6 < points[i][0] + points[i][1] - points[i][2] + points[i][3] - points[i][4])
            {
                M6 = points[i][0] + points[i][1] - points[i][2] + points[i][3] - points[i][4];
                Mi6 = i;
            }
            if (M7 < points[i][0] + points[i][1] - points[i][2] - points[i][3] + points[i][4])
            {
                M7 = points[i][0] + points[i][1] - points[i][2] - points[i][3] + points[i][4];
                Mi7 = i;
            }
            if (M8 < points[i][0] + points[i][1] - points[i][2] - points[i][3] - points[i][4])
            {
                M8 = points[i][0] + points[i][1] - points[i][2] - points[i][3] - points[i][4];
                Mi8 = i;
            }
            if (M9 < points[i][0] - points[i][1] + points[i][2] + points[i][3] + points[i][4])
            {
                M9 = points[i][0] - points[i][1] + points[i][2] + points[i][3] + points[i][4];
                Mi9 = i;
            }
            if (M10 < points[i][0] - points[i][1] + points[i][2] + points[i][3] - points[i][4])
            {
                M10 = points[i][0] - points[i][1] + points[i][2] + points[i][3] - points[i][4];
                Mi10 = i;
            }
            if (M11 < points[i][0] - points[i][1] + points[i][2] - points[i][3] + points[i][4])
            {
                M11 = points[i][0] - points[i][1] + points[i][2] - points[i][3] + points[i][4];
                Mi11 = i;
            }
            if (M12 < points[i][0] - points[i][1] + points[i][2] - points[i][3] - points[i][4])
            {
                M12 = points[i][0] - points[i][1] + points[i][2] - points[i][3] - points[i][4];
                Mi12 = i;
            }
            if (M13 < points[i][0] - points[i][1] - points[i][2] + points[i][3] + points[i][4])
            {
                M13 = points[i][0] - points[i][1] - points[i][2] + points[i][3] + points[i][4];
                Mi13 = i;
            }
            if (M14 < points[i][0] - points[i][1] - points[i][2] + points[i][3] - points[i][4])
            {
                M14 = points[i][0] - points[i][1] - points[i][2] + points[i][3] - points[i][4];
                Mi14 = i;
            }
            if (M15 < points[i][0] - points[i][1] - points[i][2] - points[i][3] + points[i][4])
            {
                M15 = points[i][0] - points[i][1] - points[i][2] - points[i][3] + points[i][4];
                Mi15 = i;
            }
            if (M16 < points[i][0] - points[i][1] - points[i][2] - points[i][3] - points[i][4])
            {
                M16 = points[i][0] - points[i][1] - points[i][2] - points[i][3] - points[i][4];
                Mi16 = i;
            }
            

            if (m1 > points[i][0] + points[i][1] + points[i][2] + points[i][3] + points[i][4])
            {
                m1 = points[i][0] + points[i][1] + points[i][2] + points[i][3] + points[i][4];
                mi1 = i;
            }
            if (m2 > points[i][0] + points[i][1] + points[i][2] + points[i][3] - points[i][4])
            {
                m2 = points[i][0] + points[i][1] + points[i][2] + points[i][3] - points[i][4];
                mi2 = i;
            }
            if (m3 > points[i][0] + points[i][1] + points[i][2] - points[i][3] + points[i][4])
            {
                m3 = points[i][0] + points[i][1] + points[i][2] - points[i][3] + points[i][4];
                mi3 = i;
            }
            if (m4 > points[i][0] + points[i][1] + points[i][2] - points[i][3] - points[i][4])
            {
                m4 = points[i][0] + points[i][1] + points[i][2] - points[i][3] - points[i][4];
                mi4 = i;
            }
            if (m5 > points[i][0] + points[i][1] - points[i][2] + points[i][3] + points[i][4])
            {
                m5 = points[i][0] + points[i][1] - points[i][2] + points[i][3] + points[i][4];
                mi5 = i;
            }
            if (m6 > points[i][0] + points[i][1] - points[i][2] + points[i][3] - points[i][4])
            {
                m6 = points[i][0] + points[i][1] - points[i][2] + points[i][3] - points[i][4];
                mi6 = i;
            }
            if (m7 > points[i][0] + points[i][1] - points[i][2] - points[i][3] + points[i][4])
            {
                m7 = points[i][0] + points[i][1] - points[i][2] - points[i][3] + points[i][4];
                mi7 = i;
            }
            if (m8 > points[i][0] + points[i][1] - points[i][2] - points[i][3] - points[i][4])
            {
                m8 = points[i][0] + points[i][1] - points[i][2] - points[i][3] - points[i][4];
                mi8 = i;
            }
            if (m9 > points[i][0] - points[i][1] + points[i][2] + points[i][3] + points[i][4])
            {
                m9 = points[i][0] - points[i][1] + points[i][2] + points[i][3] + points[i][4];
                mi9 = i;
            }
            if (m10 > points[i][0] - points[i][1] + points[i][2] + points[i][3] - points[i][4])
            {
                m10 = points[i][0] - points[i][1] + points[i][2] + points[i][3] - points[i][4];
                mi10 = i;
            }
            if (m11 > points[i][0] - points[i][1] + points[i][2] - points[i][3] + points[i][4])
            {
                m11 = points[i][0] - points[i][1] + points[i][2] - points[i][3] + points[i][4];
                mi11 = i;
            }
            if (m12 > points[i][0] - points[i][1] + points[i][2] - points[i][3] - points[i][4])
            {
                m12 = points[i][0] - points[i][1] + points[i][2] - points[i][3] - points[i][4];
                mi12 = i;
            }
            if (m13 > points[i][0] - points[i][1] - points[i][2] + points[i][3] + points[i][4])
            {
                m13 = points[i][0] - points[i][1] - points[i][2] + points[i][3] + points[i][4];
                mi13 = i;
            }
            if (m14 > points[i][0] - points[i][1] - points[i][2] + points[i][3] - points[i][4])
            {
                m14 = points[i][0] - points[i][1] - points[i][2] + points[i][3] - points[i][4];
                mi14 = i;
            }
            if (m15 > points[i][0] - points[i][1] - points[i][2] - points[i][3] + points[i][4])
            {
                m15 = points[i][0] - points[i][1] - points[i][2] - points[i][3] + points[i][4];
                mi15 = i;
            }
            if (m16 > points[i][0] - points[i][1] - points[i][2] - points[i][3] - points[i][4])
            {
                m16 = points[i][0] - points[i][1] - points[i][2] - points[i][3] - points[i][4];
                mi16 = i;
            }
        }

        G *g = create_graph(N, 32 * N);
        k = 0;
        F(i,0,N-1)
        {
            if (i == mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi1)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi1;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi1][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi2)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi2;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi2][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi3)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi3;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi3][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi3)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi3;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi3][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi4)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi4;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi4][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi4)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi4;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi4][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi5)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi5;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi5][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi5)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi5;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi5][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi6)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi6;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi6][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi6)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi6;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi6][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi7)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi7;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi7][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi7)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi7;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi7][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi8)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi8;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi8][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi8)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi8;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi8][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi9)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi9;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi9][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi9)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi9;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi9][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi10)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi10;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi10][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi10)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi10;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi10][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi11)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi11;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi11][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi11)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi11;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi11][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        
        F(i,0,N-1)
        {
            if (i == mi12)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi12;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi12][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi12)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi12;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi12][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi13)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi13;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi13][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi13)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi13;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi13][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi14)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi14;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi14][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi14)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi14;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi14][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi15)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi15;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi15][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi15)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi15;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi15][j]);
            g -> e[k].weight = wt;
            ++k;
        }

        F(i,0,N-1)
        {
            if (i == mi16)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = mi16;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[mi16][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        F(i,0,N-1)
        {
            if (i == Mi16)
                continue;
            g -> e[k].destination = i;
            g -> e[k].source = Mi16;
            wt = 0;
            F(j,0,D-1)
                wt += abs(points[i][j] - points[Mi16][j]);
            g -> e[k].weight = wt;
            ++k;
        }
        O << weight_of_maximum_spanning_tree(g) << '\n';
    }
    return 0;
}