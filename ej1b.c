#include <stdio.h>
#include <unistd.h>

int main() {
	int f = fork();
	if(f == 0) {
		execl("ej1", (char*)NULL);
	} else{
		printf("PID: %d\n", (int)getpid());
	}
}
