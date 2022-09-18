


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::: Question 5 ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct twostacks{
    int *arr,cap,top1,top2;
};

struct twostacks * createtwostacks(int capacity)
{
    struct twostacks * s= (struct twostacks *)(malloc(sizeof(struct twostacks)));
    s->arr= (int *)(malloc(sizeof(int)*capacity));
    s->cap=capacity,s->top1=-1,s->top2=capacity;
    return s;
}
void push1(struct twostacks *s,int x)
{
    if (s->top1 < s->top2 - 1) // condition for empty space in array
    {
        s->top1++;
        s->arr[s->top1] = x;
    }
}

void push2(struct twostacks *s,int x)
{
    if (s->top1 < s->top2 - 1) // condition for empty space in array
    {
        s->top2--;
        s->arr[s->top2] = x;
    }
}
int peek1(struct twostacks *s) // if stack1 is empty then return -1;
{
    if (s->top1 >= 0)
        return s->arr[s->top1];
    else
        return INT_MIN;
}
int peek2(struct twostacks *s) // if stack2 is empty then return -1
{
    if (s->top2 < s->cap)
        return s->arr[s->top2];
    else
        return INT_MIN;
}

int pop1(struct twostacks *s)
{
    if (s->top1 >= 0)
    {
        int x = s->arr[s->top1];
        s->top1--;
        return x;
    }
    else
        return INT_MIN; // if stack1 is empty
}

int pop2(struct twostacks *s)
{
    if (s->top2 < s->cap)
    {
        int x = s->arr[s->top2];
        s->top2++;
        return x;
    }
    else
        return INT_MIN; // if stack2 is empty

}

void printstack1(struct twostacks *s)
{
    printf("stack1 is :\n");
    for(int i=s->top1;i>=0;i--)
        printf("%d\n",s->arr[i]);
}
void printstack2(struct twostacks *s)
{
    printf("stack2 is :\n");
    for(int i=s->top2;i<s->cap;i++)
        printf("%d\n",s->arr[i]);
}

int main()
{
    struct twostacks *s= createtwostacks(5);
    push1(s,5);
    push1(s,10);
    push1(s,15);
    push2(s,2);
    push2(s,3);
    push2(s,8);
    printstack1(s);
    printstack2(s);
    pop1(s);
    pop2(s);
    printstack1(s);
    printstack2(s);
    printf("The peek of stack1 is %d\n",peek1(s));
    printf("The peek of stack2 is %d\n",peek2(s));

    return 0;
}





//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::: Question 6 ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





//::::::::::::::::::::::: doubly linked list  implementation of deque ::::::::::::::::::::::::::



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>



struct node{
	int data;
	struct node* next;
	struct node* prev;
};
struct node *create_node(char x)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct deque{
	struct node *rear, *front;
};

struct deque* CreateDeque(){
	struct deque* dq = (struct deque*)malloc(sizeof(struct deque));
	dq->rear = NULL;
	dq->front=NULL;
	return dq;
}

void push_front(struct deque* dq,int x){
	struct node* new_node = create_node(x);
	if(dq->front==NULL && dq->rear==NULL){
		
        dq->front=dq->rear=new_node;
	}
	else
    {
        new_node->next=dq->front;
        dq->front->prev=new_node;
        dq->front=new_node;
	}
}

void push_back(struct deque* dq,int x){
	struct node* new_node = create_node(x);
	if(dq->front==NULL && dq->rear==NULL){
		
        dq->front=dq->rear=new_node;
	}
	else
    {
        dq->rear->next=new_node;
        new_node->prev=dq->rear;
        dq->rear=new_node;
    }
}

int isEmpty(struct deque* dq){
	return dq->front==NULL;
}

int getFront(struct deque* dq){
	if(isEmpty(dq)) return INT_MIN;
	
	return dq->front->data;
}

int getRear(struct deque* dq){
	if(isEmpty(dq)) return INT_MIN;
	
	return dq->rear->data;
}

void pop_front(struct deque* dq){
	
    if(dq->front== NULL)  // single node or zero node
    {
        return;
    }   
    else if(dq->front==dq->rear)
    {
        struct node *temp=dq->front;
        free(temp);
        dq->front=dq->rear=NULL;
    }
    else
    {
        struct node *temp= dq->front;
        dq->front=dq->front->next;
        free(temp);
        dq->front->prev=NULL;

    }
}

