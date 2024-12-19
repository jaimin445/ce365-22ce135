// this program checks a*b*


#include<stdio.h>
// #include<conio.h>

int main(){
    char str[200];
    int flag=0,flag2=0;
    gets(str);

    for(int i=0;str[i]!=NULL;i++){
        if(str[i]=='a'||str[i]=='b'){
            if(str[i]=='a'){
                if(flag==1){
                    printf("invalid string");
                    flag2=1;
                    break;
                }
            }
            else if(str[i]=='b'){
                flag=1;
            }
        }
        else{
            printf("invalid string");
            flag2=1;
        }
    }

    if(flag2!=1){
        printf("string is valid");
    }
}