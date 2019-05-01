#include<stdio.h>
#include<string.h>

/*********************** count number of lines in a file ***********************/

// taking command line arguments

int main(int argc, char *argv[])	
{
	FILE *fp;
	char c;
	char filename[100];
	int count=0;
	//printf("%s\n", argv[1]);
	strcpy(filename, argv[1]);
	//scanf("%s", filename);
	fp=fopen(filename, "r");
	if (fp == NULL) {
        printf("Could not open file %s\n", filename);
       	return 1; // Undesired execution
    } 
	for(c=getc(fp); c!=EOF; c=getc(fp)) {
		if (c=='\n')
			count=count+1;
	}
	printf("\tCount is: %d\n",count);
	fclose(fp);
	return 0;
}
