#ifndef MY_LIST
#define MY_LIST

#include "STRUCT.h"

#define MAX_SYMBOLS_IN_NUM 20

enum check_number { NUM_IS_GOOD = 0, NUM_IS_BAD = -1 };

// Структура - элемент списка
// Поля - указатель на группу (структуру struct study_group) и указатель на следующий элемент

struct my_list
{
	group* data;
	struct my_list* next;
};

typedef struct my_list node;

void PrintList(node* head);

node* CreateNode(node* insert_node, group* g);

node* InsertToStart(node* head, group* grp);

node* DeleteFromStart(node* head);

node* InsertInSortList(node* head, group* g);

node* DeleteSameNodes(node* head);

#endif MY_LIST
