/*  Programmer's name: Eshaan Bansal (Eshaan7)
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
		printf("%d ", root->key); 
		inorder(root->right); 
	} 
}

void preorder(struct node* root)
{
	if (root !=NULL ) {
		printf("%d ", root->key); 
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node* root) {
	if ( root!=NULL ) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->key); 
	}		
}
/* Compute the "height" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int findHeight(struct node* node)
{
	if ( node == NULL) return -1;
	int leftHeight = findHeight(node->left);
	int rightHeight = findHeight(node->right);
	if (leftHeight > rightHeight)
		return leftHeight+1;
	else 
		return rightHeight+1;
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

struct node* minValueNode(struct node* current) 
{ 
	if (current == NULL) {
		printf("\nError: Tree is empty.\n");
		return current;
	}
    else if (current->left != NULL) 
    	return current;
    // search in left subtree
    minValueNode(current->left);
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
    else { 
    	// node with no child 
    	if ( root->left == NULL && root->right ==NULL) {
    		free(root);
    		root = NULL;
    	}
        // node with only one child 
        else if (root->left == NULL) { 
            struct node *temp = root;
            root = root->right; 
            free(temp); 
        } 
        else if (root->right == NULL) { 
            struct node *temp = root;
            root = root->left; 
            free(temp); 
        } 
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
  		else {
	        struct node* temp = minValueNode(root->right); 
	        // Copy the inorder successor's content to this node 
	        root->key = temp->key; 
	        // Delete the inorder successor 
	        root->right = deleteNode(root->right, temp->key); 
		}    
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
    printf("\n 4 - Preorder Traversal");
    printf("\n 5 - Postorder Traversal");
    printf("\n 6 - Search for element");
    printf("\n 7 - Find Height of a node");
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
    		printf("\nPreorder Traversal: \n");
			preorder(root); 
			break;

		case 5:
    		printf("\nPostorder Traversal: \n");
			postorder(root); 
			break;
			
		case 6:
            printf("\nEnter element to search: ");
            scanf("%d", &x);
            (searchTree(root, x))?printf("\n\tElement Found!"):printf("\n\tElement not found!");
            break;

        case 7:
    		printf("\nHeight of given node: %d\n",findHeight(root));
			break;

        default:
            printf("\nInvalid option. Try again\n");
            break;
    }
    }
    return 0; 
} 
