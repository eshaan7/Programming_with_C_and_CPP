/* Programmers' name: Eshaan Bansal (41816401518)
   Topic: 17. Write a program to implement 
	        17.1. Min Heap.
	        17.2. Max Heap.
	        17.3. Heap Sort Using Min and Max Heap.
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int HEAP_SIZE = 20;

struct Heap{
    int *arr;
    int count;
    int capacity;
    int heap_type; // 0 for min heap, 1 for max heap
};

int parent(int i) { return (i-1)/2; } 
// to get index of left child of node at index i 
int left(int i) { return (2*i + 1); } 
// to get index of right child of node at index i 
int right(int i) { return (2*i + 2); } 

// Returns the minimum key (key at root) from min heap 
int getRoot(struct Heap *h) { return h->arr[0]; } 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

struct Heap *CreateHeap(int capacity, int heap_type) 
{
	/* Create new heap */
    struct Heap *h = (struct Heap*)malloc(sizeof(struct Heap)); 
    // check if memory allocation fails
    if(h == NULL) {
        printf("\n\tMemory Error!");
        exit(0);
    }
    h->heap_type = heap_type;
    h->count=0;
    h->capacity = capacity;
    h->arr = (int*)malloc(capacity*sizeof(int)); // allocating size to array in bytes
    //check if memory allocation fails
    if (h->arr == NULL){
        printf("\n\tMemory Error!");
        exit(0);
    }
    return h;
}

void insertKey(struct Heap* h, int k) 
{ 
    if (h->count == h->capacity) { 
        printf("\nOverflow: Could not insert Key.\n"); 
        return;
    } 
    // First insert the new key at the end 
    h->count++; 
    int i = h->count - 1; 
    h->arr[i] = k; 
 
    // Fix the min heap property if it is violated 
    if (h->heap_type == 0) {
	    while (i != 0 && h->arr[parent(i)] > h->arr[i]) { 
	       swap(&h->arr[i], &h->arr[parent(i)]); 
	       i = parent(i); 
    	}
    } 
    // Fix the max heap property if it is violated 
    else {
    	while (i != 0 && h->arr[parent(i)] < h->arr[i]) { 
	       swap(&h->arr[i], &h->arr[parent(i)]); 
	       i = parent(i); 
    	} 
    }
} 

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeapify(struct Heap* h, int n, int i)
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < n && h->arr[l] < h->arr[i]) 
        smallest = l;
    if (r < n && h->arr[r] < h->arr[smallest]) 
        smallest = r;
    if (smallest != i) { 
        swap(&h->arr[i], &h->arr[smallest]); 
        MinHeapify(h, n, smallest);
    } 
}

void MaxHeapify(struct Heap* h, int n, int i)
{ 
    int l = left(i); 
    int r = right(i); 
    int largest = i; 
    if (l < n && h->arr[l] > h->arr[i]) 
        largest = l;
    if (r < n && h->arr[r] > h->arr[largest]) 
        largest = r;
    if (largest != i) { 
        swap(&h->arr[i], &h->arr[largest]); 
        MaxHeapify(h, n, largest); 
    } 
}

// Changes value of key at index 'i' to new_val. It is assumed that 
// new_val is smaller than harr[i]. 
void ChangeKey(struct Heap *h, int i, int new_val) 
{ 
    h->arr[i] = new_val;
    while (i != 0 && h->arr[parent(i)] > h->arr[i]) { 
       swap(&h->arr[i], &h->arr[parent(i)]); 
       i = parent(i); 
    } 
} 
  
// Method to remove root from heap 
void delRoot(struct Heap* h) 
{
    if (h->count <= 0) {
        printf("\nUnderflow: Could not delete Key.\n"); 
    	return;
    }
    if (h->count == 1) { 
        h->count--; 
        return;
    } 
    // Store the minimum value, and remove it from heap 
    int root = h->arr[0];
    h->arr[0] = h->arr[h->count-1]; 
    h->count--;
    if (h->heap_type == 0)	
    	MinHeapify(h, h->count, 0); 
    else
    	MaxHeapify(h, h->count, 0);
} 

// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls delMin() 
void deleteKey(struct Heap *h, int i) 
{ 
    ChangeKey(h, i, INT_MIN);
    delRoot(h); 
} 

void printHeap(struct Heap *h)
{
    printf("\n\tHeap: ");
    for(int i=0; i<h->count; i++) {
        printf("%d->",h->arr[i]);
    }
    printf("NULL\n");
}

// main function to do heap sort 
void heapSort(struct Heap *h) 
{ 
	int n = h->count;
    // One by one extract an element from heap 
    if (h->heap_type == 1) {
	    for (int i=n-1; i>=0; i--) { 
	        // Move current root to end 
	        swap(&h->arr[0], &h->arr[i]); 
	        // call Max Heapify on the reduced heap 
	        MaxHeapify(h, i, 0); 
	    }
	}
	else {
		for (int i=n-1; i>=0; i--) { 
	        // Move current root to end 
	        swap(&h->arr[0], &h->arr[i]);
	        // call Min Heapify on the reduced heap 
	        MinHeapify(h, i, 0); 
	    }
	}
} 

void printMENU()
{
	printf("\n\t--------MENU--------");
    printf("\n\t0. Print this Menu");
	printf("\n\t1. Create Heap");
	printf("\n\t2. Print Heap");
	printf("\n\t3. Insert element");	
	printf("\n\t4. Delete element at ith index");
	printf("\n\t5. Delete root element");
	printf("\n\t6. Print root element");
	printf("\n\t7. Change element");
	printf("\n\t8. Heap Sort");
	printf("\n\t9. Exit");
	printf("\n\t--------------------");
}

int main() 
{ 
    int choice, x, i;
    struct Heap *h = NULL;
   	printMENU();
    do {
	choice=0;
	printf("\nEnter choice(1-8): ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 0: // prints menu of options
			printMENU();
			break;

		case 1: // Create Heap
			printf("\tEnter Heap Size: ");
            scanf("%d", &x);
            printf("\tEnter Heap type(0: Min Heap, 1: Max Heap) >> ");
            scanf("%d", &i);
			h = CreateHeap(x, i);
			break;

		case 2: // Print Heap
			printHeap(h);
			break;

		case 3: // Insert element
			printf("\tEnter element to insert: ");
            scanf("%d", &x);
			insertKey(h, x);
			break;

		case 4: // Delete key at index 'i'
			printf("\tEnter element index to delete: ");
            scanf("%d", &i);
			deleteKey(h, i);
			break;

		case 5: // Delete min (or root) element
			delRoot(h);
			printf("\tRoot element deleted\n");
			printHeap(h);
			break;

		case 6: // Display Root element
			printf("\tRoot element: %d\n", getRoot(h));
			break;

		case 7: // Change an element
			printHeap(h);
			printf("\tEnter element index to change: ");
            scanf("%d", &i);
			printf("\tEnter new element: ");
            scanf("%d", &x);
            ChangeKey(h, i, x);
			printHeap(h);
			break;

		case 8: // Heap Sort
			printHeap(h);
			heapSort(h);
			printf("After Heap Sort,\n");
			printHeap(h);
			break;
		case 9: // terminates program with status code of zero
			exit(0);
			break;

		default:
			printf("\nInvalid input. Please try again.\n\n");
			break;

	}
	} while (1);
	return 0;
}
