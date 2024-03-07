#include <stdio.h>

void stringCopy(char source[], char destination[], int index) {
    if (source[index] == '\0') {
        destination[index] = '\0'; 
        return; 
    }
    destination[index] = source[index]; 
    stringCopy(source, destination, index + 1); 
}

int main() {
    char source[100], destination[100];
    printf("Enter a string: ");
    scanf("%s", source);

    stringCopy(source, destination, 0); 

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}
