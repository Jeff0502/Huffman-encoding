#include "MinHeap.h"

int main(int argc, char const *argv[])
{
    int array[5], size = 5;

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Min-Heap array: ");
    print_heap(array, size);

    delete_node(array, 4, &size);

    printf("size: %d\n", size);

    printf("After deletion: ");
    print_heap(array, size);

    return 0;
}
