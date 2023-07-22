#include <stdio.h>
#include <string.h>

size_t StrRemoveTrailingNewlines(char* str);

/* Remove all trailing newlines from a C string.
Input: pointer to the string to be altered in place
Return: length of resulting string */
size_t StrRemoveTrailingNewlines(char* str)
{
    char* p = str + strlen(str) - 1;  // grab the tail
    while (*p == '\n')
    {
        *p = '\0';
        p--;
    }
    return strlen(str);
}

int main(void)
{
    char string0[] = "This is a string with 0 newlines.";
    char string1[] = "This is a string with 1 newline.\n";
    char string2[] = "This is a string with 2 newlines.\n\n";
    char string3[] = "This is a string with 3 newlines.\n\n\n";
    char string4[] = "This is a string\nwith 1 embedded newline.\n\n";

    puts("The initial strings when not trimmed:");
    printf("%s\n", string0);
    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s\n", string3);
    printf("%s\n", string4);
 
    StrRemoveTrailingNewlines(string0);
    StrRemoveTrailingNewlines(string1);
    StrRemoveTrailingNewlines(string2);
    StrRemoveTrailingNewlines(string3);
    StrRemoveTrailingNewlines(string4);

    puts("The following should have no extra linefeeds:");
    printf("%s\n", string0);
    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s\n", string3);
    printf("%s\n", string4);
    puts("Test ends.");
}
