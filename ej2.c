#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 8192

// Use code from https://stackoverflow.com/questions/26723437/using-read-system-call as reference

/*
* Copy content on fdi to fdo
* Return the number of bytes read, or an error code on failure.
*/
int copy_file(int fdi, int fdo){
	char buff[BUFF_SIZE];
	int n_read, n_write, total = 0;
	while( (n_read = read(fdi, &buff, sizeof(buff))) > 0) {
		total += n_read;
		if ( (n_write = write(fdo, &buff, n_read)) < 0) { return n_write; }
	}
	return n_read < 0 ? n_read : total;
}

int main(int argc, char *argv[]){

	if(argc < 2) {
		printf("Source file missing!");
		return 1;
	} else if(argc < 3) {
		printf("Destination file missing!");
		return 1;
	}

	int input, output, result;
	if( (input = open(argv[1], O_RDONLY) ) < 0) {
		perror("Error opening source file");
		return 1;
	}
	if( (output = open(argv[2], O_WRONLY | O_CREAT, 0666)) < 0) {
		close(input);
		perror("Error opening destination file");
		return 1;
	}
	
	if( (result = copy_file(input, output)) < 0) {
		close(input); close(output);
		perror("Unexpected error");
		return 1;
	}

	close(input);
	close(output);
	return 0;
}

