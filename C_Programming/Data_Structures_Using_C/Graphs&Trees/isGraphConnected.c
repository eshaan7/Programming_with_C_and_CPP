/* Programmers' name: Eshaan Bansal (41816401518)
   Topic: 22. Write a program to check whether a Graph is connected or not.
*/

#include<stdio.h>

int a[20][20];
int visited[20];
int n;

void dfs(int v)
{
    visited[v]=1;
    for(int i=0; i<n; i++) {
        if(a[v][i] && !visited[i]) { 
            printf("\n%d->%d",v,i);
            dfs(i);
        }
    }
}

int main(){
    int n,i=0,j=0,count=0;

    printf("\nEnter no of vertices : ");
    scanf("%d",&n);

    // initializing with zero
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            visited[i]=0;
            a[i][j]=0;
        }
    }

    // input adjacency matrix
    printf("\nEnter adjacency matrix : \n");
    for(i=0;i<n;i++) {
        printf("[%d][] >> ", i);
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }  

    dfs(1);

    for(i=0;i<n;i++) {
        if(visited[i])
            count++;
    }

    if(count==n)
       printf("\nGraph is connected.\n");
    else
       printf("\nGraph is disconnected.\n");
    return 0;
}