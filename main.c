#include <stdio.h>
#include <string.h>


int done = 0;

const char *MORSE_CODE[] = {
        ".- ",    // A
        "-... ",  // B
        "-.-. ",  // C
        "-.. ",   // D
        ". ",     // E
        "..-. ",  // F
        "--. ",   // G
        ".... ",  // H
        ".. ",    // I
        ".--- ",  // J
        "-.- ",   // K
        ".-.. ",  // L
        "-- ",    // M
        "-. ",    // N
        "--- ",   // O
        ".--. ",  // P
        "--.- ",  // Q
        ".-. ",   // R
        "... ",   // S
        "- ",     // T
        "..- ",   // U
        "...- ",  // V
        ".-- ",   // W
        "-..- ",  // X
        "-.-- ",  // Y
        "--.. "   // Z
};

char toUpper(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return (ch - 'a') + 'A';
    }

    return ch;
}

char* getMorseCode(char ch){
    if(ch >= 'A' && ch <= 'Z') {
        return MORSE_CODE[ch - 'A'];
    } else if(ch == ' '){
        return "/";
    } else{
        return "";
    }
}

int main() {


    while(!done){
        char userInput[255];
        int userOperation;
        printf("Enter operation:\n     1. English --> Morse Code\n     2. Morse Code --> English\n     3. Quit\n");
        scanf("%d", &userOperation);
        getchar();

        switch(userOperation){
            case 1:
                printf("Enter english sentence to translate:\n");
                scanf(" %[^\n]s", userInput);
                getchar();

                for(int i = 0; i < strlen(userInput); i++){
                    char ch = toUpper(userInput[i]);
                    char *morse_code = getMorseCode(ch);

                    printf("%s", morse_code);
                }
                printf("\n");
                break;
            case 2:
                break;
            case 3:
                printf("Exiting, bye bye...");
                done = 1;
                break;
            default:
                printf("Invalid Operation.\n");
        }
    }

    return 0;
}
