#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC_ERR 1

char* readLine(FILE * source) {
	char buffer[20];
	char* line;
	int multiplier = 1;
	if (fgets(buffer, sizeof buffer, source) == NULL) return NULL;
	line = malloc(sizeof buffer);
	strncpy(line, buffer, strlen(buffer) + 1);
	while (line[strlen(line) - 1] != '\n')
	{
		char* tmp;
		multiplier++;
		fgets(buffer, sizeof buffer, source);
		if ((tmp = realloc(line, sizeof buffer * multiplier)) == NULL)
		{
			fprintf(stderr, "ERROR: realloc failed");
			exit(1);
		}
		line = tmp;
		strncat(line, buffer, strlen(buffer));
	}

	return line;
}

int main() {

	char* commandString;
	char* command;
	char* arg;
	char* extra;
	char** fieldOne = NULL;
	char** fieldTwo = NULL;
	char** fieldThree = NULL;
	FILE* file;
	int done = 0;
	int returnedStrings;
	int correctLines = 0;
	int badLines = 0;

	while (!done) {
		printf("Grock- ");

		commandString = readLine(stdin);
		command = malloc(strlen(commandString) * sizeof(char));
		arg = malloc(strlen(commandString) * sizeof(char));
		extra = malloc(strlen(commandString) * sizeof(char));
		returnedStrings = sscanf(commandString, "%s %s %s", command, arg, extra);

		if (strcmp(command, "setdb") == 0) {
			if (returnedStrings >= 2) {
				file = fopen(arg, "r");
				if (file) {
					char* line;
					char* rel;
					char* ent1;
					char* ent2;
					char* tooManyEnts;
					int lineNumber = 0;
					int fileReturnedStrings;
					correctLines = 0;
					badLines = 0;
					fieldOne = malloc(sizeof(char*));
					fieldTwo = malloc(sizeof(char*));
					fieldThree = malloc(sizeof(char*));
					while (line = readLine(file)) {
						rel = malloc(strlen(line) * sizeof(char));
						ent1 = malloc(strlen(line) * sizeof(char));
						ent2 = malloc(strlen(line) * sizeof(char));
						tooManyEnts = malloc(strlen(line) * sizeof(char));
						fileReturnedStrings = sscanf(line, "%s %s %s %[^\n]s", rel, ent1, ent2, tooManyEnts);
						if (fileReturnedStrings == 3) {
							fieldOne = realloc(fieldOne, (lineNumber + 1) * sizeof (char*));
							fieldOne[lineNumber] = malloc( (strlen(rel) + 1) * sizeof(char));
							fieldTwo = realloc(fieldTwo, (lineNumber + 1) * sizeof(char*));
							fieldTwo[lineNumber] = malloc((strlen(ent1) + 1) * sizeof(char));
							fieldThree = realloc(fieldThree, (lineNumber + 1) * sizeof(char*));
							fieldThree[lineNumber] = malloc((strlen(ent2) + 1) * sizeof(char));
							strcpy(fieldOne[lineNumber], rel);
							strcpy(fieldTwo[lineNumber], ent1);
							strcpy(fieldThree[lineNumber], ent2);
							correctLines++;
							lineNumber++;
						}
						else {
							badLines++;
						}
						
						free(rel);
						free(ent1);
						free(ent2);
						free(tooManyEnts);
					}
					printf("Read %d facts from %s\n", correctLines, arg);
					int databaseLineItr = 0;
					while (databaseLineItr < correctLines) {
						printf("%s %s %s\n", fieldOne[databaseLineItr], fieldTwo[databaseLineItr], fieldThree[databaseLineItr]);
						databaseLineItr++;
					}
					if (badLines) {
						printf("%d malformed lines were ignored.\n", badLines);
					}
					fclose(file);
				}
				else {
					printf("Unable to read from %s\n", arg);
				}
			}
			else {
				printf("Missing Argument.\n");
			}
			if (returnedStrings >= 3) {
				printf("Extra arguments ignored.\n");
			}
		}
		else if (strcmp(command, "printdb") == 0) {
			int itr = 0;
			while (itr < correctLines) {
				printf("%s %s %s\n", fieldOne[itr], fieldTwo[itr], fieldThree[itr]);
				itr++;
			}
		}
		else if (strcmp(command, "quit") == 0) {
			done = 1;
		}
		else {
			printf("Unrecognized command.\n");
		}
		free(command);
		free(arg);
		free(extra);
	}

	int itr = 0;
	for (itr; itr < correctLines; itr++) {
		free(fieldOne[itr]);
		free(fieldTwo[itr]);
		free(fieldThree[itr]);
	}
	if (fieldOne && fieldTwo && fieldThree) {
		free(fieldOne);
		free(fieldTwo);
		free(fieldThree);
	}
}