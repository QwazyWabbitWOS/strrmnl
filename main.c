#include <stdio.h>
#include <string.h>
#include <assert.h>

size_t StrRemoveTrailingNewlines(char* str);

/* Remove all trailing newlines from a C string.
Input: pointer to the string to be altered in place
Return: length of resulting string */
size_t StrRemoveTrailingNewlines(char* str)
{
    char* p = str + strlen(str) - 1;
    while (p >= str && *p == '\n')
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
    char string5[] = "";
    char string6[] = "\n";

    puts("The initial strings when not trimmed:");
    printf("%s\n", string0);
    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s\n", string3);
    printf("%s\n", string4);
    printf("%s\n", string5);
    printf("%s\n", string6);

    len = StrRemoveTrailingNewlines(string0);
    assert(len == strlen(string0));
    len = StrRemoveTrailingNewlines(string1);
    assert(len == strlen(string1));
    len = StrRemoveTrailingNewlines(string2);
    assert(len == strlen(string2));
    len = StrRemoveTrailingNewlines(string3);
    assert(len == strlen(string3));
    len = StrRemoveTrailingNewlines(string4);
    assert(len == strlen(string4));
    len = StrRemoveTrailingNewlines(string5);
    assert(len == strlen(string5));
    len = StrRemoveTrailingNewlines(string6);
    assert(len == strlen(string6));

    puts("The modified strings after trimming:");
    printf("%s\n", string0);
    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s\n", string3);
    printf("%s\n", string4);
    printf("%s\n", string5);
    printf("%s\n", string6);
    puts("Test ends.");
    return 0;
}
