// this programs checks a*b*
#include<stdio.h>

int main() {
    char str[200]; //  the input string
    int flag = 0, flag2 = 0; 
    gets(str); // Reads the input string 

    // Loop runs until the NULL character is encountered
    for (int i = 0; str[i] != NULL; i++) {
        // only 'a' or 'b' are allowed
        if (str[i] == 'a' || str[i] == 'b') {
            if (str[i] == 'a') { 
                // If 'a' is encountered after 'b', it is invalid
                if (flag == 1) { 
                    printf("invalid string"); 
                    flag2 = 1; // Sets the error flag
                    break;
                }
            } 
            else if (str[i] == 'b') {
                flag = 1; // Sets the flag indicating 'b' has been encountered
            }
        } 
        else {
            printf("invalid string");
            flag2 = 1; // Sets the error flag
            break; 
        }
    }

    
    if (flag2 != 1) {
        printf("string is valid"); 
    }
}
