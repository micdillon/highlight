#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int 
main
(int argc, char *argv[]) 
{
	/** Regex variables. */
	regex_t preg;
	int reti = 0;
	char msgbuff[100];

	/** Input variables. */
	char *line = NULL;
	size_t linecap = 0;
	ssize_t linelen;

	/** Check args. */
	if (argc < 2) {
		printf("Usage: [regex]\n");
		exit(1);
	}

	/** Compile regex. */
	reti = regcomp(&preg, argv[1], REG_EXTENDED);
	if (reti) {
		fprintf(stderr, "Could not compile regex.\n");
		exit(1);
	}

	/** Loop over stdin until we get a blank line. */
	while ((linelen = getline(&line, &linecap, stdin)) > 0) {
		reti = regexec(&preg, line, 0, NULL, 0);

		/** If regex matched, highlight the line. */
		if (reti == 0) {
			/* remove the newline */
			line[strlen(line)-1] = 0; 
			/* print the highlighted line */
			/* 1m: bold, 0m: normal, 7m: reversed, 31m: red */
			printf("\x1b[1m\x1b[31m%s\x1b[0m\n", line);

		/** Otherwise, just copy it to stdout */
		} else if (reti == REG_NOMATCH ) {
			printf("%s", line);

		/** Handle error. */
		} else {
			regerror(reti, &preg, msgbuff, sizeof(msgbuff));
			fprintf(stderr, "Regex match failed: %s\n", msgbuff);
			exit(1);
		}
	}

	regfree(&preg);
	return 0;
}
