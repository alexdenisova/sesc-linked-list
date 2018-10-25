#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{ 
  int data; 
  struct node *next; 
}; 



void append(struct node** head, int data) { 
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head;
    temp->data  = data; 
    temp->next = NULL; 
  
    if (*head == NULL) 
    { 
       *head = temp; 
       return; 
    } 
  
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = temp; 
    return; 
} 

  void dump(struct node *node) 
{ 
  if(node == NULL){
    printf("empty\n");
  }
  while (node != NULL) 
  {
     printf("%d", node->data); 
     node = node->next;
     if(node != NULL){
       printf(" ");
     } else{
       printf("\n");
     }
  } 
}
void push(struct node** head, int data) 
{ 
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data  = data;
    temp->next = (*head); 
    (*head)    = temp; 
}
void popfront (struct node** head) {
  struct node* temp = *head; 
  if((*head) == NULL){
    printf("empty\n");
  } else{
        printf("%d\n", temp->data);
        *head = temp->next; 
        free(temp);
  }
}

void peekfr(struct node** head) {
  struct node* temp = *head; 
  if((*head) == NULL){
    printf("empty\n");
  } else{
        printf("%d\n", temp->data);
  }
}

void peekb(struct node** head) {
  struct node *last = *head;
  if ((*head) == NULL) {
    printf("empty\n"); 
  } else{
  while (last->next != NULL)
    last = last->next; 

  printf("%d\n", last->data);
  }
}

void sze(struct node** head) {
  struct node* temp = *head; 
  int z = 1;
  if ((*head) == NULL) {
    printf("0\n"); 
  }else{
    while (temp->next!=NULL){
      z++;
      temp = temp->next;
    }
    printf("%d\n", z);
  }
  
}

void clear(struct node** head) {
  struct node* temp = *head;
  struct node* first = *head;
  if ((*head) == NULL) {
    printf("empty\n"); 
  } else{
    *head = NULL;
    printf("empty\n"); 
  }
}

int main() 
{ 
  struct node* head = NULL;
  char s[1000], str[100][100], dumpstr[100], appendstr[100], q[100], pushstr[100], popstr[100], peekfrontstr[100], peekbackstr[100], szestr[100], clrstr[100];
  strcpy(dumpstr, "dump");
  strcpy(appendstr, "push-back");
  strcpy(pushstr, "push-front");
  strcpy(popstr, "pop-front");
  strcpy(peekfrontstr, "peek-front");
  strcpy(peekbackstr, "peek-back");
  strcpy(szestr, "size");
  strcpy(clrstr, "clear");


  int a=0, j=0, n=0, i=0, r=0;
  fgets(s, 1000, stdin);
  int len = strlen(s);
  while(sscanf(s, "%s", str[j])!=EOF){
    int onestr(){
      r = strlen(str[j]);
      i=0;
      for(n=(r+1); (n)<len; n++){
			  s[i]=s[n];
        i++;
		  }
		  for(n=0; (n-r)<len; n++){
			  s[i+n]='\0';
		  }
		  len=strlen(s);
      j++;
    }


    if(strcmp(str[j],dumpstr)==0){
      dump(head);
    }else if(strcmp(str[j], clrstr)==0){
      clear(&head);
    } else if(strcmp(str[j], szestr)==0){
      sze(&head);
    } else if(strcmp(str[j],peekbackstr)==0){
      peekb(&head);
    } else if(strcmp(str[j],peekfrontstr)==0){
      peekfr(&head);
    } else if(strcmp(str[j],popstr)==0){
      popfront(&head);
    } else if(strcmp(str[j],pushstr)==0){
      sscanf(s, "%s %d", str[j], &a);
      onestr();
      sscanf(s, "%s", str[j]);
      push(&head, a);
      printf("%d\n", a);
      
    } else if(strcmp(str[j],appendstr)==0){
      sscanf(s, "%s %d", str[j], &a);
      onestr();
      sscanf(s, "%s", str[j]);
      append(&head, a);
      printf("%d\n", a);
      
    } else {
      //onestr();
      printf("error unknown operation %s\n", str[j]);
    }
    onestr();
    
  }
  
  return 0; 
} 