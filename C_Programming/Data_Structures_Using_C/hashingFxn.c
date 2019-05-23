/* Programmers' name: Eshaan Bansal (41816401518)
   Topic: 18. Write 
        	18.1. a program to implement Hashing Functions: Linear, Quadratic and Chain Probing.
        	18.2. theory for 10 different Hashing Functions.
*/
    
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct item {
    int key;
    int value;
};

struct hashtable_item {
    int flag;
    struct item *data;
};

struct hashtable_item *arr;

int size = 0;

void init_array()
{
    for (int i = 0; i < max; i++) {
		arr[i].flag = 0;
		arr[i].data = NULL;
    }
}

int hashcode(int key) {
    return (key % MAX);
}

void insert(int new_key, int new_value)
{
    int index = hashcode(new_key);
    int i = index;
    struct item *new_item = (struct item*)malloc(sizeof(struct item));
    new_item->key = new_key;
    new_item->value = new_value;
    while (arr[i].flag == 1) {
	 	if (arr[i].data->key == new_key) {
	        printf("\nKey already exists, hence updating its value.\n");
			arr[i].data->value = new_value;
			return;
		}

		i = (i + 1) % MAX;

		if (i == index) {
			printf("\nHash table is full, cannot insert any more items. \n");
			return;
		}
    }
    arr[i].flag = 1;
    arr[i].data = new_item;
    size++;
    printf("\tKey (%d) has been inserted.\n", new_key);
} 

void remove_element(int key)
{
    int index = hashcode(key);
    int i = index;
    while (arr[i].flag != 0) {
	 	if (arr[i].flag == 1  &&  arr[i].data->key == key ) {
	        arr[i].flag = 2;
			arr[i].data = NULL;
			size--;
			printf("\tKey (%d) has been removed.\n", key);
			return;
	 	}
		i = (i + 1) % max;
		if (i == index)
			break;
    }
    printf("\tThis key does not exist.\n");
}

void display()
{
    for (int i = 0; i < max; i++) {
    	if ( arr[i].data == NULL) {
			printf("\nArray[%d] has no elements.", i);
		}
		else {
			printf("\narr[%d] = %d (key) & %d (value) ", i, arr[i].data->key, arr[i].data->value);
		}	
    }
}


int size_of_hashtable()
{
    return size;
}

int main()
{	
	int choice=0, key, value;
 	arr = (struct hashtable_item*)malloc(max*sizeof(struct hashtable_item));
	init_array();
	printf("---Implementation of Hash Table in C with Linear Probing---");
	printf("\n-------MENU-------");
	printf("\n1. Inserting item in the Hashtable"); 
    printf("\n2. Removing item from the Hashtable"); 
    printf("\n3. Check the size of Hashtable");
    printf("\n4. Display Hashtable");
    printf("\n5. Exit");
    printf("\n------------------");
 	do {
 	choice=0;
    printf("\nEnter your choice(1-5): ");
	scanf("%d", &choice);
	switch(choice) 
    {
		case 1:
			printf("\tEnter key and value: ");
			scanf("%d %d", &key, &value);
			insert(key, value);
			break;

		case 2:
			printf("\tEnter the key to delete: ");
			scanf("%d", &key);
			remove_element(key);
			break;

		case 3:
	      	printf("\tSize of Hashtable is: %d", size_of_hashtable());
		    break;

		case 4:  
			display();
		    break;

		case 5:
			exit(0);
			break;

		default:
		    printf("\n\tWrong Input. Please try again\n");
		    break;
	}
	} while(1);
	return 0;
}