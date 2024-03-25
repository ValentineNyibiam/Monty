#include "monty.h"

/**
* tokenize_by_newline - Tokenizes the content
* of the file by a newline character
* @buff: The file content to be tokenized by newline character
*
* Return: Array of tokens which are each a line in the file
*/
void tokenize_by_newline(char *buff)
{
	char *token;
	int token_count = 0;

	strtok(buff, "\n");
	while (token != NULL)
	{
        token_count++;
		token = strtok(NULL, "\n");
	}
	printf("%d\n", token_count);
}
