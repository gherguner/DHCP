#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogr{
       
       char * Mac;
       int  IP;
};

int main(){
    struct ogr filtering;
    while(1){
        printf("1. yeni kayit ekle\n");
        printf("2. kayit ara\n");
        printf("3. cikis\n");
        printf("bir secim yapiniz\n");
        int secim;
        scanf("%d",&secim);
        if(secim == 1){
                 FILE *fp = fopen("kayit.txt","a");
                  //filtering a;
                 filtering.Mac = (char*)malloc(sizeof(char)*20);
                 
                 printf("MAC giriniz:");
                 scanf("%s",filtering.Mac);
         
                 printf("IP giriniz");
                 scanf("%d",&filtering.IP);
                 fprintf(fp,"%s %d\n",filtering.Mac,filtering.IP);
                 fclose(fp);
        }
        if(secim == 2){
		
                 FILE *fp=fopen("kayit.txt","r");
                 char arananMAC[100];
                 printf("arananMAC giriniz");
                 scanf("%s",arananMAC);
                 while(!feof(fp)){
                   
                   fscanf(fp,"%s %d",filtering.Mac,&filtering.IP);
                   if(strcmp(filtering.Mac,arananMAC)==0)
                   {
                       printf("%s  %d\n",filtering.Mac,filtering.IP);
                   }  
                   
                                          
                 }
                 if(strcmp(filtering.Mac,arananMAC)!=0)
                   {
                       printf("aranan mac bulunamadı\n");
                   }  
                     
                 fclose(fp);    
        }
        if(secim == 3){
                 break;
        }
    }
}
             
