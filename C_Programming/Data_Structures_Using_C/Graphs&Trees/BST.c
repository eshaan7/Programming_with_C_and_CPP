/*  Programmers' name: Eshaan Bansal (41816401518)
    Topic: 16. Write a program to implement BST: Insertion Deletion Search and all three types of Traversal.
*/

#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
	struct node *temp = (struct node*)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void inorder(struct node *root) 
{ 
	if (root != NULL) { 
		inorder(root->left); 
		printf("%d \n", root->key); 
		inorder(root->right); 
	} 
}


int searchTree(struct node *root, int data) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        if (data==root->key)
            return 1;
        inorder(root->right); 
    }
    return -1; 
}  

struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 

    return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 


int main() 
{ 
	int choice=0, x=0;
	struct node *root = NULL; 
	printf("-------MENU-------");
	printf("\n 1 - Insert");
    printf("\n 2 - Delete at i");
    printf("\n 3 - Inorder Traversal");
    printf("\n 4 - Search for element");
	printf("\n------------------");
    while (1)
    {
    printf("\n\tEnter Choice(1-4): ");
    scanf("%d", &choice);
    switch(choice)
    {
    	case 1:
    		printf("\nEnter element to push: ");
    		scanf("%d", &x);
    		root=insert(root, x);
    		break;
		case 2:
			printf("\nEnter element to delete: ");
    		scanf("%d", &x);
    		root=deleteNode(root, x);
    		break;

    	case 3:
    		printf("\nInorder Traversal: \n");
			inorder(root); 
			break;
			
		case 4:
            printf("\nEnter element to search: ");
            scanf("%d", &x);
            (searchTree(root, x))?printf("\n\tElement Found!"):printf("\n\tElement not found!");
            break;

        default:
            printf("\nInvalid option. Try again\n");
            break;
    }
    }
    return 0; 
} 
