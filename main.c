#include "Encoder.h"

int main(int argc, char const *argv[])
{
        char in[] = "Hello World";

        int sz = sizeof(in) / sizeof(in[0]);

        encode(in, sz);

        return 0;
}
