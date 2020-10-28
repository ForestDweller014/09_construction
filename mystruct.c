#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mystruct.h"

struct session *new_session(char *user) {
	struct session *ns;
	ns = malloc(sizeof(struct session));

	strncpy(ns->username, user, sizeof(ns->username));

	srand(time(NULL));
	int i;
	char *nt = ns->login_token;
	for (i = 0; i < 256; i++) {
		*(nt + i) = (rand() % (62));
		if (*(nt + i) < 10) {
			*(nt + i) += 48;
		} else if (*(nt + i) < 36) {
			*(nt + i) += 65 - 10;
		} else {
			*(nt + i) += 97 - 36;
		}
	}

	return ns;
}

int print_session(struct session *curr_session) {
	printf("Username: %s\nLogin token: %s\n", curr_session->username, curr_session->login_token);
	return 0;
}