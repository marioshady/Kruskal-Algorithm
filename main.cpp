#include <iostream>
#include"Weighted_graph.hpp"

using namespace std;

int main()
{
    string companyname,managername;
    cout<<"Please enter the Company Name"<<endl;
    cin>>companyname;
    
    cout<<"Please enter your name"<<endl;
    cin>>managername;
    
    int numberofnodes,numberofedges;
    cout<<"Please enter how many nodes or cities do you have"<<endl;
    cin>>numberofnodes;
    cout<<"Please enter how many connection from one city to another do we have"<<endl;
    cin>>numberofedges;
    int edgecounter=0;
    
    Weighted_graph graph(numberofnodes,numberofedges);
    
    for(int i=0; i<numberofnodes; i++)
    {
        int numberofnodesfromthisnode;
        cout<<"Please enter how many connections from the city "<<i<<" are there?"<<endl;
        cin>>numberofnodesfromthisnode;
        for(int x=0; x<numberofnodesfromthisnode;x++)
        {
            if(edgecounter<numberofedges)
            {
            int whichnode,weightnode;
            cout<<"Which node is "<<i<<" connected to?"<<endl;
            cin>>whichnode;
            
            cout<<"Please enter the distance between "<<i<<" and "<<whichnode<<endl;
            cin>>weightnode;
            graph.insert_edge(i, whichnode, weightnode);
            edgecounter++;
            }
            else
            {
                cerr<<"You have reached your edges end"<<endl;
            }
        }
    }
    
    
    
    cout<<"Hello Mr. "<<managername<<endl;
    cout<<"Here are the full network of "<<companyname<<endl;
    graph.viewGraph();
    
    graph.Kruskal_alg();
    
    cout<<"And here is the most efficient way to connect the cables of your networking company"<<endl;
    graph.Result();

  
    return 0;
}


