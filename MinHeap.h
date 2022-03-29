#ifndef MINHEAP_H

#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{

        int data;

        char c;

	struct node *left, *right;
};

struct minHeap{
        unsigned size;

        unsigned capacity;

        struct  node **array;
};

int is_leaf(struct node *n);

struct minHeap *create_dheap(char *data, int freq[], int size);

struct node *create_node(char c, int freq);

void swap_nodes(struct node **a, struct node **b);

struct minHeap *create_heap(unsigned capacity);

void destroy_mh(struct minHeap *mh);

void heapify(struct minHeap *heap, int i);

void MH_push(struct minHeap *heap, struct node *node);

void print_heap(struct minHeap *heap);

struct node *MH_pop(struct minHeap *heap);

#endif
