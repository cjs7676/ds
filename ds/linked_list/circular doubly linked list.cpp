#include <iostream>
using namespace std;
class node
{
public:
int data;
int key;
node *next;
node *prev;

};
node *head = NULL;
node *last = NULL;
node *current;

bool isEmpty()
{
return head == NULL;
}

int length()
{
int length = 0;
node *current;
for(current = head; current != NULL; current = current->next)
{
length++;
}
return length;
}

void displayForward()
{
node *ptr = head;
cout<<"\n[ ";
while(ptr != NULL)
{
cout<<ptr->key,ptr->data;
ptr = ptr ->next;
}
cout<<" ]";
}

void displayBackward()
{
node *ptr = last;
cout<<"\n[ ";
while(ptr != NULL)
{
cout<<ptr->key,ptr->data;
ptr = ptr ->prev;
}
cout<<" ]";
}

void insertFirst(int key, int data){
node *link = new node();
link -> key = key;
link -> data = data;
if(isEmpty()){
last = link;
}
else{
head->prev = link;
}
link->next = head;
head = link;
}

void insertLast(int key, int data){
node *link = new node();
link -> key = key;
link -> data = data;
if(isEmpty()){
last = link;
}
else{
last->next = link;
}
link->prev = last;
last = link;
}

node* deleteFirst(){
node *tempLink = head;
if(head->next == NULL){
last = NULL;
}
else{
head->next->prev = NULL;
}
head = head -> next;
return tempLink;
}

node* deleteLast(){
node *tempLink = last;
if(head->next == NULL){
head = NULL;
}
else{
last->prev->next = NULL;
}
last = last -> prev;
return tempLink;
}

node* del(int key)
{
node* current = head;
node* previous = NULL;
if(head == NULL)
{
return NULL;
}
while(current ->key != key)
{
if(current->next == NULL)
{
return NULL;
}
else
{
previous = current;
current = current->next;
}
}
if(current ==  head)
{
head = head->next;
}
else
{
current ->prev->next = current->next;
}
if(current == last)
{
last = current ->prev;
}
else
{
current ->next->prev = current->prev;
}
return current;
}

bool insertAfter(int key, int newKey, int data)
{
node *current = head;
if(head == NULL)
{
return false;
}
while(current->key != key)
{
if(current->next == NULL)
{
return false;
}
else
{
current =  current->next;
}
}
node *newLink = new node();
newLink->key = newKey;
newLink->data = data;
if(current==last)
{
newLink->next = NULL;
last = newLink;
}
else
{
newLink->next = current->next;
current->next = newLink;
}
newLink->prev = current;
current->next = newLink;
return true;
}
main()
{
cout<<"\n \n ";
insertFirst(1,10);
insertFirst(2,23);
insertFirst(3,30);
insertFirst(4,12);
insertFirst(5,44);
insertFirst(6,53);
cout<<"\nList(First to last): ";
displayForward(); 
cout<<"\nList(Last to first): ";
displayBackward();
cout<<"\nList, after deleting first record: ";
deleteFirst();
displayForward();
cout<<"\nList, after deleting last record:: ";
deleteLast();
displayForward();
cout<<"\nList, insert after key(4): ";
insertAfter(4,7,13);
displayForward();
cout<<"\nList, insert delete key(4): ";
del(4);
displayForward();
}
