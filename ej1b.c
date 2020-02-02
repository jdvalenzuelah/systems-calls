#include <stdio.h>
#include <unistd.h>

int main() {
	int f = fork();
	if(f == 0) {
		execl("ej1a.o", (char*)NULL);
	} else{
		printf("PID B: %d\n", (int)getpid());
		execl("ej1a.o", (char*)NULL);
	}
}
