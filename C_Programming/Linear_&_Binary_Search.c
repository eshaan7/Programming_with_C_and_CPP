/* Programmers' name: Eshaan Bansal (41816401518)
   Date: 04/04/2019
   Topic: 19. Write a program to implement 
            19.1. Linear Search. 
            19.2. Binary Search.
*/

#include <stdio.h> 


// A linear search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1   
int linearSearch(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) // if ith element matches with given data
            return i; 
    return -1; 
} 

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
  
  
int main() 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 10; // data to search for 
    int n = sizeof(arr) / sizeof(arr[0]); // n stores size of array
    printf("\nLinear search: \n");
    int result1 = linearSearch(arr, n, x); 
    (result1 == -1) ? printf("\tElement is not present in array") 
                   : printf("\tElement is present at index %d", 
                            result1); 

    printf("\nBinary search: \n");
    int result2 = binarySearch(arr, 0, n - 1, x); 
    (result2 == -1) ? printf("\tElement is not present in array") 
                   : printf("\tElement is present at index %d", 
                            result2); 
    return 0; 
} 