#include<iostream>
#include<stdlib.h>
#include<assert.h>

#define NAME_MAX  10
#define SEX_MAX  10
#define ADDR_MAX  15
#define TELE_MAX  15
#define PEOPLE_MAX  1000 

using namespace std;

class contact{
	
public:
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
};
class Infor{
public:
	contact data[PEOPLE_MAX];
	int sz;
};

enum MyEnum
{
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	FIND,
	SHOW,
	SORT
};

void IntInfor(Infor *infor);
void addInfor(Infor *infor); 
void deleteInfor(Infor *infor);
void modefyInfor(Infor *infor);
void coutInfor(Infor *infor);
int findInfor(Infor *infor, char *name);
void srotInfor(Infor *infor);
void searchInfor(Infor *infor);