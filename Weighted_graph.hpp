//
//  Weighted_graph.hpp
//  Kruskal's Algorithm MST DS Project
//
//  Created by Mario on 12/7/20.
//  Copyright © 2020 Mario. All rights reserved.
//

#ifndef Weighted_graph_hpp
#define Weighted_graph_hpp

#include <stdio.h>
#include<iostream>
#pragma once


using namespace std;
class Weighted_graph
{

    class Node
    {
    public:
        int number_nodes;
        Node* node_ptr;
        Node()
        {
            number_nodes=0 ;
            node_ptr = this;
            
        }
        ~Node()
        {
        };
    };
    class Edge
    {
    public:
        int from, to, weight;
        bool isAdded;
        Edge()
        {
            from = 0;
            to = 0;
            isAdded = false;
        }
        ~Edge()
        {

        }
        
        void AddToMST()
        {
            isAdded = true;
        }
        
    };

public:
    Node* node;
    Edge* edge;
    int number_vertices;
    int number_edges;
    int mySize ;
    Weighted_graph(int v, int e);
    int Find_parent(int node);
    void Merge(int from, int to);
    void sort(Edge *edge);
    void Kruskal_alg();
    void insert_edge(int a, int b, int w);
    void viewGraph();
    void Result();

};



#endif /* Weighted_graph_hpp */
