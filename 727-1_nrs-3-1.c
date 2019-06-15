#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
 	{
 		int value;
 		struct node *next;
 	}node;
typedef struct list
 	{
 		node *head;
 		node *tail;
 	}list;
// Инициализация пустого списка
void init(list *l)
 	{
 		//l=(list *)malloc(sizeof(list)); //ПОЧЕМУ ЕСЛИ СДЕЛАТЬ ВЫДЕЛЕНИЕ ПАМЯТИ ТУТ ПРОИСХОДИТ ОШИБКА СЕГМЕНТАЦИИ ФАЙЛА
 		l->head=NULL;
 		l->tail=NULL;

 	}
// Удаление всех элементов списка
void clear(list* l)
{
	node* tmp=NULL;
	while ((l->head)->next)
	{
		tmp=l->head;
		l->head=(l->head)->next;
		free(tmp);

	}
	free(l->head);
}
// Проверка на пустоту
int isEmpty(list *l)
{
	int a;
	a=(l->head==NULL)?1:0;
	return a;
}
// Поиск элемента по значению.NULL если элемент не найден.
node* find(list* l, int znachenie)
{
	node* tmp=l->head;
	while(tmp!=NULL)
	{
		if ((tmp->value)==znachenie)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}
// Вставка значения в конец списка, вернуть 0 если успешно
int push_back(list* l, int znachenie)
{
	node* element_spiska=(node*)malloc(sizeof(node));
	element_spiska->value=znachenie;
	element_spiska->next=NULL;
	if (l->tail != NULL)
		l->tail->next=element_spiska;
	else 
	{
		l->head=element_spiska;
	}
	l->tail=element_spiska;
	return 0;
}
// Вставка значения в начало списка, вернуть 0 если успешно
int push_front(list* l, int znachenie)
{
	node* element_spiska=(node*)malloc(sizeof(node));
	element_spiska->value=znachenie;
	element_spiska->next=l->head;
	l->head=element_spiska;
	return 0;
}
// Вставка значения после указанного узла, вернуть 0 если успешно
int insertAfter(list* l,node* n,int znachenie)
{
	node* element_spiska=(node*)malloc(sizeof(node));
	element_spiska->value=znachenie;
	element_spiska->next=n->next;
	if(n->next==NULL)
		l->tail=element_spiska;
	n->next=element_spiska;
	return 0;
}
// Удалить первый элемент из списка с указанным значением, вернуть 0 если успешно
int remo_ve(list* l, int znachenie)
{
	node* prev=l->head;
	node* tmp=prev->next;
	if (prev->value==znachenie)
	{
		l->head=prev->next;
		free(prev);
		tmp=NULL;
		return 0;
	}
	while (prev)
	{
		if (tmp->value==znachenie)
		{
			if(tmp==l->tail)
			{
				l->tail=prev;
				free(tmp);
				prev=NULL;
				return 0;
			}
			prev->next=tmp->next;
			free(tmp);
			prev=NULL;
			return 0;
		}
		prev=tmp;
		tmp=prev->next;
	}
	return 1;	
}
// вывести все значения из списка в прямом порядке, через
//пробел, после окончания вывода перейти на новую строку
void print(list* l)
{
	node* tmp=l->head;
	while(tmp)
	{
		printf("%d ",(tmp)->value);
		tmp=(tmp)->next;
		if (tmp->next == NULL)
		{
			printf("%d",(tmp)->value);
			tmp=(tmp)->next;
		}
	}
	tmp=NULL;
	printf("\n");
}

int main(void)
{
	//Считать количество элементов
	int n,a;
	scanf("%d",&n);
 	list* list_a=NULL;
 	//Создать пустой список, считать n элементов и занести их в список
 	list_a=(list *)malloc(sizeof(list));
 	init(list_a);
 	while (n>=1)
 	{
 		scanf("%d",&a);
 	    push_back(list_a, a);
 	    n--;
 	}
 	//Вывод содержимого списка 
 	print (list_a);
 	//
 	int k1, k2, k3;
    scanf("%d %d %d", &k1, &k2, &k3);
    if (find(list_a, k1) != NULL)
    {
        printf("%d",1);
    }
    else{printf("%d",0);}
    if (find(list_a, k2) != NULL)
    {
        printf("%d", 1);
    }
    else{printf("%d", 0);}
    if (find(list_a, k3) != NULL)
    {
        printf("%d\n", 1);
    }
    else{printf("%d\n", 0);}
    //5
    int m;
    scanf("%d", &m);
    push_back(list_a, m);
    print(list_a);
    //7
    int t;
    scanf("%d", &t);
    push_front(list_a, t);
    print(list_a);
    //9
    int j,x;
    scanf("%d %d", &j, &x);
    node* j_node=list_a->head;
    for (int i=1;i<j;i++)
    {
    	j_node=j_node->next;
    }
    insertAfter(list_a, j_node, x);
    print(list_a);
    //11
    int z;
    scanf("%d", &z);
    remo_ve(list_a, z);
    print(list_a);
   //13
    clear(list_a);
 	return 0;
}
