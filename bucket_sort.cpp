#include<stdio.h>
#include<stdlib.h>

/*  Sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed
    across the range. How do we sort the numbers efficiently? Bucket sort. */

struct node {
	float data;
	struct node *next;
};

void addNode(struct node **q, float num) {
	struct node *insertNode = (struct node*) malloc(sizeof(struct node));
	insertNode->data = num;
	struct node *temp = *q;

	/* If it's the first node */
	if (NULL == *q){
		*q = insertNode;
		(*q)->next = NULL;
	/* If the new node is to be inserted before the first node */
	} else if (num < temp->data) {
		*q = insertNode;
		(*q)->next = temp;
	/* Traverse the entire linked list to find the correct point of insertion */
	} else {
		while(temp != NULL) {
			if(temp->data <= num && (temp->next == NULL || num <= temp->next->data)) {
				insertNode->next = temp->next;
				temp->next = insertNode;
				return;
			}
			temp = temp->next;
        }
	}
}

void printList(struct node *temp) {
	while(temp != NULL) {
		printf("%.4f ", temp->data);
		temp = temp->next;
	}
}

void bucketSort(float arr[], int n) {
	struct node *p[n];

	/* Initialize by empty buckets */
	for(int i = 0; i < n; i++) p[i] = NULL;

	/* Put array elements in n different buckets */
	for(int i = 0; i < n; i++) {
		/* Calculating the index of insertion into the bucket array */
		int bucketIndex = n*arr[i];
		addNode(&p[bucketIndex], arr[i]);
	}

	for(int i = 0; i < n; i++) printList(p[i]);
	printf("\n");
}

int main(){
	float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	int n = sizeof(arr)/sizeof(arr[0]);
	bucketSort(arr,n);
}
