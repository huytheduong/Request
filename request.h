/*Huy Duong
This program is modify from the project 9 and add more delete function the the program*/
#ifndef REQUEST_H
#define REQUEST_H
#define NAME_LEN 30
struct request{//info of the cus in the list
	int room_number;
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	int num_items;
	struct request *next;
};//declare all the prototype
struct request *append_to_list(struct request *list);
struct request *delete_from_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
#endif
