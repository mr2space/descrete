#include<stdio.h>
int orGate();
int andGate();
int main(){
    orGate();
    andGate();
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
