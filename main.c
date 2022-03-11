#include "Encoder.h"

int main(int argc, char const *argv[])
{
    int array[5], size = ARRAY_SIZE(array);

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    return 0;
}
