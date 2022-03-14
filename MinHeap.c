#include "MinHeap.h"

void swap_nodes(int *a, int *b)
{
    int i = *a;

    *a = *b;
    *b = i;
}

void heapify(int array[], int size, int i)
{
        int min = i, l = 2 * i + 1, r = 2 * i + 2;

        if(l < size && array[l] < array[min])
                min = l;

        if(r < size && array[r] < array[min])
                min = r;

        if(min != i){
                swap_nodes(&array[min], &array[i]);

                heapify(array, size, min);
        }
}

void insert(int heap[], int newNum, int *size)
{
        if (*size == 0){
                heap[0] = newNum;

                ++*size;
        }

        else{
                //sets last node (empty node) to the new num
                heap[*size] = newNum;

                ++*size;

                for (int i = *size / 2 - 1; i >= 0; i--){
                        heapify(heap, *size, i);
                }
        }
}

int pop(int heap[], int *size)
{
        int min = heap[0];

        swap_nodes(&heap[0], &heap[*size - 1]);

        --*size;

        for (int i = *size / 2 - 1; i >= 0; i--){
                heapify(heap, *size, i);
        }

        return min;
}

void build_tree(int heap[], int *size)
{
        // int internal_node = 0;

        // for(int i = 0; i < 2; i++)
        //         internal_node += pop();

        // insert(heap, internal_node, size);
}

void delete_node(int heap[], int num, int *size)
{
    int i;

    for(i = 0; i < *size; i++){
        if(num == heap[i]) break;
    }

    swap_nodes(&heap[i], &heap[*size - 1]);
    --*size;

    for (int i = *size / 2 - 1; i >= 0; i--){
        heapify(heap, *size, i);
    }
}

void print_heap(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);

  printf("\n");
}