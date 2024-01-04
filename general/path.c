#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * addNode - Add a newnode at the beginning
 * @head: the current struct
 * @directory: the directory to add
 * Return: newnode on Success
*/

struct Node *addNode(struct Node *head, char *directory)
{
	struct Node *newnode;

	newnode = (struct Node *)malloc(sizeof(struct Node));

	if (newnode == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}

	newnode->directory = strdup(directory);
	if (newnode->directory == NULL)
	{
		perror("Directory is empty");
		free(directory);
		exit(EXIT_FAILURE);
	}

	newnode->next = head;

	return (newnode);
}


/**
 * printList - print the content in a struct
 * @head: the current struct
*/

void printList(struct Node *head)
{
	while (head != NULL)
	{
		printf("%s\n", head->directory);
		head = head->next;
	}
}


/**
 * freeList - free memory form the struct
 * @head: the current struct
*/

void freeList(struct Node *head)
{
	struct Node *temp;

	if (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->directory);
		free(temp);
	}
}




/**
 * main - Entry point
 * Return: 0 on Success
*/

int main(void)
{
	char *path;
	char *token;

	path = getenv("PATH");

	if (path == NULL)
	{
		printf("Path envirinent variable not found\n");
		return (1);
	}

	struct Node *head = NULL;

	token = strtok(path, ":");

	while (token != NULL)
	{
		head = addNode(head, token);
		token = strtok(NULL, ":");
	}

	printf("The directory in the PATH env variable\n");
	printList(head);

	freeList(head);

	return (0);
}
