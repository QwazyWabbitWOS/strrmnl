#include <stdio.h>
#include <string.h>

size_t strrrnl(char* str);

/* Remove all trailing newlines from a C string.
Input: pointer to the string to be altered in place
Return: length of resulting string */
size_t strrrnl(char* str)
{
    char* p = str + strlen(str) - 1;
    while (*p == '\n')
    {
        *p = '\0';
        p--;
    }
    return (p - str + 1);
}

int main(void)
{
    size_t len;
    char string0[] = "This is a string with 0 newlines.";
    char string1[] = "This is a string with 1 newline.\n";
    char string2[] = "This is a string with 2 newlines.\n\n";
    char string3[] = "This is a string with 3 newlines.\n\n\n";
    char string4[] = "This is a string\nwith 1 embedded newline and two trailing.\n\n";

    puts("The initial strings when not trimmed:");
    printf("%s\n", string0);
    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s\n", string3);
    printf("%s\n", string4);

    len = strrrnl(string0);
    len = strrrnl(string1);
    len = strrrnl(string2);
    len = strrrnl(string3);
    len = strrrnl(string4);

    puts("The modified strings after trimming:");
    printf("%s\n", string0);
    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s\n", string3);
    printf("%s\n", string4);
    puts("Test ends.");
    return 0;
}
