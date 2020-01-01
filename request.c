/*Huy Duong
This program is modify from the project 9 and add more delete function the the program*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "readline.h"
#include "request.h"
struct request *append_to_list(struct request *list){

struct request *new = malloc(sizeof(struct request));//create new cus for the user input

 printf("Enter room number: ");
 scanf("%d",&new->room_number);	//store the input

 struct request *temp = NULL;
 for(temp = list;temp!=NULL;temp = temp->next)
 {
	 if(new->room_number == temp->room_number)
	 {
		 //if the room exists
		 printf("Request for this room already exists. To update number of items, enter operation code: u\n");
		 free(new);
		 return list;
	 }
 }
 printf("Enter guest first name: ");
 read_line(new->first,NAME_LEN);
 printf("Enter guest last name: ");
 read_line(new->last,NAME_LEN);
 printf("Enter number of items: ");
 scanf("%d",&new->num_items); //collect the neccessary data
 if(list== NULL)
 {
	list = new;
	new->next = NULL;
	return list;
 }	//if list empty add node to the first position
 if(list->next==NULL)
 { 
      //if there 2 elements 
     if(strcmp(new->last,list->last)>0)
     { 
	  //compare  last name
          list->next = new;
          new->next = NULL;
          return list;
      }
      if(strcmp(new->last,list->last)<0)
      { 
	  //compare last name
          new->next = list;
          list = new;
          return list;
      }
      if(strcmp(new->last,list->last)==0)
      {  
	  //if there last names the same
          if(strcmp(new->first,list->first)<=0)
	  {
	      //compare  first name
              new->next = list;
              list = new;
              return list;
          }
          if(strcmp(new->first,list->first)>0)
	  { 
	       //compare first name
               list->next = new;
               new->next = NULL;
               return list;
           }
      }
  }
//if 2 or more elements in the list
 struct request *cur=NULL;
 struct request *pre=NULL;
 for(cur = list->next, pre = list;cur != NULL;pre = cur, cur = cur->next)
 {
     if(strcmp(new->last,pre->last)<0)
     { 
	//compare last name
         new->next = pre;
         list = new;
         return list;
     }
     if(strcmp(new->last,pre->last)>0&&strcmp(new->last,cur->last)<0)
     { 
	//compare their last name with the current and previous element
         new->next=cur;
         pre->next=new;
         return list;
     }
     if(cur->next==NULL&&strcmp(new->last,cur->last)>0) //if the new request is at the end of the list
       { 
         cur->next=new;
         new->next=NULL;
         return list;
      }
     if(strcmp(new->last,cur->last)==0) //if their last names are similar
       { 
         if(strcmp(new->first,cur->first)<=0)//compare first name
	   {  
             new->next=cur;
             pre->next=new;
             return list;
          }
         if(strcmp(new->first,cur->first)>0)//compare first name
	  { 
              new->next=cur->next;
              cur->next=new;
              return list;
          }
     }
     if(strcmp(new->last,pre->last)==0&&pre==list)
      {
         if(strcmp(new->first,pre->first)>0)
	   {
             new->next=pre->next;
             pre->next=new;
             return list;
    	   }
     }
     if(strcmp(new->first,pre->first)<=0)
       {
             new->next=pre;
             list=new;
             return list;
        }
     }
 }	//if list node null add to the next elements
 return list;
}
struct request *delete_from_list(struct request *list)
{
    while(list!=NULL)
	{  //while the list is not pointing to NULL
        struct request* user= malloc(sizeof(struct request));
        printf("Enter room number: ");
        scanf("%d", &user->room_number);
        printf("Enter guest first name: ");
        read_line(user->first,NAME_LEN);
        printf("Enter guest last name: ");
        read_line(user->last,NAME_LEN);
      //get info from user input
		struct request* cur = NULL;
        struct request* pre = NULL;
        for(cur = list, pre  =NULL; cur != NULL; pre = cur, cur = cur->next)
	   {
            if(cur->room_number==user->room_number&& strcmp(user->first,cur->first)==0&& strcmp(user->last,cur->last)==0)
	      { 
		//if the information matches
                if(cur == list)
		  {  //if the request in the first element 
                    list = list->next;
                    free (cur); //free the first element
                    printf("Request for room %d, guest %s %s deleted",user->room_number,user->first,user->last);
                    free (user);
                    return list;
                   }
                   else
		   {
                    pre->next=cur->next;
                    free (cur); //free the requested element
                    printf("Request for room %d, guest %s %s deleted",user->room_number,user->first,user->last);
                    free (user);
                    return list;
                }
            }
        }
        printf("Room %d, guest name %s %s not found",user->room_number,user->first, user->last);    //if the indexing pointer reaches the end
        free (user);
        return list;
    }
    return list;
}

void update(struct request *list)
{
	while(list!=NULL)
	{
		int room_num,item_num;
		printf("Enter room number: ");
		scanf("%d",&room_num);
		struct request *temp=NULL;
		for(temp = list; temp != NULL; temp = temp->next)
		{
			if(temp->room_number==room_num)
			{	//if the room exists
				printf("Enter the number of items to be added: ");
				scanf("%d",&item_num);	//ask the user to update
				temp->num_items += item_num;
				printf("Room %d, number of items is updated to %d",temp->room_number, temp->num_items);
				return;
			}
		}
		if(temp == NULL)	printf("Service request is not found for room %d, to add to the list, enter operation code: a\n", room_num);	//if there is no room was found
		return;
	}
	return;
}
void printList(struct request *list)
{

  struct request *temp=NULL;
  while(list != NULL)
  {
	printf("Room Number\tFirst Name\tLast Name\tNumber of Items\n");
  	for(temp = list; temp != NULL; temp = temp->next)
	{
		printf("%-16d%-16s%-23s%d\n",temp->room_number,temp->first, temp->last, temp->num_items);	//print the information according to the format
  	}
	return;
  }
}
void clearList(struct request *list)
{
 struct request *p;
 while(list != NULL)
 {
	 p = list;
	 list = list->next;
	 if(p != NULL)
	 	free(p);//clear the memory that p point to
 }
 return;
}
