#ifndef MINHEAP_H

#define MINHEAP_H

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#include <stdio.h>

struct node{

        int freq;

        char c;
};

void swap_nodes(int *a, int *b);

void heapify(int array[], int size, int i);

void insert(int array[], int newNum);

void print_heap(int array[], int size);

void delete_node(int heap[], int num, int *size);

#endif