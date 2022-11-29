#include <stdio.h>
struct graph
{
    char start, end;
    int weight;
};

int graphInput(struct graph *g)
{
    printf("Enter the start char: ");
    scanf(" %c", &g->start);
    printf("Enter the end char: ");
    scanf(" %c", &g->end);
    printf("Enter the weight: ");
    scanf(" %d", &g->weight);
}

int graphArrayInput(struct graph *g, int len)
{
    int l = 0;
    for (l = 0; l < len; l++)
    {
        printf("Enter the value of graph %d \n",l+1);
        graphInput((g + l));
    }
}




int graphDisplay(struct graph *g,int len){
    int l = 0;
    for (l = 0; l < len; l++)
    {
        printf(" %c --- %d --- %c \n", (g + l)->start, (g + l)->weight, (g + l)->end);
    }

    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    struct graph g[size];
    graphArrayInput(g,3);
    printf(" \n graph is --- \n");
    graphDisplay(g,3);
     return 0;
}
