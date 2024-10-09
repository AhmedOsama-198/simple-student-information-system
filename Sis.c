#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student{
	int id;
	char name[50];
	int age;
	float gpa;
};

struct node{
	struct student data;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void enterNewStudent();

void addStudent(const struct student *const ptr);

void displayStudents(void);

void searchStudentByID(int id);

void updateStudent(int id);

float calculateAverageGPA(void);

void searchHighestGPA(void);

void deleteStudent(int id);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);

	short input = 0;
	int id;

	puts("Welcome");

	while(input != 8){
		printf("\n\n");
		puts("***********Main Menu***********\n");
		puts("1. Add a student");
		puts("2. Display all students");
		puts("3. Search for a student by id");
		puts("4. Update student information");
		puts("5. Delete a student");
		puts("6. Calculate average Gpa");
		puts("7. Find student with highest Gpa");
		puts("8. Exit");
		puts("\n*******************************\n");

		printf("Enter choice: ");

		scanf("%hd",&input);

		switch(input){

		case 1:
			puts("\n*******************************\n");
			enterNewStudent();
			break;
		case 2:
			puts("\n*******************************\n");
			displayStudents();
			break;
		case 3:
			puts("\n*******************************\n");
			printf("Enter student id: ");
			scanf("%d",&id);
			puts("");
			searchStudentByID(id);
			break;
		case 4:
			puts("\n*******************************\n");
			printf("Enter student id: ");
			scanf("%d",&id);
			puts("");

			updateStudent(id);
			break;
		case 5:
			puts("\n*******************************\n");
			printf("Enter student id: ");
			scanf("%d",&id);
			puts("");
			deleteStudent(id);
			break;
		case 6:
			puts("\n*******************************\n");

			printf("Average Gpa is: %.2f\n",calculateAverageGPA());
			break;
		case 7:
			puts("\n*******************************\n");
			printf("Student with highest Gpa:\n");
			searchHighestGPA();
			break;
		case 8:
			puts("Good bye");
			break;

		default:
			puts("\nUnrecognized choice, please try again");
		}
	}

}

void enterNewStudent(){
	struct student new;
	struct node *ptr = head;
	char flag = 1;

	printf("enter name: ");
	getchar();
	gets(new.name);

	printf("enter id: ");

	while(flag == 1){
		flag = 0;
		ptr = head;
		scanf("%d",&new.id);
		while(ptr != NULL){
			if(ptr -> data.id == new.id){
				flag = 1;
				printf("id already taken, please choose another id: ");
				break;
			}
			ptr = ptr -> next;
		}
	}


	printf("enter age: ");
	scanf("%d",&(new.age));

	printf("enter gpa: ");
	scanf("%f",&(new.gpa));

	addStudent(&new);

}
void addStudent(const struct student *const ptr)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));

	link -> data.id = ptr -> id;
	strcpy(link -> data.name, ptr -> name);
	link -> data.age = ptr -> age;
	link -> data.gpa = ptr -> gpa;

	link -> next = NULL;

	if(head == NULL){
		head = link;
		return;
	}

	current = head;

	// loop until reach the last node in the old list
	while(current->next != NULL)
	{
		current = current->next;
	}

	// Make the last node in the old list point to new node
	current->next = link;

}

void displayStudents(void)
{
	if(head == NULL){
		puts("No student are present on the system");
		return;
	}

	struct node *ptr = head;

	while(ptr != NULL){
		printf("student name: %s\n",ptr -> data.name);
		printf("id: %d\n",ptr -> data.id);
		printf("Age: %d\n",ptr -> data.age);
		printf("Gpa: %.2f\n",ptr -> data.gpa);

		ptr = ptr -> next;

		printf("\n");
	}

}

void searchStudentByID(int id)
{

	if(head == NULL){
		puts("No student are present on the system");
		return;
	}

	struct node *ptr = head;

	while(ptr != NULL)
	{
		if(ptr -> data.id == id){
			printf("student name: %s\n",ptr -> data.name);
			printf("id: %d\n",ptr -> data.id);
			printf("Age: %d\n",ptr -> data.age);
			printf("Gpa: %.2f\n",ptr -> data.gpa);

			return;
		}

		ptr = ptr -> next;
	}

	printf("Student not found in system\n");
}

void updateStudent(int id)
{

	if(head == NULL){
		puts("No student are present on the system");
		return;
	}

	short choice = 0;

	struct node *ptr = head;

	while(ptr != NULL)
	{
		if(ptr -> data.id == id){
			printf("student name: %s\n",ptr -> data.name);
			printf("id: %d\n",ptr -> data.id);
			printf("Age: %d\n",ptr -> data.age);
			printf("Gpa: %.2f\n",ptr -> data.gpa);

			while(choice != 4){

				puts("\nwhat would you like to change?");
				puts("1. Name");
				puts("2. Age");
				puts("3. Gpa");
				puts("4. exit");

				scanf("%hd",&choice);

				switch(choice){
				case 1:
					memset(ptr->data.name, '\0', sizeof(ptr->data.name));
					printf("enter new name: ");
					getchar();
					gets(ptr -> data.name);
					break;
				case 2:
					printf("enter new age: ");
					scanf("%d",&(ptr -> data.age));
					break;
				case 3:
					printf("enter new gpa: ");
					scanf("%f",&(ptr -> data.gpa));
					break;
				case 4:
					break;
				default:
					puts("\nUnrecognized choice, please try again");
				}

			}
			puts("\nUpdated information\n");

			printf("student name: %s\n",ptr -> data.name);
			printf("id: %d\n",ptr -> data.id);
			printf("Age: %d\n",ptr -> data.age);
			printf("Gpa: %.2f\n",ptr -> data.gpa);

			return;
		}

		ptr = ptr -> next;

	}

	printf("Student not found in system\n");
}

float calculateAverageGPA(void)
{

	if(head == NULL){
		puts("No student are present on the system");
		return 0;
	}
	float sum = 0;
	int count = 0;

	struct node *ptr = head;

	while(ptr != NULL){
		sum += ptr -> data.gpa;
		count++;
		ptr = ptr -> next;
	}

	return sum/count;

}

void searchHighestGPA(void)
{
	if(head == NULL){
		puts("No student are present on the system");
		return;
	}

	struct node *ptr = head;
	struct node *maxStudent = ptr;

	float max = ptr -> data.gpa;

	ptr = ptr -> next;

	while(ptr != NULL){
		if(max < ptr -> data.gpa){
			max = ptr -> data.gpa;
			maxStudent = ptr;
		}
		ptr = ptr -> next;
	}

	printf("student name: %s\n",maxStudent -> data.name);
	printf("id: %d\n",maxStudent -> data.id);
	printf("Age: %d\n",maxStudent -> data.age);
	printf("Gpa: %.2f\n",maxStudent -> data.gpa);

}

void deleteStudent(int id)
{

	if(head == NULL){
		puts("No student are present in the system");
		return;
	}



	struct node *ptr = head;
	struct node *delete = NULL;

	if(ptr ->data.id == id){
		delete = head;
		head = head->next;
		free(delete);
		printf("Successfully deleted student with id no. %d\n", id);
		return;
	}

	while(ptr -> next != NULL)
	{
		if(ptr -> next -> data.id == id){
			delete = ptr -> next;
			ptr -> next = ptr -> next -> next;
			free(delete);

			printf("Successfully deleted student with id no. %d\n",id);

			return;
		}

		ptr = ptr -> next;
	}

	printf("Student not found in system\n");
}