void pop_back(struct deque* dq){
	
    if(dq->rear== NULL)  // single node or zero node
    {
        return;
    }   
    else if(dq->front==dq->rear)
    {
        struct node *temp=dq->front;
        free(temp);
        dq->front=dq->rear=NULL;
    }
    else
    {
        struct node *temp= dq->rear;
        dq->rear=dq->rear->prev;
        free(temp);
        dq->rear->next=NULL;
    }
    
}

void printDeque(struct deque *dq)
{
    struct node *curr=dq->front;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}



int main(){
	struct deque* dq = CreateDeque();
	push_front(dq,1);
	push_front(dq,2);
    push_back(dq,3);
	push_back(dq,5);
	push_front(dq,4);
    printDeque(dq);
    printf("front element is %d\n",getFront(dq));
    printf("rear element is %d\n",getRear(dq));
    pop_front(dq);
    pop_back(dq);
    printDeque(dq);
    printf("front element is %d\n",getFront(dq));
    printf("rear element is %d\n",getRear(dq));


    return 0;
} 



//::::::::::::::::::::::: array implementation of deque ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct deque{
    int *arr;
    int front,cap,size;
};

// all operations in O(1)

// maintaining circular array and front index and size and capacity

// we are maintaining a front index , here front can be any index in array and rear must be size-1 elements next in right circular manner

// circular 
// rear index can be found by rear= (front+size-1)%cap 

struct deque* createdeque(int capacity)
{
    struct deque *dq=(struct deque *)(malloc(sizeof(struct deque)));
    dq->arr= (int *)(malloc(sizeof(int)*capacity));
    dq->cap=capacity;
    dq->size=0;
    return dq;
}
bool isfull(struct deque *dq) 
{
    return dq->cap==dq->size;
}
bool isempty(struct deque *dq)
{
    return dq->size==0;
}
int getfront(struct deque *dq)
{
    if(isempty(dq))
        return INT_MIN;
    else
        return dq->arr[dq->front];
}
int getrear(struct deque *dq)
{
    int rear=(dq->front+dq->size-1)%dq->cap;  // rear index 
    if(isempty(dq))
        return INT_MIN;
    else
        return dq->arr[rear];
}
void  push_front(struct deque *dq,int x)  // for pushing front , to get index of new front , we have to shift front to front - 1 in circular manner
{
    if(isfull(dq))
        return;
    dq->front=(dq->front-1+dq->cap)%dq->cap;
    dq->arr[dq->front]=x;
    dq->size++;

}

void  push_back(struct deque *dq,int x)  // for pushing back , to get index of new rear , we just need to increment rear index by 1 in circular manner
{
    if(isfull(dq))
        return;
    
    int rear=(dq->front+dq->size)%dq->cap;
    dq->arr[rear]=x;
    dq->size++;
    

}

void pop_back(struct deque *dq)     // for popping back we just have to decrement rear index which can be done by decrementing current size
{
    if(isempty(dq))
        return;
    
    dq->size--;
}

void pop_front(struct deque *dq)  // to pop_front , we just need to increment front index by one 
{
    if(isempty(dq))
        return ;
   
    dq->front=(dq->front+1)%dq->cap;

    dq->size--;

}

void printdeque(struct deque *dq)
{

    int x=dq->size;
    int i=dq->front;
    while(x--)
    {
        printf("%d ",dq->arr[i]);
        i=(i+1)%dq->cap;
    }
    printf("\n");
}

int main()
{
    struct deque *dq= createdeque(10);
    push_front(dq,5);
    push_back(dq,10);
    push_back(dq,15);
    push_front(dq,8);
    push_back(dq,17);
    push_front(dq,2);
    push_back(dq,19);
    push_front(dq,1);
    printdeque(dq);
    pop_back(dq);
    pop_front(dq);
    printdeque(dq);
    pop_front(dq);
    pop_back(dq);
    printdeque(dq);
    printf("front element is %d\n",getfront(dq));
    printf("rear element is %d\n",getrear(dq));
    return 0;
}


