#include <stdio.h>
#include <string.h>

void reverse_string(char *s, int start, int end) {
    if (start >= end)
        return;
 
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    reverse_string(s, start + 1, end - 1);
}

int main() {
    char input_string[] = "Hello, World!";
    int length = strlen(input_string);
    printf("Original string: %s\n", input_string);
    reverse_string(input_string, 0, length - 1);
    printf("Reversed string: %s\n", input_string);
    return 0;
}
