#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo-wm.h"
#include "commands.h"
#include "tree.h"

void handleCommand(char* request) {
	fprintf(stderr, "Recv from FIFO: %s", request);

	//Array to contain pointers to tokens, max of 5 tokens
	char *tokens[5];

	int counter = 0;
	char *lastToken, *token;
	for ( token = strtok_r(request, " ", &lastToken); token; token = strtok_r(NULL, " ", &lastToken)) {
		tokens[counter++] = token;
		fprintf(stderr, "Adding Token %s\n", token);
	}


	if (!strcmp(tokens[0], "kill")) {
		fprintf(stderr, "Killing Client");
	} else if (!strcmp(tokens[0], "dump")) {
		dumpTree();
	} else if (!strcmp(tokens[0], "layout")) {
		fprintf(stderr, "Setting layout to: %s", tokens[1]);
		if (!strcmp(tokens[1], "vertical")) {	
			currentContainer -> layout = 0;

		} else if (!strcmp(tokens[1], "horizontal")) {
			currentContainer -> layout = 1;
		}
		placeContainer(currentContainer, 
				currentContainer -> x, currentContainer -> y, 
				currentContainer -> width, currentContainer -> height);

	} else if (!strcmp(tokens[0], "containerize")) {
		if (currentClient -> previous != NULL) {
			fprintf(stderr, "Containerizing!");
			Container * newContainer = malloc(sizeof(Container));
			parentClient(currentClient, newContainer);
			parentContainer(newContainer, currentContainer);
			currentContainer = newContainer;
		} else {
			fprintf(stderr, "Containerize called but already alone in a container...");
		}
	}
}
