#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Student.h"
void saveInfoToFile(char* fileName, struct studentNode* listHeadNode)
{
	FILE* fp = fopen(fileName,"w+");
	struct studentNode* pMove = listHeadNode->next;
	
	while(pMove)
	{
		fprintf(fp,"%s %s %s %s\n",pMove->data.num,pMove->data.name,pMove->data.sex,pMove->data.major);
		pMove = pMove->next;
	}
	fclose(fp);
}

void readInfoFromFile(char* fileName, struct studentNode* listHeadNode)
{
	struct student tempData;
	FILE* fp = fopen(fileName,"r");
	if(fp==NULL)
	{
		fp = fopen(fileName,"w+");
	}
	while(fscanf(fp,"%s %s %s %s\n",tempData.num,tempData.name,tempData.sex,tempData.major) != EOF)
	{
		struct student studentNode = tempData;
		struct student tempData;
		insertNodeByHead(listHeadNode,studentNode);
	}
}
