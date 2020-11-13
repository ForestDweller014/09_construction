#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

int main() {
	struct session *curr_struct = new_session("ForestDweller");
	print_session(curr_struct);
	free(curr_struct);
	return 0;
}