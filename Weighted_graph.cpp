#include "Weighted_graph.hpp"
#include<iostream>


Weighted_graph::Weighted_graph(int v, int e)
{
    if (v < 0 || e < 0   )
        cerr << "out of range" << endl;
    this->number_vertices = v;
    this->number_edges = e;
    node = new Node[v+1];
    edge = new Edge[number_edges];
    mySize = 0;
    for (int x = 0; x <= v; x++)
    {
        node[x].number_nodes = x;
    }

}
void Weighted_graph::insert_edge(int a, int b, int w)
{
    if (a<0 || a>number_vertices || b<0 || b>number_vertices)
    {
        cerr << "out of range" << endl;
        return; 
    }
    edge[mySize].from = a;
    edge[mySize].to = b;
    edge[mySize].weight = w;
    mySize++;
}


int Weighted_graph::Find_parent(int n)
{
    int isParent = node[n].node_ptr->number_nodes;
    if (isParent == n)
        return isParent;
    return Find_parent(isParent);
}
void Weighted_graph::Merge(int from, int to)
{
    int a = Find_parent(from);
    int b = Find_parent(to);
    node[a].node_ptr = &node[b];
}

void Weighted_graph::sort(Edge* e)
{
    int temp1;
    int temp2;
    int temp3;
    for (int x = 0; x < mySize; x++)
    {
        for (int y = 1; y < mySize - x; y++)
        {
            if (e[y - 1].weight>e[y].weight )
            {
                temp1 = e[y - 1].weight;
                e[y - 1].weight = e[y].weight;
                e[y].weight = temp1;

                temp2 = e[y - 1].from;
                e[y - 1].from = e[y].from;
                e[y].from = temp2;

                temp3 = e[y - 1].to;
                e[y - 1].to = e[y].to;
                e[y].to = temp3;
            }
            }
        }
    for (int x = 0; x < mySize; x++)
    {
        for (int y = 1; y < mySize-x; y++)
        {
            if (edge[y - 1].weight == edge[y].weight)
            {
                if (edge[y - 1].from > edge[y].from)
                {
                    temp1 = edge[y - 1].from;
                    edge[y - 1].from = edge[y].from;
                    edge[y].from = temp1;

                    temp3 = e[y - 1].to;
                    e[y - 1].to = e[y].to;
                    e[y].to = temp3;
                }
                
            }
        }
    }

}

void Weighted_graph::viewGraph()
{
    cout << "your graph: " << endl;
    for (int x = 0; x < mySize; x++)
    {
        cout << edge[x].from << " " << edge[x].to << " " << edge[x].weight << endl;
    }
}
void Weighted_graph::Kruskal_alg()
{
    int x, y;
    sort(edge);
    cout << endl;
    for (int i = 0; i < mySize; i++)
    {
        x = edge[i].from;
        y = edge[i].to;



        if (Find_parent(x) != Find_parent(y))
        {
            Merge(x, y);
            edge[i].AddToMST();
        }
    }
    

    
    
}
void Weighted_graph::Result()
{
    for (int i = 0; i < mySize; i++)
    {
        if (edge[i].isAdded)
        {
            cout << edge[i].from << " " << edge[i].to << " " << edge[i].weight << endl;
        }
    }

}
