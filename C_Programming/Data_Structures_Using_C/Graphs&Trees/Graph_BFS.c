/* Programmers' name: Eshaan Bansal (41816401518)
   Topic: 21.1. Write a program to implement Graphs and their traversals: BFS and DFS
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int V;
int adj[MAX][MAX];
int state[MAX];
int queue[MAX], front = -1,rear = -1;

int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

void enqueue(int vertex)
{
	if(rear == MAX-1)
		printf("\nError: Queue Overflow");
	else {
		if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}

int dequeue()
{	
	if(front == -1 || front > rear){
		printf("\nError: Queue Underflow\n");
		exit(1);
	}
	int deleted_item = queue[front];
	front = front+1;
	return deleted_item;
}

void create_graph()
{	
	int count, max_edge, origin, destin;
 	printf("\nEnter number of vertices : ");
	scanf("%d", &V);
	max_edge = V*(V-1);
 	for(count=1; count<=max_edge; count++) {	
 		printf("\nEnter edge %d( -1 -1 to quit ): ",count);
		scanf("%d %d", &origin, &destin);
 		if((origin == -1) && (destin == -1))
			break;
 		if(origin>=V || destin>=V || origin<0 || destin<0) {
			printf("Error: Invalid edge!\n");
			count--;
		} 
		else { 
			adj[origin][destin] = 1;
		}
    }
}

void BFS(int v)
{
	enqueue(v);
	state[v] = waiting;
	while(!isEmpty_queue()) {	
		v = dequeue();
		printf("%d ",v);
		state[v] = visited;
		for(int i=0; i<V; i++) {
			if(adj[v][i] == 1 && state[i] == initial) {
				enqueue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}

void BF_Traversal() // Breadth First Traversal
{	
	int v;
	for(int i=0; i<V; i++)
		state[i] = initial;
	printf("\nEnter Start Vertex for BFS: ");
	scanf("%d", &v);
	BFS(v);
}

int main()
{
	create_graph();
	BF_Traversal();
	return 0;
}