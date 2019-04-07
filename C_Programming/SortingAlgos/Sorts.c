/* Programmers' name: Eshaan Bansal (41816401518)
   Date: 04/04/2019
   Topic: 20.Write a program to implement
	        20.1. Selection Sort.
	        20.2. Bubble Sort.
	        20.3. Insertion Sort.
	        20.4. Merge Sort
	        20.5. Quick Sort
*/

#include<stdio.h>
#include<stdlib.h>

void show(int *arr, int n)
{
    int i;
    printf("\n\tarr[] = ");
    for (i=0; i<n; i++) {
	    printf("%d ", arr[i]);
    }
    printf("\n");
}


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

/* Function to sort an array using selection sort */  
void selectionSort(int *arr, int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

/* Function to sort an array using Bubble sort */
void bubsort(int *arr, int n) 
{
    int temp, i, j;
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
    	    if (arr[i]>arr[j])
        		swap(&arr[i], &arr[j]);
	   }
    }
}


/* Function to sort an array using insertion sort */
void insertionSort(int arr[], int n) 
{ 
    int i, key, hole; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        hole = i-1;
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (hole >= 0 && arr[hole] > key) { 
            arr[hole + 1] = arr[hole];
            hole = hole - 1;
        } 
        arr[hole + 1] = key;
    } 
} 

/* Functions to sort an array using merge sort */

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int *A, int *L, int leftCount, int *R, int rightCount) {
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j<rightCount) {
		if(L[i] < R[j]) 
			A[k++] = L[i++];
		else 
			A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A, int n) {
	int mid,i, *L, *R; // L and R are left and right subarrays
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// `mid` elements (from index 0 till mid-1) should be part of left sub-array 
	// and `n-mid` elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n-mid)*sizeof(int)); 
	
	for(i=0; i<mid; i++) L[i] = A[i]; // creating left subarray
	for(i=mid; i<n; i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
	free(L);
    free(R);
}


/* Functions to sort an array using Quick Sort */

/* This function takes last element as pivot,
   and Pindex is the start or array. 
   runs loop for arr[l..r-1] swapping every element 
   smaller than pivot element to the the left of Pindex. */

int partition(int arr[], int l, int r)
{
	int pivotEl = arr[r];
	int Pindex = l;
	int i;
	for (i=l; i<r; i++) {
		if (arr[i] <= pivotEl) {
			swap(&arr[Pindex], &arr[i]);
			Pindex++;
		}
	}
	swap(&arr[Pindex], &arr[r]);
	return Pindex;
}

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
 start --> Starting index, 
 end --> Ending index */
void quickSort(int arr[], int start, int end) 
{ 
    if (start < end) {
        /* Pindex is partitioning index, arr[p] is now 
           at right place */
        int Pindex = partition(arr, start, end);
        // Separately sort elements before 
        // partition and after partition
        quickSort(arr, start, Pindex-1); 
        quickSort(arr, Pindex+1, end); 
    } 
} 

// taking command line argument for choice 
int main(int argc, char **argv)
{
    int arr[] = {5, 9, 1, 4, 2, 0};
    int n=6;
    int choice=atoi(argv[1]);
    /*
    printf("\n-------MENU-------");
	printf("\n 1 - Bubble Sort");
    printf("\n 2 - Selection Sort");
    printf("\n 3 - Insertion Sort");
    printf("\n 4 - Merge Sort");
    printf("\n 5 - Quick Sort");
    printf("\n 6 - Exit");
    printf("\n------------------");
    */
    printf("\n\tYour Choice(1-6): %d", choice);
    switch(choice)
    {
    	case 1:
		    bubsort(arr, n);
		    printf("\n\tAfter Bubble Sort: ");
		    show(arr, n);
		    break;

		case 2: 
		    selectionSort(arr, n);
		    printf("\n\tAfter selection Sort: ");
		    show(arr, n);
		    break;

		case 3:
		    insertionSort(arr, n);
		    printf("\n\tAfter insertion Sort: ");
		    show(arr, n);
		    break;

		case 4:
		    MergeSort(arr, n);
		    printf("\n\tAfter Merge Sort: ");
		    show(arr, n);
		    break;
		
		case 5:
    		quickSort(arr, 0, n-1);
    		printf("\n\tAfter quick Sort: ");
    		show(arr, n);
    		break;
    	
    	case 6:
    		exit(0);
    		break;
    	
    	default:
    		printf("\n\tInvalid option. Try again.\n");
    		break;
    }
    return 0;
}