#include "Encoder.h"

int main(int argc, char const *argv[])
{
        int array[5], size = 0;

        insert(array, 3, &size);
        insert(array, 4, &size);
        insert(array, 9, &size);
        insert(array, 5, &size);
        insert(array, 2, &size);

        print_heap(array, size);

    return 0;
}
