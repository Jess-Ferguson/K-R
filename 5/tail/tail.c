#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dqueue.h>

#define MAX_LEN 256
#define MAX_LINES 32
#define DEFAULT_TAIL 10

int getlinep(char *s, int lim);

int main(int argc, char *argv[])
{
	char *line;
	char *temp;
	int tail_len = DEFAULT_TAIL;
	queue_t * queue = NULL;
	int elements;
	int len;

	if(!(queue = queue_init(sizeof(char *)))) {
		fprintf(stderr, "Error %d: Could not initialise queue!\n", MEM_ERROR);
		return MEM_ERROR;
	}

	if(argc >= 2) {
		if(atoi(*(++argv))) {
			tail_len = -atoi(*argv);
			if(tail_len <= 0 || tail_len > MAX_LEN)
				tail_len = DEFAULT_TAIL;
		}
	}

	for(elements = 0; elements < tail_len; elements++) {
		if(!(line = malloc(MAX_LEN))) {
			fprintf(stderr, "Error: Memory allocation failure!\n");
			return MEM_ERROR;
		}

		if(!getlinep(line, MAX_LEN)) {
			free(line);

			if(elements == 0) {
				queue_destroy(&queue);
				return EXIT_SUCCESS;
			}

			break;
		}

		queue_push(&line, queue);
	}

	if(elements == tail_len) {
		if(!(temp = malloc(MAX_LEN))) {
			fprintf(stderr, "Error: Memory allocation failure!\n");
			return MEM_ERROR;
		}
		for(;;) {
			if(!(len = getlinep(temp, MAX_LEN))) {
				free(temp);
				break;
			}

			queue_pop(&line, queue);
			memcpy(line, temp, len + 1);
			queue_push(&line, queue);
		}
	}

	while(elements-- > 0) {
		queue_pop(&line, queue);
		printf("%s", line);
		free(line);
	}

	queue_destroy(&queue);

	return EXIT_SUCCESS;
}

int getlinep(char *s, int lim)
{
	int i;
	
	for(i = 0; i < lim - 1 && (*s = getchar()) != EOF && *s != '\n'; i++, s++)
		;

	if(*s == '\n') {
		s++;
		i++;
	}
	
	*s = '\0';
	
	return i;
}