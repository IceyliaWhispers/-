#include"Student.h"
#include"StudentADT.h"
#include<stdlib.h>

struct studentNode* createlist()
{
	struct studentNode* listHeadNode = (struct studentNode*)malloc(sizeof(struct studentNode));
	listHeadNode->next = NULL;
	return listHeadNode;
}

struct studentNode* createNode(struct student data)
{
	struct studentNode* newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertNodeByHead(struct studentNode* listHeadNode, struct student data)
{
	struct studentNode* newNode = createNode(data);
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

void sort(struct studentNode* listHeadNode)
{
	struct studentNode* q = listHeadNode->next;
	struct studentNode* p = NULL;
	struct studentNode* temp = NULL;
	
	if (q == NULL)
	{
		printf("\n\t\t没有信息!!!!\n");
	}
	
	for (q = listHeadNode->next; q->next != NULL; q = q->next)
	{
		for (p = q->next; p != NULL; p = p->next)
		{
			if (atoi(q->data.num) > atoi(p->data.num))//#include <stdlib.h>
			{
				struct student temp;
				 temp = q->data;
				 q->data = p->data;
				 p->data = temp; 
			}
		}
	}
}

struct studentNode* searchNodeByNum(struct studentNode* listHeadNode, char* num)
{
	struct studentNode* pMove = listHeadNode->next;
	
	if (pMove == NULL)
	{
		return NULL;
	}
	
	while (pMove != NULL)
	{
		if (strcmp(pMove->data.num, num) != 0)
		{
			pMove = pMove->next;
			
			if (pMove == NULL)
			{
				return NULL;
			} 
		}
		if (strcmp(pMove->data.num, num) == 0)
		{
			return pMove;
		} 
	}
}

void printNode(struct studentNode* curNode)
{
	printf("\t\t*-----------------------------------------------------------------------*\n");
	printf("\t\t|\t学号  \t| \t姓名\t   | \t性别\t |  \t专业\t        |\n");
	printf("\t\t*-----------------------------------------------------------------------*\n");
	
	printf("\t\t| %s\t| \t%s\t   |\t%s\t | \t%s\t        |\n", curNode->data.num, curNode->data.name, curNode->data.sex, curNode->data.major);
		
	printf("\t\t*-----------------------------------------------------------------------*\n");
}

struct studentNode* searchNodeByName(struct studentNode* listHeadNode, char* name)
{
	struct studentNode* pMove = listHeadNode->next;
	
	if (pMove == NULL)
	{
		return NULL;
	}
	while (pMove != NULL)
	{
		if (strcmp(pMove->data.name, name) != 0)//#include <string.h> 
		{
			pMove = pMove->next;
			if (pMove == NULL)
			{
				return NULL;
			} 
		}
		if (strcmp(pMove->data.name, name) == 0)
		{
			return pMove;
		}
	}
}

void printNodeBySex(struct studentNode* listHeadNode, char* sex)
{
	struct studentNode* pMove = listHeadNode->next;
	
	if (pMove == NULL)
	{
		printf("\n\t\t\t没有信息!!!!\n");
		return;
	}
	
	while (pMove != NULL)
	{
		if (strcmp(pMove->data.sex, sex) != 0)
		{
			pMove = pMove->next;
			if (pMove == NULL)
			{
				printf("\t\t\t没有此性别的学生!!!\n") ;
				return ; 
			}
		 }
		if (strcmp(pMove->data.sex, sex) == 0)
		{
			printf("\t\t| %s\t| \t%s\t   |\t%s\t | \t%s\t        |\n", pMove->data.num, pMove->data.name, pMove->data.sex, pMove->data.major);
	printf("\t\t*-----------------------------------------------------------------------*\n");
		pMove = pMove->next;
		}
	}
}

void printNodeByMajor(struct studentNode* listHeadNode, char* major)
{
	struct studentNode* pMove = listHeadNode->next;
	
	if (pMove == NULL)
	{
		printf("\n\t\t\t没有信息!!!!\n");
		return;
	}
	
	while (pMove != NULL)
	{
		if (strcmp(pMove->data.major, major) != 0)
		{
			pMove = pMove->next;
			
			if (pMove == NULL)
			{
				
				printf("\t\t\t没有此专业的学生！！！"); 
				
				return ; 
			} 
		}
		if (strcmp(pMove->data.major, major) == 0)
		{
			
		printf("\t\t| %s\t| \t%s\t   |\t%s\t | \t%s\t        |\n", pMove->data.num, pMove->data.name, pMove->data.sex, pMove->data.major);
	printf("\t\t*-----------------------------------------------------------------------*\n");
		pMove = pMove->next;
		} 
	}
}

void deleteNodeByStudentNum(struct studentNode* listHeadNode, char* num)
{
	struct studentNode* posFrontNode = listHeadNode;
	
	struct studentNode* posNode = listHeadNode->next;
	
	if (num == NULL)
	{
		printf("\t\t\t无法删除!\n");
		return; 
	}
	else
	{
		while (strcmp(posNode->data.num, num))
		{
			posFrontNode = posNode;
			
			posNode = posFrontNode->next;
			
			if (posNode == NULL)
			{
				printf("\t\t\t无法删除!\n");
				return; 
			} 
		}
		
		posFrontNode->next = posNode->next;
		
		free(posNode);
		
		printf("\n\t\t\t删除成功!即将返回主页面!\n");
	}
}

void updateStudent(struct studentNode* listHeadNode, char* num,struct studentNode* newDataNode)
{
	struct studentNode* curNode = searchNodeByNum(listHeadNode,num);
	
	strcpy(curNode->data.num,newDataNode->data.num);
	
	strcpy(curNode->data.name,newDataNode->data.name);
	
	strcpy(curNode->data.major,newDataNode->data.major);
	
	strcpy(curNode->data.sex,newDataNode->data.sex);
}
