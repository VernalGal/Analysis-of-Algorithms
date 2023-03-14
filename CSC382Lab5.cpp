#include<iostream>
using namespace std;

struct node 
{
    int vertex;
    node* next;
};


bool cycles = false;
bool* Visited;

class Graph 
{
private:
    node* headnodes;
    int n;
    int e;

public:

    Graph(int nodes) // construtor
    {
        n = nodes;
        headnodes = new node[n]; // headnodes is an array of nodes.
        for (int i = 0; i < n; i++)
        {
            headnodes[i].vertex = i;
            headnodes[i].next = 0;
        }
    }

    void create()
    {
        int vertex_1, vertex_2;
        cout << "Please enter the number of edges: ";
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cout << "Please enter the number of vertices (0-" << n - 1 << ") you want to connect: ";
            cin >> vertex_1 >> vertex_2;
            makeEdge(vertex_1, vertex_2);
            makeEdge(vertex_2, vertex_1);
        }

    }

    void makeEdge(int vertex_1, int vertex_2) 
    {

        node* newNode = new node;
        newNode->vertex = vertex_2;
        newNode->next = headnodes[vertex_1].next;
        headnodes[vertex_1].next = newNode;


    }
    
    
    
    void DFS(int father, int v)
    {
        Visited[v] = true;
        node* adjacent_node = headnodes[v].next;
        while (adjacent_node)
        {
            if (!Visited[adjacent_node->vertex])
                DFS(v, adjacent_node->vertex);
            else if (father != adjacent_node->vertex)
            {
                cycles = true;
            }
            adjacent_node = adjacent_node->next;
        }
    }

    
    
    
    void showGraph() 
    {

        node* showConnectedNode = new node;

        for (int i = 0; i < n; i++)
        {
            showConnectedNode = &headnodes[i];

            cout << "Connected vertice V" << i << ": { ";
            while (showConnectedNode != NULL)
            {
                cout << showConnectedNode->vertex << " ";
                showConnectedNode = showConnectedNode->next;

            }
            cout << " }";
            cout << endl;
        }

    }
};


int main()
{

    int n;
    cout << "Please enter the number of vertices you want to make: ";
    cin >> n;


    Graph G(n);
    int Nmbrcmpnts = 0;
    Visited = new bool[n];
    G.create();
    G.showGraph();

    for (int i = 0; i < n; i++)
    {

        Visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!Visited[j]) {
                G.DFS(0, j);
                Nmbrcmpnts++;
            }
        }
    }


    cout << "This graph has: " << Nmbrcmpnts << " components." << endl;
    if (cycles)
        cout << "This graph has 1 or more cycles: " << endl;
    else
        cout << "This graph has no cycles: " << endl;



    return 0;
}