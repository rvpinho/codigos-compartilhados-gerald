#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashlp.h"

extern int M; // size of linear probing table

int main(){

	int i, sum_cost;
	srand(time(0));

	M = 5; // You can set the size of hash tab.

	init_hash();

	// Adding key-values

	put(10, 5.1);
	put(16, 3);
	put(22, 34.75);
	put(34, 34.75);

	printf("Displaying only inseted key-values \n\n");
	display();

	printf("Displaying all hash table \n\n");
	display_all();

	printf("Displaying hash table as '*'' and '_' respectivelly occupied and empty slots.\n\n");
	display_clusters();


	//You also can check the insertion
	if( put(123456, 1.2) == 0 ){
		printf("Error: table is full.\n");
	}else{
		printf("key-value inserted.\n");
	}

	if( put(33242, 34.75) == 0 ){
		printf("Table is full.\n");
	}else{
		printf("key-value inserted.\n");
	}
	
	
	return 0;
}