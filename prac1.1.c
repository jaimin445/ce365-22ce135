// this program checks a*bb 

#include<stdio.h>

int main() {
    char str[200]; // character array to store the input string
    int flag = 0, flag2 = 0, count = 0; // Initializes flags and counter
    gets(str); // Read input string

    // loop run until its found null 
    for(int i = 0; str[i] != NULL; i++) {
    
        if (str[i] == 'a' || str[i] == 'b') { //only a and b is allow otherwise invalid
            if (str[i] == 'a') { 
            
                if (flag == 1) { // its check a shouldnt encounter after b
                    printf("invalid string"); //invalid string message
                    flag2 = 1; // error flag
                    break; 
                }
            } 
            else if (str[i] == 'b') { 
                count++; 
                flag = 1; //  this  flag indicating 'b' has been encountered
                if (count > 2) {  // more than two 'b's are not allowed otherwise the string is invalid
                    printf("invalid string");
                    flag2 = 1; // Sets the error flag
                    break; 
                }
            }
        } 
        else {
            printf("invalid string"); 
            flag2 = 1; 
            break; 
        }
    }

    if (flag2 != 1) {
        if(flag==0)
        {
            printf("string is invalid");
        }else{
        printf("string is valid"); }
    }
}
