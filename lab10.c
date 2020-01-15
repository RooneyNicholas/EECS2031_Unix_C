#include <stdio.h>
#include <string.h>

int main() {
	int itr;
	for(itr = 0; itr < 5; itr++) {
		printf("Grock- ");
		char input[128] = {};
		fgets(input, 128, stdin);
		char command[128] = {};
		sscanf(input, "%s", command);
		int itr = 0;
		printf("Command entered: %s\n", command);
		while(input[itr] != ' ' && input[itr]) {
			itr++;
		}
		itr++;
		if(input[itr]) { //This will pass the newline char, no need to add it to print statement.
			printf("Arguments entered: ");
			while(input[itr]) {
				printf("%c", input[itr]);
				itr++;
			}
		} else {
			printf("Arguments entered: \n");
		}
	}
	return 0;
}
