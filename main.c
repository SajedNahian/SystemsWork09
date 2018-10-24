#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fileDescription;
	char buffer [17];
	char * fileName = "coolfile.txt";
	printf("Opening file '%s' with write access...\n", fileName);
	fileDescription = open(fileName, O_CREAT | O_WRONLY, 0700);

	if (fileDescription == -1) {
		printf("File creation / opening failed!\n");
		return 1;
	}

	char * myMessage = "This is so cool!\n";
	printf("Writing to file '%s'...\n", fileName);
	write(fileDescription, myMessage, 17);
	printf("Closing file '%s'...\n", fileName);
	close(fileDescription);
	printf("Opening file '%s' with read access...\n", fileName);
	fileDescription = open(fileName, O_RDONLY);

	if (fileDescription == -1) {
		printf("Failed to open file\n");
		return 1;
	}
	
	printf("Reading file '%s':\n", fileName);
	read(fileDescription, buffer, 17);
	buffer[17] = '\0';
	printf("%s", buffer);
	return 0;
}