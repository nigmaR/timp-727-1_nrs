#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct node
 	{
 		int value;
 		struct node *left;
 		struct node *right;
 		struct node *parent;
 	}node;
typedef struct tree
 	{
 		node *root;
 		int size;
 	}tree;
// инициализация пустого дерева
void init(tree *t)
{
	t->root=NULL;
	t->size=0;
}
//удалить все элементы из дерева


/* поиск элемента по значению. вернуть 0 если элемент найд
ен и ссылку на найденнйы элемент в переменную n если n !=
NULL. в случае если элемент не найден вернуть 1 
*/
int find_tree(tree *t, int znachenie, node **n)
{
	node *tmp=t->root;
	while (tmp != NULL)
	{
		if (znachenie < tmp->value)
		{
			tmp=tmp->left;
		}
		else if (znachenie > tmp->value)
		{
			tmp=tmp->right;
		}
		else if (znachenie == tmp->value)
		{
			*n=tmp;
			tmp=NULL;
			return 0;
		}
	}
	tmp=NULL;
	return 1;
}
/* вставка значения в дерево. вернуть 0 если вставка выпол
нена успешна,
1 если элемент уже существует
2 если не удалось выделить память для нового элемента
*/
int insert(tree *t, int znachenie)
{
	int i;
	node *pred=NULL;
	node *tmp=t->root;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (znachenie < tmp->value)
			{
				if (tmp->left == NULL)
				{
					pred=tmp;
					//i=0;
					node *element_spiska=malloc(sizeof(node));
					if (element_spiska == NULL)
						return 2;
					element_spiska->parent=pred;
					element_spiska->value=znachenie;
					element_spiska->left=NULL;
					element_spiska->right=NULL;
					pred->left=element_spiska;
					(t->size)++;
					tmp=NULL;
					return 0;
				}
				tmp=tmp->left;
			}
			else if (znachenie > tmp->value)
			{
				if (tmp->right == NULL)
				{
					pred=tmp;
					//i=0;
					node *element_spiska=malloc(sizeof(node));
					if (element_spiska == NULL)
						return 2;
					element_spiska->parent=pred;
					element_spiska->value=znachenie;
					element_spiska->left=NULL;
					element_spiska->right=NULL;
					pred->right=element_spiska;
					(t->size)++;
					tmp=NULL;
					return 0;
				}	
				tmp=tmp->right;
			}
			else if (znachenie == tmp->value)
			{
				tmp=NULL;
				return 1;
			}
		}
	
	}
	node *element_spiska=malloc(sizeof(node));
		if (element_spiska == NULL)
			return 2;
	element_spiska->parent=NULL;
	element_spiska->value=znachenie;
	element_spiska->left=NULL;
	element_spiska->right=NULL;
	t->root=element_spiska;
	(t->size)++;
	tmp=NULL;
	return 0;	
}
/* удалить элемент из дерева по указанному значению. вернуть 0 если элемент был 
удален и 1 если нет элемента с указанным значением 
*/
int remove_(tree* t, int znachenie)
{
	node *tmp = t -> root, *udal_elem=NULL;
	node *min_right = NULL;
	find_tree(t,znachenie,&udal_elem);
	if (udal_elem == NULL)
		return 1;
	else if (udal_elem == t -> root)
	{
		if((udal_elem -> left == NULL ) && (udal_elem -> right == NULL))
		{
			t -> root = NULL;
			free(udal_elem);
			(t->size)--;
			return 0;
		}
		if((udal_elem -> left == NULL) && (udal_elem ->right != NULL))
		{
			udal_elem -> right -> parent = NULL;
			t -> root = udal_elem -> right;
			free(udal_elem);
			(t->size)--;
			return 0;
		}
		if((udal_elem -> left != NULL) && (udal_elem ->right == NULL))
		{
			udal_elem -> left -> parent = NULL;
			t -> root = udal_elem -> left;
			free(udal_elem);
			(t->size)--;
			return 0;
		}
		if ((udal_elem -> left != NULL) && (udal_elem -> right !=NULL))
		{
			min_right = udal_elem -> right;
			if (min_right -> left == NULL)
			{
				udal_elem -> value = min_right -> value;
				if (min_right -> right == NULL)
				{
					udal_elem -> right= NULL;
				}
				else
				{
					udal_elem -> right = min_right->right;
					min_right->right->parent = udal_elem;
				}
				min_right=NULL;
				free(min_right);
				(t->size)--;
				return 0;
			}
			else
			{
				while (min_right -> left != NULL)//ищем минимальный правого поддерева
					min_right = min_right -> left;
				udal_elem -> value = min_right -> value;
				if (min_right -> right == NULL)
					min_right -> parent -> left = NULL;
				else 
				{
					min_right -> parent -> left = min_right -> right;
					min_right -> right -> parent = min_right -> parent;
				}
				free(min_right);
				(t->size)--;
				return 0;
			}	
		
		}
	}
	else 
	{
		if((udal_elem -> left == NULL ) && (udal_elem -> right == NULL))
		{
			tmp= udal_elem -> parent;
			if (udal_elem == tmp -> right)
				tmp -> right = NULL;
			else
				tmp ->left = NULL;
			free(udal_elem);
			(t->size)--;
			return 0;
		}
		if((udal_elem -> left == NULL) && (udal_elem ->right != NULL))
		{
			tmp = udal_elem -> parent;
			if (udal_elem == tmp -> right)
				tmp -> right = udal_elem -> right;
			else
				tmp -> left = udal_elem -> right;
			udal_elem -> right -> parent = tmp;
			free(udal_elem);
			(t->size)--;
			return 0;
		}
		if((udal_elem -> left != NULL) && (udal_elem ->right == NULL))
		{
			tmp = udal_elem -> parent;
			if (udal_elem == tmp -> right)
				tmp -> right = udal_elem -> left;
			else
				tmp -> left = udal_elem -> left;
			udal_elem -> left -> parent = tmp;
			free(udal_elem);
			(t->size)--;
			return 0;
		}
		if ((udal_elem -> left != NULL) && (udal_elem -> right !=NULL))
		{
			min_right = udal_elem -> right;
			if (min_right -> left == NULL)
			{
				udal_elem -> value = min_right -> value;
				udal_elem -> right = NULL;
				free(min_right);
				(t->size)--;
				return 0;
			}
			else
			{
				while (min_right -> left != NULL)//ищем минимальный правого поддерева
					min_right = min_right -> left;
				udal_elem -> value = min_right -> value;
				if (min_right -> right == NULL)
					min_right -> parent -> left = NULL;
				else 
				{
					min_right -> parent -> left = min_right -> right;
					min_right -> right -> parent = min_right -> parent;
				}
				free(min_right);
				(t->size)--;
				return 0;

			}
			
		}
	}
}
/* удалить минимальный элемент из поддерева, корнем которо
го является n. вернуть значение удаленного элемента */
int revomeMin(node* n)
{
	int znach=0;
	node* min = n;
	node* tmp = n;
	while (min -> left != NULL)
		min = min -> left;
	if(min -> right == NULL)
		{
			tmp= min -> parent;
			if (min == tmp -> right)
				tmp -> right = NULL;
			else
				tmp ->left = NULL;
			znach= min -> value;
			free(min);
			return znach;
		}
	if(min -> right != NULL)
	{
		tmp = min -> parent;
		if (min == tmp -> right)
			tmp -> right = min -> right;
		else
			tmp -> left = min -> right;
		min -> right -> parent = tmp;
		znach= min -> value;
		free(min);
		return znach;
	}
}

