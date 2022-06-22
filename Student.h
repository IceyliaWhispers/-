#ifndef _STUDENT
#define _STUDENT

struct student
{
	char num[15];
	char name[12];
	char sex[6];
	char major[20];
};

struct studentNode
{
	struct student data;
	struct studentNode* next;
};
#endif
