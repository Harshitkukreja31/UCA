

// void create() {
	
// 	// Declaring a File Pointer Variable
// 	FILE * fileptr;
	
// 	// User Friendly Prompts 
// 	printf("Enter the Name of File with Extension .txt:- ");
	
// 	char name[10000];

// 	scanf("\n%[^\n]%*c", name);
	
// 	// Creating and Opening the file using file pointer created above
// 	fileptr = fopen(name, "w");
	
// 	// For Some Reason if file creation failed
// 	if ( fileptr == NULL) {
	
// 		printf("Error !\n");
// 		return;
// 	}
	
// 	// User Friendly Prompt to Enter the contents of File
// 	printf("\nEnter the Contents of The file :- \n");
	
// 	char str[100000];
	
// 	scanf("\n%[^\n]%*c", str);
	
// 	// Printing the contents entered by user into the file
// 	fprintf(fileptr, "%s\n", str);
	
// 	// Closing the file pointer to avoid memory leak
// 	fclose(fileptr);
	
// 	// An Acknowledgement of Successfull File Creation
// 	printf("\nFile Creation Successfull\n");	
// 	printf("\nFile Name :- %s\n", name);
// }
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

void create() {

	printf("Enter the Name of File with Extension .txt:- ");
	
	char name[10000];

	scanf("\n%[^\n]%*c", name);
    const char* filename = name;
    int fd;

    // Use creat() system call to create a new file
    fd = creat(filename, 0777);
	//fd = creat(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    printf("File '%s' created successfully.\n", filename);
    printf("File descriptor: %d\n", fd);

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("File closed successfully.\n");

  
}