/* выполнить левое вращение поддерева, корнем которого явл
яется n. вернуть 0 при успещшно выполнение операции и 1 в
случае если вращение невозможно */
int rotateLeft(node *n)
{
	node* tmp1=n;
	node* tmp2=n -> right;
	if (n->right != NULL)
	{
		if (n->right->left==NULL)
		{
			tmp1->right=NULL;
			tmp1->parent=tmp2;
			tmp2->left=tmp1;

		}
		else
		{
			tmp1->right=tmp2->left;
			tmp2->left->parent=tmp1;
			tmp1->parent=tmp2;
			tmp2->left=tmp1;

		}
		
		
		return 0;

	}
	else
		return 1;

}
int rotateRight(node *n)
{
	node* tmp1=n;
	node* tmp2=n -> left;
	if (n->left != NULL)
	{
		if (n->left->right==NULL)
		{
			tmp1->left=NULL;
			tmp1->parent=tmp2;
			tmp2->right=tmp1;

		}
		else
		{
			tmp1->left=tmp2->right;
			tmp2->right->parent=tmp1;
			tmp1->parent=tmp2;
			tmp2->right=tmp1;

		}
		
		
		return 0;

	}
	else
		return 1;

}
void clear(tree *t)
{
	int a=0;
	while (t->size!=0)
 	{
 		a=remove_(t,t->root->value);
 		
 	}
	
}

int max_(int x, int y) 
{
	return (((x) > (y)) ? (x) : (y));
}

