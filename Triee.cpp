//
//  Triee.cpp
//  Kruskal's Algorithm MST DS Project
//
//  Created by Mario on 12/12/20.
//  Copyright © 2020 Mario. All rights reserved.
//

#include "Triee.hpp"
#include <iostream>
using namespace std;

Trie::Trie()
{
    this->isLeaf = false;
    for (int i = 0; i < Max_Char; i++)
    {
        this->child[i] = NULL;
    }
}


Trie* Trie::getNode(void)  //create the node
{
    Trie* NodePointer = new Trie;

    NodePointer->isLeaf = false;

    for (int i = 0; i < 26; i++)
        NodePointer->child[i] = NULL;

    return NodePointer;
}
// instialize a word in a tree
void Trie::insert(Trie* root, string key)
{

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!root->child[index])
            root->child[index] = getNode();

        root = root->child[index];
    }
    // mark last node as leaf
    root->isLeaf = true;
}
bool Trie::search(Trie* root, string key)
{
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!root->child[index])
            return false;

        root = root->child[index];
    }
    return (root != NULL && root->isLeaf);
}
bool Trie::prefix(Trie* root, string key) {
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!root->child[index])
            return false;

        root = root->child[index];
    }
    return (root != NULL && root->child);
}
