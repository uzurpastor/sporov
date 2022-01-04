#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	size_t buf;
	char *line;
	printf("buf:");
	scanf("%zu", &buf);

	line = (char*)malloc(buf*sizeof(char));
	getline(&line, &buf, stdin);

	getline(&line, &buf, stdin);

	printf("%s", line);
	return 0;
}