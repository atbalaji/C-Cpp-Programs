#include<algorithm>
#include <iostream>
#include <list>
#include <stack>
#include<stdio.h>
using namespace std;
 
 
bool print = false ;
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // An array of adjacency lists
 
    // Fills Stack with vertices (in increasing order of finishing times)
    // The top element of stack has the maximum finishing time
    void fillOrder(int v, bool visited[], stack<int> &Stack);
 
    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
 
    // The main function that finds and prints strongly connected components
    void printSCCs();
 
    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 int n;
// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
   // cout << v << " ";
    if(print)
    	n++;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v�s list.
}
 
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
 
    // All vertices reachable from v are processed by now, push v to Stack
    Stack.push(v);
}
 
// The main function that finds and prints all strongly connected components
void Graph::printSCCs()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
 
    // Create a reversed graph
    Graph gr = getTranspose();
 
    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Now process all vertices in order defined by Stack
    int c =0 ;
    while (Stack.empty() == false)
    {
    	print = true ;
    	n=0;
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
 
        // Print Strongly connected component of the popped vertex
        if (visited[v] == false && v!=0)
        {
        	n=0;
            gr.DFSUtil(v, visited);
            cout << endl;
            cout<<n;
            
        }
    }
}
 
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    FILE *fp ;
	fp = fopen("SCC.txt","r");
    Graph g(875715);
   	char a[100];
	char b[100];
	int from,to;
	while((fscanf(fp,"%s",a))!=EOF){
	//cin>>to;
	fscanf(fp,"%s",b);
		string f(a),t(b);
		cout<<a<<" "<<b<<endl;
		from = atoi(f.c_str());
		to = atoi(t.c_str());
		g.addEdge(from,to);
	//	gra[from].push_back(to);
	//	gra_rev[to].push_back(from);
	}
   
 
    cout << "Following are strongly connected components in given graph \n";
    g.printSCCs();
 
    return 0;
}
