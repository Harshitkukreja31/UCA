// #include <stdio.h>
// #include <stdlib.h>

// void copyfiles() {
	
// 	// Declaring a File Poweinter Variable
// 	FILE * srcptr, * desptr;
	
// 	// User Friendly Prompts 
// 	printf("Enter the Name of Source File with Extension .txt:- ");
	
// 	char name[10000];

// 	scanf("\n%[^\n]%*c", name);
	
// 	// Finding the file using file pointer
// 	srcptr = fopen(name, "r");
	
// 	// IF File doesn't Exists
// 	if ( srcptr == NULL) {
	
// 		printf("Error File Not Found !! \n");
// 		return;
// 	}

// 	// If file Exits 
// 	printf("\nEnter The Name of Destination File with .txt:- ");
// 	scanf("\n%[^\n]%*c", name);

// 	// Creating a file pointer for Destination File
// 	desptr = fopen(name, "w");
	
// 	// Copying the file
// 	char ch;

// 	while ((ch = fgetc(srcptr)) != EOF) {
// 		fputc(ch, desptr);
// 	}

// 	// Closing Both the file pointers
// 	fclose(srcptr);
// 	fclose(desptr);
	
// 	// An Acknowledgement of Successfull File Copied
// 	printf("\nFile Copying Successfull\n");
	
// 	printf("\nName of the Copied File :- %s\n", name);	
// }
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_FILENAME 256

void copyfiles() {
    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    char source_filename[MAX_FILENAME];
    char dest_filename[MAX_FILENAME];

    // Get source filename from user
    printf("Enter the source filename: ");
    if (scanf("%255s", source_filename) != 1) {
        fprintf(stderr, "Error reading source filename\n");
        exit(EXIT_FAILURE);
    }

    // Get destination filename from user
    printf("Enter the destination filename: ");
    if (scanf("%255s", dest_filename) != 1) {
        fprintf(stderr, "Error reading destination filename\n");
        exit(EXIT_FAILURE);
    }

    // Open source file for reading
    source_fd = open(source_filename, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open destination file for writing (create if it doesn't exist, truncate if it does)
    dest_fd = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        exit(EXIT_FAILURE);
    }

    // Copy data from source to destination
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            close(source_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    // Check if read encountered an error
    if (bytes_read == -1) {
        perror("Read error");
        close(source_fd);
        close(dest_fd);
        exit(EXIT_FAILURE);
    }

    // Close both files
    if (close(source_fd) == -1) {
        perror("Error closing source file");
        exit(EXIT_FAILURE);
    }

    if (close(dest_fd) == -1) {
        perror("Error closing destination file");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");

 
}