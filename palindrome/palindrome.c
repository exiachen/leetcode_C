#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
	int length = 0;
	char *start = NULL;
	char *end = NULL;

    if (!s)
    	return false;

    length = strlen(s);
    if (0 == length)
    	return true;

    start = s;
    end = s + (length - 1);

    while (start < end)
    {
    	if (!isalnum(*start))
    	{
    		start++;
    		continue;
    	}

    	if (!isalnum(*end))
    	{
    		end--;
    		continue;
    	}

    	if (tolower(*start) == tolower(*end))
    	{
    		start++;
    		end--;
    	}
    	else
    	{
    		return false;
    	}
    }

    return true;
}

int main(int argc, char *argv[])
{
	char test[] = "1a2";
	printf("isPalindrome: %d\n", isPalindrome(test));

	return 0;
}


