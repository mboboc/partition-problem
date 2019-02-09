#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"
#include "ft_atoi.c"
#include <string.h>
#include <sys/time.h>

void insertAt(List* list, Item elem, int pos);

void printList(List *list) {
	if (list == NULL || list->first == NULL) {
		printf("List == NULL\n");
		return;
	}
	while (list->first != NULL) {
		printf("%d ", list->first->elem);
		list->first = list->first->next;
	}
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b);
}

int KKAlgo(List **list, int size, FILE *fid) {
	ListNode    *n1;
	ListNode    *n2;
	ListNode    *aux;
	int         e1;
	int         e2;
	int         i;
	int         pos;
	int         diff;
	int         inserted;
    struct      timeval t0, t1;
    int         aux_size;
    
    aux_size = size;
    gettimeofday(&t0, NULL);
	i = size;
    while (i != 1) {
		n1 = (*list)->first;
		n2 = (*list)->first->next;
		e1 = n1->elem;
		e2 = n2->elem;
		deleteOnce(*list, e1);
		deleteOnce(*list, e2);
		size = size - 2;
		diff = abs(e1 - e2);
		pos = 0;
		inserted = 0;
		aux = (*list)->first;
		while (pos < size) {
			if (diff > aux->elem) {
				insertAt(*list, abs(e1 - e2), pos);
				size++;
				inserted = 1;
				break;
			}
			aux = aux->next;
			pos++;
		}
		if (inserted == 0) {
			insertAt(*list, abs(e1 - e2), size);
			size++;
		}
		i--;
	}	
	gettimeofday(&t1, NULL);
    long elapsed = (t1.tv_sec - t0.tv_sec)*1000000 + t1.tv_usec - t0.tv_usec;
    //fprintf(fid, "KKAlgo: %d\n", (*list)->first->elem);
	//fprintf(fid, "KKAlgoRUNTIME: %ld ms\n", elapsed);
	//fprintf(fid, "%d ", (*list)->first->elem);
    //fprintf(fid, "%d", aux_size);
    return (*list)->first->elem;
}

int greedyAlgo(List **list, int size, FILE *fid) {
	ListNode    *aux;
	int         sum1;
	int         sum2;
    struct      timeval t0, t1;

    gettimeofday(&t0, NULL);
	sum1 = 0;
    sum2 = 0;
    aux = (*list)->first;
    while (size > 0) {
		if (sum1 >= sum2) {
			sum2 = sum2 + aux->elem;
			deleteOnce(*list, aux->elem);
		} else {
			sum1 = sum1 + aux->elem;
			deleteOnce(*list, aux->elem);
		}
        aux = aux->next;
		size--;
	}
	gettimeofday(&t1, NULL);
    long elapsed = (t1.tv_sec - t0.tv_sec)*1000000 + t1.tv_usec - t0.tv_usec;
    //fprintf(fid, "greedyAlgo: %d\n", abs(sum1 - sum2));
	//fprintf(fid, "greedyAlgoRUNTIME: %ld ms\n", elapsed);
	//fprintf(fid, "%d", abs(sum1 - sum2));
    fprintf(fid, "%d", elapsed);
    return abs(sum1 - sum2);
}

int main(int argc, char *argv[]) {
	int         size = 0;
	int         i;
	int         buff;
	List        *list;
	List        *list1;
	char        *aux;
	int         *bufferArray;
	int         diff;
	int         diff1;
	FILE        *fid;
	int         auxSize;
	char        *c;
    
    auxSize = 0;
	bufferArray = (int *)malloc(sizeof(int) * argc - 2);
	list = createList();
	list1 = createList();
	if (argc > 1) {
		c = argv[0];
		while (*c != '\0') {
			auxSize ++;
			c++;
		}
		if (auxSize == 7) {
			aux = malloc(14 * sizeof(char));
			strcat(aux, "out/");
			strcat(aux, argv[0] + 2);
			aux[9] = '.';
			aux[10] = 'o';
			aux[11] = 'u';
			aux[12] = 't';
			aux[13] = '\0';
		} else if (auxSize == 8) {
			aux = malloc(14 * sizeof(char));
			strcat(aux, "out/");
			strcat(aux, argv[0] + 2);
			aux[10] = '.';
			aux[11] = 'o';
			aux[12] = 'u';
			aux[13] = 't';
			aux[14] = '\0';
		} else {
			aux = malloc(15 * sizeof(char));
			strcat(aux, "out/");
			strcat(aux, argv[0] + 2);
			aux[11] = '.';
			aux[12] = 'o';
			aux[13] = 'u';
			aux[14] = 't';
			aux[15] = '\0';
		}
		size = ft_atoi(argv[1]);
		i = 2;
		while (i < size + 2) {
			buff = ft_atoi(argv[i]);
			bufferArray[i - 2] = buff;
			i++;
		}
		qsort(bufferArray, size, sizeof(int), cmpfunc);
		i = 0;
		while (i < size) {
			insertAt(list, bufferArray[i], 0);
			insertAt(list1, bufferArray[i], 0);
			i++;
		}
		fid = fopen(aux, "w");	
		diff = greedyAlgo(&list, size, fid);
		diff1 = KKAlgo(&list1, size, fid);
		fclose(fid); 
	}
}
