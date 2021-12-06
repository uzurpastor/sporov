#include "../libpr1.h"

int main(){

	int step;
	struct ArrayList * root;
	{
		int n;
		printf("Input first value: ");
		scanf("%d", &n);
		root = init(n);
	}
	while(step != 0){
		int input;
		printf(
			"\t1. Add\n"
			"\t2. Insert\n"
			"\t3. Size\n"
			"\t4. Remove\n"
			"\t5. Set\n"
			"\t6. Get\n"
			"Command: ");
		scanf("%d", &step);
		printf("_________________\n");
		switch(step){
			case 1:
				printf("Input value: ");
				scanf("%d", &input);
				add(root, input);

		}
		printf("Arr:\n\t");
		display_list(root);
		printf("\n-----------------\n");

	}

}