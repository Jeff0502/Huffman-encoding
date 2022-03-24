#include "Encoder.h"

int *get_freq(char *in, char *distinct);

void print_codes(struct node *root, int out[], int top);

struct node *build_tree(char count_c[], int freq[], int size);

char *get_c(char *in, int size);

void encode(char input[], int size)
{
        int *freq, out[50], top = 0;

        char *char_in;

        char_in = get_c(input, size);

        size = strlen(char_in);

        freq = get_freq(input, char_in);

        struct node *root = build_tree(char_in, freq, size);

        print_codes(root, out, top);

        free(char_in);
        free(freq);
        
}

struct node *build_tree(char char_in[], int freq[], int size)
{
        struct node *left, *right, *top;

        struct minHeap *minH = create_dheap(char_in, freq, size);

        while(minH->size != 1){
                //Repeat until there is only one node left
                left = MH_pop(minH);
                right = MH_pop(minH);

                top = create_node('$', left->freq + right->freq);

                top->left = left;

                top->right = right;

                MH_push(minH, top);
        }

        //return the last node
        return MH_pop(minH);
}

void print_codes(struct node *root, int out[], int top)
{
        if(root->left){
                out[top] = 0;
                print_codes(root->left, out, top + 1);
        }

        if(root->right){
                out[top] = 1;
                print_codes(root->right, out, top + 1);
        }

        if(!(root->right) && !(root->left)){
                printf("%c: ", root->c);

                for(int i = 0; i < top; ++i)
                        printf("%d", out[i]);

                printf("\n");
        }
}

char *get_c(char *in, int size)
{
        int count = 0, top = 0, i;

        char buf[256] = "", c, *out;

        for(i = 0; i < size - 1; i++){
                c = in[i];

                buf[c] = c;
        }

        for(i = 0; i < 256; i++){
                if(buf[i] != 0)
                        count++;
        }

        out = malloc(count * sizeof(char));

        
        for(i = 0; i < 256; i++){
                if(buf[i] != 0 && buf[i] != '\0'){
                        out[top] =  buf[i];
                        top++;
                }     
        }

        out[top] = '\0';

        return out;
}

int *get_freq(char *in, char *distinct)
{
        //Get freq from string 
        int *out = malloc((sizeof(distinct) + 1) * sizeof(int));

        char ch;

        for(int i = 0; distinct[i] != '\0'; i++){
                ch = distinct[i];
                for(int j = 0; in[j] != '\0'; j++){
                        if(in[j] == ch)
                                out[i]++;
                }
        }

        return out;
}
