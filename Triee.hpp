//
//  Triee.hpp
//  Kruskal's Algorithm MST DS Project
//
//  Created by Mario on 12/12/20.
//  Copyright © 2020 Mario. All rights reserved.
//

#ifndef Triee_hpp
#define Triee_hpp

#include <stdio.h>
#pragma once
#include <string.h>
#include<iostream>
using namespace std;
class Trie
{
    static const int Max_Char = 26;
private:
    Trie* child[Max_Char];
    bool isLeaf;
public:
    Trie();
    Trie* getNode(void);       // to create the root
    void insert(Trie* root, string key);  // to insert the word in root
    bool search(Trie* root, string key);  // to search to the word in root
    bool prefix(Trie* root, string key);  // to search for prefix in root

};




#endif /* Triee_hpp */
