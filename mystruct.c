#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mystruct.h"

struct session *new_session(char *user) {
	srand(time(NULL));
	char token[12];
	int i;
	for (i = 0; i < 12; i++) {
		token[i] = (rand() % (62));
		if (token[i] < 10) {
			token[i] += 48;
		} else if (token[i] < 36) {
			token[i] += 65 - 10;
		} else {
			token[i] += 97 - 36;
		}
	}

	struct session *ns;
	ns = malloc(sizeof(struct session));

	strncpy(ns->username, user, sizeof(ns->username) - 1);
	strncpy(ns->login_token, token, sizeof(ns->login_token) - 1);

	return ns;
}

int print_session(struct session *curr_session) {
	printf("Username: %s\nLogin token: %s\n", curr_session->username, curr_session->login_token);
	return 0;
}