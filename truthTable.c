#include<stdio.h>
int orGate();
int andGate();
int notGate();
int main(){
    orGate();
    andGate();
    notGate();
    return 0;
}


int andGate(){
    int a ,b;
    printf("Truth table of And \n");
    printf("  A | B | AB\n");
    for(a=0;a<2;a++){
        for(b=0;b<2;b++){
            printf("  %d | %d | %d\n",a,b,a&&b);
        }
    }
}

int orGate()
{
    int a, b;
    printf("Truth table of OR \n");
    printf("  A | B | AB\n");
    for (a = 0; a < 2; a++)
    {
        for (b = 0; b < 2; b++)
        {
            printf("  %d | %d | %d\n", a, b, a || b);
        }
    }
}

int notGate(){
    
    int a;
    printf("Truth table of NOT \n");
    printf(" A | not A \n");
    for (b = 0; b < 2; b++)
        {
            printf("  %d | %d \n", a, 1-a);
        }
}
    
