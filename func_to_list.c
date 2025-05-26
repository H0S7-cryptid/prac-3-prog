#include "STRUCT.h"
#include "MY_LIST.h"

void PrintList(node* head)
{
	if (head == NULL) return;

	for (node* tmp = head; tmp != NULL; tmp = head)
	{
		printGroup(tmp->data);
		head = head->next;
	}
}

node* CreateNode(node* insert_node, group* g)
{
	insert_node = (node*)malloc(sizeof(node));
	if (!insert_node)  return NULL;
	insert_node->data = (group*)malloc(sizeof(group));
	if (!insert_node->data) return NULL;

	*(insert_node->data) = *(g);
	insert_node->next = NULL;

	return insert_node;
}

node* InsertToStart(node* head, group* grp)
{
	node* node_to_ins = NULL;

	node_to_ins = CreateNode(node_to_ins, grp);

	node_to_ins->next = head;
	head = node_to_ins;

	return head;
}

node* DeleteFromStart(node* head)
{
	node* item = head;
	head = head->next;
	free(item);
	return head;
}

node* InsertInSortList(node* head, group* g)
{
	if (head == NULL || (WhichGroupIsSmaller(g, head->data) == GROUP1_IS_SMALLER)) return InsertToStart(head, g);

	node* tmp = head;
	node* prev = NULL;
	node* node_to_ins = NULL;

	while (tmp != NULL && WhichGroupIsSmaller(g, tmp->data) != GROUP1_IS_SMALLER)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	node_to_ins = CreateNode(node_to_ins, g);

	if (prev != NULL) prev->next = node_to_ins;
	node_to_ins->next = tmp;

	return head;
}

node* DeleteSameNodes(node* head)
{
	group* exploring_element;
	node* total_search_ptr = head;
	node* cycle_search_ptr = NULL;
	node* prev = NULL;

	int is_deleted = 0;

	exploring_element = total_search_ptr->data;

	while (total_search_ptr->next != NULL)
	{
		is_deleted = 0;
		cycle_search_ptr = total_search_ptr;
		while (1)
		{
			if (cycle_search_ptr->next == NULL) break;

			if (isEqualGroup(exploring_element, cycle_search_ptr->next->data) == GROUPS_ARE_EQUAL)
			{
				node* item = cycle_search_ptr->next;
				prev = cycle_search_ptr;
				prev->next = prev->next->next;
				free(item);
				is_deleted = 1;
				break;
			}
			prev = cycle_search_ptr;
			cycle_search_ptr = cycle_search_ptr->next;
		}
		prev = total_search_ptr;
		if (is_deleted == 0) total_search_ptr = total_search_ptr->next;
		exploring_element = total_search_ptr->data;
	}

	return head;
}
