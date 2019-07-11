#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashlp.h"

int M = 10; // default size of linear probing table

int N = 0; // number of key-value pairs in the table

int *keys;

float *vals;

enum empty{empty_slot = -1};

void init_hash(){
	int i;

	keys = (int *) malloc(sizeof(int) * M);
	vals = (float *) malloc(sizeof(float) * M);
	for (i = 0; i < M; i++){
		keys[i] = empty_slot;
		vals[i] = empty_slot;
	}
}


int hash(int k){
	int idx;
	idx =  (k & 0x7fffffff) % M;
	return idx;
}

int put(int k, float val){
	int i;
	int stop_cond;

	stop_cond = stop_condition_idx(k);
	for(i = hash(k); keys[i] != empty_slot; i = (i+1) % M){
		if(keys[i] == k)			
			break;
		
		if(i == stop_cond)
			return 0;
	}

	keys[i] = k;
	vals[i] = val;	
	N += 1; 

	return 1;
}

int stop_condition_idx(int k){
	int h_id;
	h_id = hash(k);
	if(h_id == 0){
		return M-1;
	}else{
		return h_id-1;
	}

}

void display(){

	int i;
	for(i = 0; i < M; i++){
		if(keys[i] != empty_slot)
			printf("h_tb[%d] = {key = %d, value = %f}\n", i, keys[i], vals[i]);
	}
}

void display_all(){

	int i;
	for(i = 0; i < M; i++){
		printf("h_tb[%d] = {key = %d, value = %f}\n", i, keys[i], vals[i]);
	}
}

void display_clusters(){
	int i;
	for(i = 0; i < M; i++){
		if(keys[i] != empty_slot)
			printf("*");
		else
			printf("_");
	}
	printf("\n");
}