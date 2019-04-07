#include<iostream.h>
#include<conio.h>


void create(int arr[], int n)
{
    cout<<"\n\n\tEnter the array elements: ";
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
}

void show(int arr[], int n)
{
    cout<<"\n\n\tElements of array: ";
    for (int i=0; i<n; i++) {
	    cout<<arr[i]<<" ";
    }
}
void bubsort(int arr[], int n) 
{
    int temp;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
	    if (arr[i]>arr[j]) {
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	    }
	}
    }
}

void main()
{
    clrscr();
    int arr[10],n;
    cout<<"\n\nEnter size of array: ";
    cin>>n;
    create(arr, n);
    show(arr, n);
    bubsort(arr, n);
    cout<<"\n\n\t\tAfter Bubble Sort: ";
    show(arr, n);
    getch();
}