#include<stdio.h>
#include<stdlib.h>
int main(){
    unsigned char n[]={'A','l','f','r','e','d','o'};
    unsigned char count=0;
    for(unsigned char i = 0; i<sizeof(n); i++){
        for (unsigned char j = 128; j >0;j>>=1){
            if(n[i] & j){
                count +=1;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}