#include "Encoder.h"

char *code[256] = {0};

void print_huffcode(int size, char *input);

void print_hufftable(struct minHeap *c_len);

void print_codes(struct node *root);

void free_codes(char *input, int size);

int *get_freq(char *in, char *distinct);

void assign_codes(struct node *root, char out[], int top);

struct minHeap *get_code_len(char *distinct, int size);

struct node *build_tree(char count_c[], int freq[], int size);

char *get_distinct(char *in, int size);

void free_tree(struct node *root);

void free_tree(struct node *root)
{
       if(!is_leaf(root)){
               free_tree(root->left);
               free_tree(root->right);
        }

       else{
               free(root);
        }
}

void print_codes(struct node *root)
{
        if(root->left){
                print_codes(root->left);

        }

        if(root->right){
                print_codes(root->right);
        }

        if(is_leaf(root)){
                printf("%c: ", root->c);

                printf("%s", code[(int)root->c]);

                printf("\n");
        }
}

void encode(char input[], int size)
{
        int distinct_size = 0, *freq, top = 0;

        char out[50], *distinct;

        distinct = get_distinct(input, size);

        distinct_size = strlen(distinct);

        struct minHeap *c_len;

        freq = get_freq(input, distinct);

        struct node *root = build_tree(distinct, freq, distinct_size);

        assign_codes(root, out, 0);

        print_codes(root);

        c_len = get_code_len(distinct, distinct_size);

        destroy_mh(c_len);
        free_codes(distinct, distinct_size);
        free(distinct);
        free(freq);
        free_tree(root);
}

void print_hufftable(struct minHeap *c_len)
{
        struct node *j = MH_pop(c_len);

        printf("\t%c:%s\n", j->c, code[(int)j->c]);

}

void print_huffcode(int size, char *input)
{
        //To exclude the null character
        size--;

        for(int i = 0; i < size - 1; i++){
                printf("%s", code[(int)input[i]]);
        }

        printf("\n");

}

struct node *build_tree(char char_in[], int freq[], int size)
{
        struct node *left, *right, *top, *root;

        struct minHeap *minH = create_dheap(char_in, freq, size);

        while(minH->size != 1){
                //Repeat until there is only one node left
                left = MH_pop(minH);
                right = MH_pop(minH);

                top = create_node('$', left->data + right->data);

                top->left = left;

                top->right = right;

                MH_push(minH, top);
        }

        //return the last node
        root = MH_pop(minH);

        destroy_mh(minH);

        return root;
}

void free_codes(char *distinct, int size)
{
        for(int i = 0; i < size; i++){
              free(code[(int)distinct[i]]);
        }
}

void assign_codes(struct node *root, char out[], int top)
{
        if(root->left){
                out[top] = '0';
                assign_codes(root->left, out, top + 1);

        }

        if(root->right){
                out[top] = '1';
                assign_codes(root->right, out, top + 1);
        }

        if(is_leaf(root)){
                int len = strlen(out);

                code[root->c] = malloc(len * sizeof(char));

                if(code[root->c] == NULL){
                        fprintf(stderr, "Not enough memory\n");
                }

                strcpy(code[root->c], out);
        }
}

char *get_distinct(char *in, int size)
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

struct minHeap *get_code_len(char *distinct, int size)
{
        struct minHeap *code_len;

        struct node *n;

        char c;

        int len = 0;

        code_len = create_heap(size);

        for(int i = 0; distinct[i] != '\0'; i++){
                c = distinct[i];
                len = strlen(code[(int)c]);

                n = create_node(c, len);

                MH_push(code_len, n);
        }

        return code_len;
}