#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int WriteDB(FILE * file, char facts[128][128], char fileName[]) {
	int lineNumber = 0;
	int incorrectLines = 0;
	int correctLines = 0;
	char line[128];
	char fact1[128];
	char fact2[128];
	char fact3[128];
	char extras[128];
	while (fgets(line, 128, file)) {
		if (sscanf(line, "%s %s %s %s", &fact1, &fact2, &fact3, &extras) == 3) {
			sprintf(facts[lineNumber], "%s %s %s", fact1, fact2, fact3);
			correctLines++;
			lineNumber++;
		}
		else {
			incorrectLines++;
		}
	}
	printf("Read %d facts from %s\n", correctLines, fileName);
	if (incorrectLines) {
		printf("%d malformed lines were ignored\n", incorrectLines);
	}
	return correctLines;
}

int ReadFile(FILE* file, char arguments[128], char facts[128][128]) {
	int writtenLines = 0;
	char extraArguments[128];
	int returnedStrings = sscanf(arguments, "%s %s", arguments, &extraArguments);
	if (returnedStrings > 0) {
		file = fopen(arguments, "r");
		if (file) {
			writtenLines = WriteDB(file, facts, arguments);
			fclose(file);
		}
		else {
			printf("Unable to read from %s\n", arguments);
		}
	}
	else {
		printf("Missing Argument.\n");
	}
	if (returnedStrings == 2) {
		printf("Extra arguments ignored\n");
	}
	return writtenLines;
}


int main() {

	bool done = false;
	char commandFullString[128];
	char command[128];
	char arguments[128];
	char facts[128][128];
	int writtenLines = 0;
	FILE* file;

	while (!done) {
		printf("Grock- ");
		fgets(commandFullString, sizeof(commandFullString), stdin);
		commandFullString[strlen(commandFullString) - 1] = '\0';
		sscanf(commandFullString, "%s %[^\n]s", &command, &arguments);
		command[strlen(command)] = '\0';
		arguments[strlen(arguments)] = '\0';
		if (strcmp(command, "setdb") == 0) {
			writtenLines = ReadFile(&file, arguments, facts);
		}
		else if (strcmp(command, "printdb") == 0) {
			if (writtenLines) {
				int itr;
				for (itr = 0; itr < writtenLines; itr++) {
					printf("%s\n", facts[itr]);
				}
			}
			else {
				printf("Database is empty.\n");
			}
		}
		else if (strcmp(command, "quit") == 0) {
			done = true;
		}
		else {
			printf("Unrecognized command.\n");
		}
	}

	return 0;
}