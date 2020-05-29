#define _CRT_SECURE_NO_WARNINGS

/*	more-shell-commands collection
	a collection of custom shell commands

  -	pattern <pattern>
	search for all the words that
	matches a speficied pattern

	github.com/mightbesimon
	by simon
*/

#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

// define some contants
#define MAX_WORD_LENGTH	32
#define WORDLIST		"../resources/wordlist.txt"


/*	checks if a word matches the pattern
*/
int is_match(char *word, char *pattern)
{
	int idx = 0;

	while ((word[idx] != '\0')
		&& (pattern[idx] != '\0'))
	{
		
		if ((pattern[idx] != '-')
			&& (word[idx] != pattern[idx]))
			return 0;

		idx++;
	}

	return (word[idx] == pattern[idx]) ? 1 : 0;
}


/*	take args
	load the dictionary words
	check for matches
*/
int main(int argc, char *argv[])
{
	// vreify args
	if (argc != 2) {
		printf("usage:   %s <pattern>\n", argv[0]);
		printf("example: %s -p-tt--n-\n", argv[0]);
		return 1;
	}


	// load wordlist
	FILE *input;
	char word[MAX_WORD_LENGTH];
	int count;

	input = fopen(WORDLIST, "r");
	count = 0;

	if (input == NULL) {
		printf("Could not open file <%s>.\n", WORDLIST);
		return 1;
	}


	// check for matches
	while (fscanf(input, "%s", word) != EOF) {
		if (is_match(word, argv[1])) {
			printf("%s\n", word);
			count++;
		}
	}

	// matches count
	printf("%d matches\n", count);
	return 0;
}

