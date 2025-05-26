#include "MY_LIST.h"

int main()
{
	node* head = NULL;
	group buffer_group;

	node* tmp = NULL;

	printf("\t\t\tList with ""Start"" features\n");
	head = InsertToStart(head, initGroup(&buffer_group, "AVT-412", "Faculty of automation and computer engeneereng", 2023, 0));
	head = InsertToStart(head, initGroup(&buffer_group, "SVT-412", "faculty of automation and computer engeneereng", 2020, 0));
	head = InsertToStart(head, initGroup(&buffer_group, "AVT-412", "Aaculty of automation and computer engeneereng", 2020, 1));

	printf("List with 3 elements:\n\n");
	PrintList(head);

	head = DeleteFromStart(head);

	printf("\tlist without 1-st element\n\n");
	PrintList(head);
	
	for (node* tmp = head; head != NULL; tmp = head)
	{
		head = head->next;
		free(tmp);
	}

	printf("\t\t\tList with ""Sort"" features\n\n");
	head = InsertInSortList(head, initGroup(&buffer_group, "AVT-412", "Aaculty of automation and computer engeneereng", 2023, 1));
	head = InsertInSortList(head, initGroup(&buffer_group, "SVT-312", "Faculty of automation and computer engeneereng", 2021, 0));
	head = InsertInSortList(head, initGroup(&buffer_group, "AVT-412", "Aaculty of automation and computer engeneereng", 2023, 1));
	head = InsertInSortList(head, initGroup(&buffer_group, "AVT-112", "Faculty of automation and Computer engeneereng", 2019, 1));

	printf("Entered sorted List:\n\n");
	PrintList(head);

	head = DeleteSameNodes(head);
	
	printf("\tSorted List (with only unique elements):\n\n");
	PrintList(head);

	for (node* tmp = head; head != NULL; tmp = head)
	{
		head = head->next;
		free(tmp);
	}

	return 0;
}
