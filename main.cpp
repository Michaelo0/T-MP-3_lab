

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
typedef struct my_list{
    	int data;
    struct my_list* next;
    } MList;

int add(MList* phead, int index, int data)
{
    	MList *item = new MList;
    	MList *tmp = NULL;
    	int i;
    
    	item->data = data;
    	item->next = NULL;
    
    	tmp = phead;
    	i = 0;
    	while (tmp->next != NULL && i<index) {
        		i++;
        		tmp = tmp->next;
        	}
    	item->next = tmp->next;
    	tmp->next = item;
    	return 0;
    }

int del(MList* item, int index)
{
    	return 0;
}

int get(MList* phead, int index, int* pdata)
{
    	MList *tmp = phead;
    	int i = 0;
    	while (tmp->next != NULL && i<=index) {
        		tmp = tmp->next;
        		i++;
        	}
    	*pdata = tmp->data;
    	cout<<tmp->data<<endl;
    	return 0;
    }

    void getsize(MList* phead, int* size) {
        	MList* tmp = phead;
        	int i=0;
        	while (tmp->next != NULL) {
            		tmp = tmp->next;
            		i++;
            	}
        	*size = i;
        }

    int graphlist(MList* phead) {
        	MList* tmp = phead->next;
        	int i=0;
        	cout<<"digraph structs {"<<endl;
        	cout<<"graph[rankdir=LR];"<<endl;
        	cout<<"node[shape=record]"<<endl;
        
        	while (tmp->next != NULL) {
            		cout<<"struct"<<i<<"[label=\"{<f0>"<<tmp->data<<"|<f1>}\"];"<<endl;
            		tmp = tmp->next;
            		i++;
            		cout<<"struct"<<i-1<<":<f1>->struct"<<i<<":<f0>;"<<endl;
            	}
        		cout<<"struct"<<i<<"[label=\"{<f0>"<<tmp->data<<"|<f1>}\"];"<<endl;
        	cout<<"}"<<endl;
        	return 0;
        }

    int main()
    {
        	MList head;
        	head.next = NULL;
        	string command;
        	int data, size, ncommand;
        	cin>>ncommand;
        	for (int i=0; i<ncommand; i++) {
                cin>>command;
                if (!command.compare(0,3,"add"))
                {
                        int pos, dat;
                        cin>>pos>>dat;
                        add(&head, pos, dat);
                }
            	}
        	add(&head, 0, 10);
          	add(&head, 0, 11);
          	add(&head, 1, 12);
          	add(&head, 2, 13);
        
        	getsize(&head, &size);
        	cout<<size<<endl;
        	for (int i=0; i<size; i++) {
            	get(&head, i, &data);
            	}
        	graphlist(&head);
        	return 0;
        }