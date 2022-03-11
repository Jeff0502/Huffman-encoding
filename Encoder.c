#include "Encoder.h"

void get_freq(char *in);

void encode(char *string)
{
        get_freq(string);
}

void get_freq(char *in)
{
        int i = 0;
        char j;

        unsigned int freq[128] = {0};

        do{
                j = in[i];
                i++;
                freq[(int)j]++;
        }while(j != '\0');

        for(i = 0; i < 128; i++){
               
                printf("%C: %i\n", (char)i, freq[i]);
        }
}
