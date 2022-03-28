#include "MinHeap.h"

void build_heap(struct minHeap *mh);

int is_leaf(struct node *n)
{
        return (n->left == NULL && n->right == NULL);
}

void build_heap(struct minHeap *mh)
{
        int n = mh->size - 1, j;

        for (j = (n - 1) / 2; j >= 0; --j)
                heapify(mh, j);
}

struct node *create_node(char c, int freq)
{       
        struct node *i = malloc(sizeof(struct node));

        i->c = c;
        i->freq = freq;
        i->left = NULL;
        i->right = NULL;

        return i;
}

void destroy_mh(struct minHeap *mh)
{
        free(mh->array);
        free(mh);
}

struct minHeap *create_dheap(char *data, int freq[], int size)
{
        struct minHeap *i = create_heap(size);

        for(int j = 0; j < size; ++j){
                i->array[j] = create_node(data[j], freq[j]);
        }

        i->size = size;

        build_heap(i);

        return i;
}

struct minHeap *create_heap(unsigned capacity)
{
        struct minHeap *i = (struct minHeap *)malloc(sizeof(struct minHeap));

        i->size = 0;

        i->capacity = capacity;

        i->array = (struct node**)malloc(sizeof(struct node *) * i->capacity);

        return i;        
}

void swap_nodes(struct node **a, struct node **b)
{
        struct node *i = *a;

        *a = *b;
        *b = i;
}

void heapify(struct minHeap *heap, int i)
{
        int min = i, l = 2 * i + 1, r = 2 * i + 2;

        if(l < heap->size && heap->array[l]->freq < heap->array[min]->freq)
                min = l;

        if(r < heap->size && heap->array[r]->freq < heap->array[min]->freq)
                min = r;

        if(min != i){
                swap_nodes(&heap->array[min], &heap->array[i]);

                heapify(heap, min);
        }
}

void MH_push(struct minHeap *heap, struct node *node)
{
        ++heap->size;

        int i = heap->size - 1;
  
        while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
                heap->array[i] = heap->array[(i - 1) / 2];
                i = (i - 1) / 2;
        }
  
        heap->array[i] = node;
}

struct node *MH_pop(struct minHeap *heap)
{
        struct node *min = heap->array[0];

        swap_nodes(&heap->array[0], &heap->array[heap->size - 1]);

        --heap->size;

        heapify(heap, 0);

        return min;
}

void print_heap(struct minHeap *heap)
{
        for (int i = 0; i < heap->size; i++)
                printf("%d ", heap->array[i]->freq);

        printf("\n");
}
