#include<iostream>
using namespace std;
#define size 7
int arr[size];
void init()
{
for (int i = 0; i < size; i++)
{
arr[i] = -1;
}
}
void insert(int value)
{
int key = value % size;
if (arr[key] == -1)
{
arr[key] = value;
cout << value << " inserted at arr[" << key << "]" << endl;
}
else
{
cout << "Collision : arr[" << key << "] has element " << arr[key] << " already!" << endl;
cout << "Unable to insert " << value << endl;
}
}
void search(int value)
{
int key = value % size;
if (arr[key] == value)
{
cout << "Search Found" << endl;
}
else
{
cout << "Search Not Found" << endl;
}
}
void display()
{
for (int i = 0; i < size; i++)
{
cout << "arr[" << i << "] = " << arr[i] << endl;
}
} int main()
{
init();
insert(1);
insert(40);
insert(2);
insert(3);
cout << "Hash table" << endl;
display();
cout << endl;
cout << "Searching value 4.." << endl;
search(40);
cout<<"\n ";
return 0;
}