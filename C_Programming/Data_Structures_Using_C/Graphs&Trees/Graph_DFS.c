/* Programmers' name: Eshaan Bansal (41816401518)
   Topic: 21.2. Write a program to implement Graphs and their traversals: BFS and DFS
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjList;
};

struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);
void DFS(struct Graph*, int);


int main()
{
    int number_of_vertices, choice=0, ver1, ver2, ver3;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&number_of_vertices);
    struct Graph* graph = createGraph(number_of_vertices);
    printf("\n1.Add Edge\n2.Print Graph\n3.DFS Traversal\n4.Exit");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter first vertex to add edge: ");
            scanf("%d",&ver1);
            printf("Enter second vertex to add edge: ");
            scanf("%d",&ver2);
            addEdge(graph,ver1,ver2);
            break;
        case 2:
            printGraph(graph);
            break;
        case 3:
            printf("Enter the vertex to initiate DFS: ");
            scanf("%d",&ver3);
            DFS(graph, ver3);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice Entered. Please try again.");
            break;
        }
    }
    return 0;
}


void DFS(struct Graph* graph, int startVertex) 
{
    struct node* temp = graph->adjList[startVertex];
    graph->visited[startVertex] = 1;
    printf("Visited %d\n", startVertex);
    while(temp!=NULL) {
        int connectedVertex = temp->vertex;
        if(graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}


struct node* createNode(int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjList = malloc(vertices*sizeof(struct node*));

    graph->visited = malloc(vertices*sizeof(int));
    for (int i=0; i<vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
    for (int v = 0; v <(graph->numVertices); v++) {
        struct node* temp = graph->adjList[v];
        printf("\nAdjacency list of vertex [%d]: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


