// #include <stdio.h>

// void appendfile() {
	
// 	// Declaring a File Pointer Variable
// 	FILE * fileptr;
	
// 	// User Friendly Prompts 
// 	printf("Enter the Name of File with Extension .txt:- ");
	
// 	char name[10000];

// 	scanf("\n%[^\n]%*c", name);
	
// 	// Finding the file using file pointer
// 	fileptr = fopen(name, "r");
	
// 	// IF File doesn't Exists
// 	if ( fileptr == NULL) {
	
// 		printf("Error File Not Found !! \n");
// 		return;
// 	}

// 	// If File Exists Opening the file in Append mode
// 	fileptr = fopen(name, "a");
	
// 	// User Friendly Prompt to Enter the contents of File
// 	printf("\nEnter the Contents to Add in the file :- \n");
	
// 	char str[100000];
	
// 	scanf("\n%[^\n]%*c", str);
	
// 	// Printing the contents entered by user into the file
// 	fprintf(fileptr, "%s\n", str);
	
// 	// Closing the file pointer to avoid memory leak
// 	fclose(fileptr);
	
// 	// An Acknowledgement of Successfull File Creation
// 	printf("\nFile Updation Successfull\n");	
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_FILENAME 256
#define MAX_CONTENT 1024

void appendfile() {
    int fd;
    ssize_t bytes_written;
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];

    // Get filename from user
    printf("Enter the filename to append to: ");
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Error reading filename\n");
        exit(EXIT_FAILURE);
    }

    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Get content from user
    printf("Enter the content to append (max 1023 characters):\n");
    if (fgets(content, MAX_CONTENT, stdin) == NULL) {
        fprintf(stderr, "Error reading content\n");
        exit(EXIT_FAILURE);
    }

    // Open file for appending (create if it doesn't exist)
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Append content to file
    bytes_written = write(fd, content, strlen(content));
    if (bytes_written == -1) {
        perror("Write error");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("Content appended successfully.\n");

    return 0;
}