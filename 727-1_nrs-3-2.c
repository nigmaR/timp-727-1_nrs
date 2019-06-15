#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
 	{
 		int value;
 		struct node *next;
 		struct node *prev;
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
	{
		l->tail->next=element_spiska;
		element_spiska->prev=l->tail;

	}
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
	element_spiska->prev=NULL;
	element_spiska->next=l->head;
	l->head->prev=element_spiska;
	if(l->tail == NULL)
    {
        l->tail = element_spiska;
    }
    else
    {
        l->head->prev = element_spiska;
    }
	l->head=element_spiska;
	return 0;
}
// Вставка значения после указанного узла, вернуть 0 если успешно
int insertAfter(list* l, int position, int znachenie)
{
    node *tmp, *sec;
    tmp = l->head;

    if(tmp == NULL)
        {
            return 1;
        }
    for (int i = 1; i < position; i++)
    {
        if(tmp->next == NULL)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    sec = tmp->next;

    node *element_spiska;
    element_spiska = (node*)malloc(sizeof(node));
    element_spiska->next = sec;
    element_spiska->prev = tmp;
    element_spiska->value = znachenie;

    tmp->next = element_spiska;
    if (sec != NULL)
    {
        sec->prev = element_spiska;
    }
    if(l->tail == tmp)
    {
        l->tail = element_spiska;
    }

    if(tmp->next->value == znachenie)
    {
        return 0;
    }
    return 1;
}
int insertBefore( list* l, int position, int znachenie)
{
 
    struct node *tmp, *pre;
    tmp = l->head;

    if(tmp == NULL)
        {
            return 1;
        }
    for (int i = 1; i < position; i++)
    {
        if(tmp->next == NULL)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    pre = tmp->prev;
    node* element_spiska = (node*)malloc(sizeof(node));
    element_spiska->next = tmp;
    element_spiska->prev = pre;
    element_spiska->value = znachenie;

    tmp->prev = element_spiska;
    if(pre != NULL)
    {
        pre->next = element_spiska;
    }
    if(l->head == pre)
    {
        l->head = element_spiska;
    }

    if(tmp->prev->value == znachenie)
    {
        return 0;
    }
    return 1;
}
int removeFirst( list* l, int znachenie)
{
    node *tmp, *sec, *pre;
    tmp = l->head;
    pre = NULL;

    if(tmp == NULL)
        {
            return 1;
        }
    while (tmp->value != znachenie)
    {
        if(tmp->next == NULL)
        {
            return 1;
        }
        pre = tmp;
        tmp = tmp->next;
    }
    sec = tmp->next;

    free(tmp);

    if(pre == NULL)
    {
        l->head = sec;
    }
    else
    {
        pre->next = sec;
    }
    if(sec == NULL)
    {
        l->tail = pre;
    }
    else
    {
        sec->prev = pre;
    }

    return 0;

}
int removeLast(list* l, int znachenie)
{
    node *tmp, *sec, *pre;
    tmp = l->tail;
    sec = NULL;

    if(tmp == NULL)
        {
            return 1;
        }
    while (tmp->value != znachenie)
    {
        if(tmp->prev == NULL)
        {
            return 1;
        }
        sec = tmp;
        tmp = tmp->prev;
    }
    pre = tmp->prev;

    free(tmp);

    if(pre == NULL)
    {
        l->head = sec;
    }
    else
    {
        pre->next = sec;
    }
    if(sec == NULL)
    {
        l->tail = pre;
    }
    else
    {
        sec->prev = pre;
    }

    return 0;
}

// вывести все значения из списка в прямом порядке, через
//пробел, после окончания вывода перейти на новую строку
/*void print(list* l)
{
	node* tmp=l->head;
	while(tmp)
	{
		if ((tmp)->next)
		{
			printf("%d",(tmp)->value);
			tmp=(tmp)->next;
			printf(" ");
		}
		else 
		{
			printf("%d",(tmp)->value);
			tmp=NULL;
		}
	}
	tmp=NULL;
	printf("\n");
}
*/
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
void print_invers(list* l)
{
    node *tmp=l->tail;
    while(tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->prev;
        if (tmp->prev == NULL)
        {
        	printf("%d", tmp->value);
        	tmp = tmp->prev;
        }
    }
    tmp=NULL;
    printf("\n");
}
/*void print_invers(list* l)
{
    node *tmp;
    tmp = l->tail;
    while(tmp)
    {
    		if (tmp->prev)
    	{
       	 	printf("%d", tmp->value);
       	 	tmp = tmp->prev;
       	 	printf(" ");
    	}
    	else
    	{
    		printf("%d",tmp->value);
			tmp=NULL;
    	}
    }
    tmp=NULL;
    printf("\n");
}
*/

int main(void)
{
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
        printf("%d", 1);
    }
    else{printf("%d", 0);}
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
    print_invers(list_a);
	//7
	int t;
    scanf("%d", &t);
    push_front(list_a, t);
    print(list_a);
    //9
    int j,x;
    scanf("%d %d", &j, &x);
    insertAfter(list_a, j, x);
    print_invers(list_a);
    //11
    int u, y;
    scanf("%d %d", &u, &y);
    insertBefore(list_a, u, y);
    print(list_a);
    //13
    int z;
    scanf("%d", &z);
    removeFirst(list_a, z);
    print_invers(list_a);
    //15
    int r;
    scanf("%d", &r);
    removeLast(list_a, r);
    print(list_a);
    //17
    clear(list_a);

 	return 0;
}
