struct session {char username[20]; char login_token[12];};
struct session *new_session(char *user);
int print_session(struct session *curr_session);