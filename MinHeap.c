#include "MinHeap.h"

int heap_size = 0;

void swap_nodes(int *a, int *b)
{
    int i = *a;

    *a = *b;
    *b = i;
}

void heapify(int array[], int size, int i)
{
        int min = i, l = 2 * i + 1, r = 2 * i + 2;

        if(l < size && l < array[min])
                min = l;

        if(r < size && r < array[min])
                min = r;

        if(min != i){
                swap_nodes(&array[min], &array[i]);

                heapify(array, size, min);
        }
}

void insert(int array[], int newNum)
{
        if (heap_size == 0){
                array[0] = newNum;

                heap_size += 1;
        }

        else{
                //sets last node (empty node) to the new num
                array[heap_size] = newNum;

                heap_size += 1;

                for (int i = heap_size / 2 - 1; i >= 0; i--){
                        heapify(array, heap_size, i);
                }
        }
}

void delete_node(int heap[], int num, int *size)
{
    int i;

    for(i = 0; i < *size; i++)
    {
        if(num == heap[i])
            break;
    }

    swap_nodes(&heap[i], &heap[*size - 1]);
    --*size;

    for (int i = *size / 2 - 1; i >= 0; i--)
    {
        heapify(heap, *size, i);
    }
}

void print_heap(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);

  printf("\n");
}