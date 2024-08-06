// #include <stdio.h>

// void writefile() {
	
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

// 	// If File Exists Opening the file in Write mode
// 	fileptr = fopen(name, "w");
	
// 	// User Friendly Prompt to Enter the contents of File
// 	printf("\nEnter the New Contents of The file :- \n");
	
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

void writefile() {
	printf("Enter the Name of File with Extension .txt:- ");
	
	char name[10000];

	scanf("\n%[^\n]%*c", name);
    const char *filename = name;
	printf("\nEnter the New Contents of The file :- \n");
	
	char str[100000];
	
	scanf("\n%[^\n]%*c", str);
    const char *data = str;
    int fd;
    ssize_t bytes_written;

    // Open the file for writing. If it doesn't exist, create it.
    // If it exists, truncate it.
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write data to the file
    bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Successfully wrote %zd bytes to file '%s'.\n", bytes_written, filename);

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("File closed successfully.\n");

  
}