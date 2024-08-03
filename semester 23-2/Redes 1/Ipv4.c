#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    unsigned char IP[]={225,1,1,1};
    unsigned char MR[]={0xFF,0,0,0};
    int nbits= 0;
    printf("%d %d\n",100,0111);
    printf("IP: %d.%d.%d.%d \n",IP[0],IP[1],IP[2],IP[3]);
    printf("HEX: %x.%x.%x.%x \n",IP[0],IP[1],IP[2],IP[3]);
    printf("BIN: %b %b %b %b \n",IP[0],IP[1],IP[2],IP[3]);
    printf("BIN: %b %b %b %b \n",MR[0],MR[1],MR[2],MR[3]);
    if(IP[0]&128){
        if(IP[0]&64){
            if(IP[0]&32){
                if(IP[0]&16){
                    printf("Es clase E\n");
                }
                else printf("Es clase D\n");
            }
            else{
                printf("Es clase C\n");
                MR[1]=0xFF, MR[2]=255;
                printf("MR: %d.%d.%d.%d\n",MR[0],MR[1],MR[2],MR[3]);
            } 

        }
        else{
            printf("Es clase B\n");
            MR[1]=0xFF;
            printf("MR: %d.%d.%d.%d\n",MR[0],MR[1],MR[2],MR[3]);
        } 
    }
    else{
        printf("Es clase A\n");
        printf("MR: %d.%d.%d.%d\n",MR[0],MR[1],MR[2],MR[3]);
    } 
    unsigned char bro[]={IP[0] | ~MR[0], IP[1] | ~MR[1], IP[2] | ~MR[2], IP[3] | ~MR[3]};
    
    //Calculo ip madre
    printf("Rango de: ");
    printf("%d.%d.%d.%d ",IP[0],IP[1]&MR[1],IP[2]&MR[2],IP[3]&MR[3]);
    
    
    //printf("%d.%d.%d.%d ",(unsigned char)( IP[0] | ~MR[0]),(unsigned char)( IP[1] | MR[1]),(unsigned char)( IP[2] | MR[2]),(unsigned char)( IP[3] | MR[3])+1);
    printf("a %d.%d.%d.%d\n", bro[0],bro[1],bro[2],bro[3]);
    printf("%d\n",255);
    printf("%x\n",255);
    printf("%b\n",255);
    return 0;
}