int getDepth(node* n, int depth)
{
	if (n == NULL)
		return depth;
	return max_(getDepth(n->left,depth +1),getDepth(n->right,depth +1));
}
/*вывести все значения из поддерева корнем которого являе
тся n по уровнем, начиная с корня. каждый уровень выводитс
я на своей строке. элементы в строке разделяются пробелом.
 если на указанном месте нет элемента, заменить его значен
ием '_'. Если дерево пусто вывести '-'
*/
void print(node* n)
{
	node* tmp=n;
	node* tmp3=n;
	node* tmp2=NULL;// glubina количество уровней дерева
	int lvl=1,i=0,j=0,glubina=0,z=0,y=0;// lvl дерева считаем от 0, просто нулевой уровень выводим не в цикле
	if (tmp==NULL)
		printf("-\n");
	else 
	{
		printf("%d\n",tmp3->value);
	}
	glubina=getDepth(tmp3,glubina);
	while (lvl < glubina)//повышение уровня
	{

		z= (1<<lvl)-1;
		for (i=0;i<(1<<lvl);i++)//проход вдоль уровня
		{
			y=z;
			int *arr;
			arr = (int*)malloc(lvl * sizeof(int));
  			for (int k=lvl-1;k>=0;k--)
  			{
  				arr[k]=y%2;
   	 			y /= 2;
  			}
			tmp2 = tmp;
			for (j=0;j<lvl;j++)// проход вниз от корня до элемента этого уровня
			{	
				if (tmp2 == NULL)
				{    
					break;

				}
				else
				{
					if(arr[j]==1)
					{
						tmp2 = tmp2->left;
					}
					else
					{
						tmp2 = tmp2->right;
					}
				}
	
			}
			if (tmp2 == NULL)
				printf("_");
			else
				printf("%d",tmp2->value);
			if ((i+1)<(1<<lvl))
				printf(" ");
			z--;
			free(arr);
		}
		lvl++;
		printf("\n");
	}
	tmp=NULL;
	tmp2=NULL;
	free(tmp);
	free(tmp2);
	
	
}
void printTree(tree* t)
{
	print(t->root);
}
void obhod_v_shirinu(node* n)
{
	node* tmp=n;
	node* tmp3=n;
	node* tmp2=NULL;// glubina количество уровней дерева
	int lvl=1,i=0,j=0,glubina=0,z=0,y=0;// lvl дерева считаем от 0, просто нулевой уровень выводим не в цикле
	if (tmp==NULL)
		printf("-\n");
	else 
	{
		printf("%d ",tmp3->value);
	}
	glubina=getDepth(tmp3,glubina);
	while (lvl < glubina)//повышение уровня
	{

		z= (1<<lvl)-1;
		for (i=0;i<(1<<lvl);i++)//проход вдоль уровня
		{
			y=z;
			int *arr;
			arr = (int*)malloc(lvl * sizeof(int));
  			for (int k=lvl-1;k>=0;k--)
  			{
  				arr[k]=y%2;
   	 			y /= 2;
  			}
			tmp2 = tmp;
			for (j=0;j<lvl;j++)// проход вниз от корня до элемента этого уровня
			{	
				if (tmp2 == NULL)
				{    
					break;

				}
				else
				{
					if(arr[j]==1)
					{
						tmp2 = tmp2->left;
					}
					else
					{
						tmp2 = tmp2->right;
					}
				}
	
			}
			//if (tmp2 == NULL)
			//	printf("_");
			if (tmp2 != NULL)
			{
				printf("%d",tmp2->value);
				if ((i+1)<(1<<lvl))
					printf(" ");
			}
			z--;
			free(arr);
		}
		lvl++;
		printf(" ");
	}
	printf("\n");
	tmp=NULL;
	tmp2=NULL;
	free(tmp);
	free(tmp2);
	
}
/*void obhod_simm(node* root)
{
	node* tmp=root;
	node* lastNode=NULL;
	while(tmp)
	{
		if (lastNode == tmp->parent)
		{
			if (tmp->left != NULL)
			{
				lastNode = tmp;
				tmp = tmp->left;
			}
			else
				lastNode = NULL;
		}
		if (lastNode == tmp->left)
		{
			printf("%d",tmp->value);
			if (tmp->right != NULL)
			{
				lastNode = tmp;
				tmp = tmp -> right;
			}
			else
				lastNode = NULL;
		}
		if (lastNode == tmp ->right)
		{
			lastNode = tmp;
			tmp = tmp ->parent;
		}

	}
}
*/
void obhod_obratniy(node* root,int* razmer)
{
	
	if (root)
	{
		obhod_obratniy(root->left,razmer);
		obhod_obratniy(root->right,razmer);
		if (*razmer==1)
			printf("%d",root->value);
		else
		{
			*razmer=*razmer-1;
			printf("%d ",root->value);
			
		}


	}
}
void obhod_pryamoi(node* root)
{
	node* tmp=root;
	printf("%d ",root->value);
	while(tmp)
	{
		int i=0;
		if (tmp->left != NULL)
		{
			tmp = tmp->left;
			printf("%d ",tmp->value);
			i++;
		}
		else if (tmp -> right != NULL)
		{
			tmp = tmp -> right;
			printf("%d ",tmp->value);
			i++;
		}
		else if (tmp->left == NULL && tmp->right == NULL)
		{
			while (tmp->parent != NULL)
			{
				if ((tmp == tmp->parent->left) && (tmp -> parent -> right != NULL))
				{
					tmp = tmp -> parent -> right;
					printf("%d ",tmp->value);
					i++;
				}
				else
					tmp = tmp -> parent;
				if (i!=0)
					break;
			}
		}
		if (i==0)
			tmp = NULL;



	}

}
int main(void)
{
	int i,a,razm;
 	tree* tree_a=NULL;
 	tree_a=(tree *)malloc(sizeof(tree));
 	init(tree_a);
 	for(i=0;i<7;i++)
 	{
 		scanf("%d",&a);
 	    insert(tree_a, a);
 	}
	razm=tree_a->size;
	int* razm_p=&razm;
 	obhod_obratniy(tree_a->root,razm_p);
 	printf("\n");
	return 0;
}
