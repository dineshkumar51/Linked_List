#include <stdio.h>
 #include <stdlib.h>
 struct Node
 {
   int data;
   struct Node *next;
 }*first=NULL,*second=NULL,*third=NULL;
 
 
void create(int A[],int n)
{
  int i;
  struct Node *t,*last;
  first=(struct Node *)malloc(sizeof(struct Node));
  first->data=A[0];
  first->next=NULL;
  last=first;
  for(i=1;i<n;i++)
  {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}


void create1(int A[],int n)
{
  int i;
  struct Node *t,*last;
  second=(struct Node *)malloc(sizeof(struct Node));
  second->data=A[0];
  second->next=NULL;
  last=second;
  for(i=1;i<n;i++)
  {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}
 
 
 void Display(struct Node *p)
 {
    printf("\n");
    while(p!=NULL)
   {
     printf("%d ",p->data);
     p=p->next;
   }
   
}
 
 
 void RDisplay(struct Node *p)
 {
   printf("\n");     
   if(p!=NULL)
   {
       RDisplay(p->next);
      printf("%d ",p->data);
   }
  

 }
 
 int count(struct Node *p)
{
  printf("\n");
  int l=0;
  while(p)
  {
    l++;
    p=p->next;
  }
 
 return l;
 
}


 int sum(struct Node *p)
 {
    printf("\n"); 
    int s=0;
    while(p!=NULL)
    {
      s+=p->data;
      p=p->next;
    }
    return s;
    
 }

int Max(struct Node *p)
{
  printf("\n");
  int max=-32768;
  while(p)
  {
    if(p->data>max)
    max=p->data;
    p=p->next;
  }
 return max;
 
 } 
 
 struct Node * LSearch(struct Node *p,int key)
 {
 
 printf("\n"); 
 while(p!=NULL)
 {
    if(key==p->data)
    {
       
        return p;
        
    }
    p=p->next;
 }
 }

void insert (struct Node *p,int pos,int x)
{
    printf("\n");
    struct Node *t;
    int i;
    if (pos<0 || count(p)<pos)
     {
         printf("invalid position");
         return;
     }
     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=x;
     if (pos == 0)
     {
         t->next = first;
         first=t;
     }
     
     if (pos >0)
     {
         for(i =0;i<pos-1;i++)
         {
             p=p->next;
         }
         t->next = p->next;
         p->next = t;
     }
    
}

int Delete (struct Node *p,int pos)
{
    struct Node *q;
    int i,x;
    if (pos<0 || pos>count(p))
    {
        printf("invalid position");
        return;
    }
    
    if (pos == 1)
    {
     x = p->data;
     first = first->next;
     free(p);
     return x;
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
            
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}


int isSorted(struct Node *p)
{

  printf("\n");    
  int x=-65536;
  while(p!=NULL)
  {
      if (p->data<x)
       return 0;
       
     x = p->data;
     p = p->next;
  }
  return 1;
}

void remove_duplicate(struct Node *p)
{
    struct Node *q = first->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        if(p->data==q->data)
        {
           p->next = q->next;
           free(q);
           q=p->next;
        }
    }
}

void reverse (struct Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;

}


void Merge(struct Node *p,struct Node *q)
{
 
  struct Node *last;
  if(p->data < q->data)
  {
      third=last=p;
      p=p->next;
      third->next=NULL;
  }

 else
 {
      third=last=q;
      q=q->next;
      third->next=NULL;
 }
 while(p && q)
 {
   if(p->data < q->data)
  {
      last->next=p;
      last=p;
      p=p->next;
      last->next=NULL;
  }
  else
  {
      last->next=q;
      last=q;
      q=q->next;
      last->next=NULL;
  }
 
     
 }
 if(p)last->next=p;
 if(q)last->next=q;
  }

int isLoop(struct Node *f)
{
    printf("\n");
    struct Node *p,*q;
    f=p=q;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
        
    }while(p && q && p!=q);
    return p == q?1:0;
    
}

int main()
{
  struct Node *temp;
  int A[]={3,5,7,10,25,32,78,78,100};
  int B[]={2,3,5,6,7,8};
  create(A,9);
  create1(B,6);
  Display(first);
  Display(second);
  Merge(first,second);
  Display(third);
  int l = isLoop(first);
  printf("%d",l);
  //int c = count(first);
  //printf("%d",c);
  //int s = sum(first);
  //printf("%d",s);
  //int m = Max(first);
  //printf("%d",m);
  //temp=LSearch(first,8);
  //printf("%d",temp);
  //insert(first,3,9);
  //int d = Delete(first,2);
  //printf("%d",d);
  //int so = isSorted(first);
  //printf("%d",so);
  //Display(first);
  //remove_duplicate(first);
  //Display(first);
  //reverse(first);
  //Display(first);
  return 0;
  
  
}
