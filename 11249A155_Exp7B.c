#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    return p1[2] - p2[2];
}

void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}

void unionSet(int u, int v, int parent[], int rank[])
{
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int n, int edge[][3])
{
    qsort(edge, n, sizeof(edge[0]), comparator);

    int parent[n];
    int rank[n];
    makeSet(parent, rank, n);

    int minCost = 0;

    printf("Following are the edges in the constructed MST\n");

    for (int i = 0; i < n; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);

        if (setU != setV)
        {
            printf("%d -- %d == %d\n", u, v, wt);
            minCost += wt;
            unionSet(setU, setV, parent, rank);
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main()
{
    int edge[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalAlgo(5, edge);

    return 0;
}
