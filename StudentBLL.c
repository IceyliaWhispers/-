#include<stdio.h>
#include<windows.h>
#include<string.h>
#include"APP_CONFIG.h"
#include"StudentFile.h"
#include"StudentBLL.h"
#include"Student.h"
#include"StudentADT.h"
void showMessage()
{
	printf("\n\n\t\t�������......");
	printf("������ϣ��������˵�����......");
}

void quit()
{
	head_menu();
	printf("\t\t���򼴽��˳�......\n");
	Sleep(2000); 
	exit(ERROR);
}

int check(struct studentNode* list, struct student tempData)
{
	int flag=0;
	struct studentNode* p=NULL;
	p=list->next;
	while(p!=NULL)
	{
		if(strcmp(p->data.num,tempData.num)==0)
		{
			flag=1;
			break;
		}
		else
		{
			p=p->next;
		}
	}
	return flag;
}

void printList(struct studentNode* listHeadNode)
{
	struct studentNode* pMove=listHeadNode->next;
	printf("\t\t----------------------\n");
	printf("\t\t|\t ѧ�� \t|  ����  | �Ա� |  רҵ  |\n");
	printf("\t\t----------------------\n");
	while(pMove)
	{
		printf("\t\t|  %s  | %s  | %s | %s |\n",pMove->data.num,pMove->data.name,pMove->data.sex,pMove->data.major);
		printf("\t\t----------------------\n");
		pMove=pMove->next;
	}
	printf("\n");
}

void addstudent(struct studentNode* list)
{
	system("cls");
	head_menu();
	printList(list);
	while(TRUE)
	{
		int flag;
		struct student tempData;
		char cContinue;
		printf("\t\t������ѧ�ţ��������Ա�רҵ\n");
		scanf("%s %s %s %s",tempData.num,tempData.name,tempData.sex,tempData.major);
		flag=check(list,tempData); 
		if(flag==ISEXIST)
		{
			printf("�ظ�ѧ�Ų������룡������\n");
			printf("���⽨����\n");
			system("pause");
		}
		else
		{
			insertNodeByHead(list,tempData);
		}
		system("cls");
		head_menu();
	    printList(list);
	    printf("\t\t�Ƿ�������ѧ����Y/N��");
		getchar();
		scanf("%c",&cContinue);
		if(cContinue=='Y' || cContinue=='y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	saveInfoToFile("student.txt",list);
	printf("\t\t��������ص����˵�......");
	system("pause");
}

void sortstudent(struct studentNode* list)
{
	head_menu();
	printf("\t\t����ǰ��\n");
	printList(list);
	sort(list);
	printf("\t\t�����\n");
	printList(list);
	printf("\t\t��������ص���һ���˵�......\n");
	system("pause");
}

void querystudent(struct studentNode* list)
{
	struct student tempData;
	struct studentNode *p=NULL;
	char cContinue;
	int queryType;
	
	while(TRUE)
	{
		system("cls");
		head_menu();
		
		printf("\n\n");
		printf("\t\t| 1----��ѯ������Ϣ |\n");
		printf("\t\t| 2----����ѧ�Ų�ѯ |\n");
		printf("\t\t| 3----����������ѯ |\n");
		
		scanf("%d",&queryType);
		if(queryType==1)
		{
			printList(list);
		}
		else if(queryType==2)
		{
			printf("\t\t���������ѧ����ѧ�ţ�"); 
			scanf("%s",tempData.num);
			
			p=searchNodeByNum(list,tempData.num);
			if(p==NULL)
			{
				printf("\t\tû����ص���Ϣ\n");
			}
			else
			{
				printNode(p);
			} 
		}
		else if(queryType==3)
		{
			printf("\t\t���������ѧ����������"); 
			scanf("%s",tempData.name);
			
			p=searchNodeByName(list,tempData.name);
			if(p==NULL)
			{
				printf("\t\tû����ص���Ϣ\n");
			}
			else
			{
				printNode(p);
			} 
		}
		else
		{
			printf("\t\t�������\n");
		}
		printf("\t\t�Ƿ������ѯ��Y/N ");
		getchar();
		scanf("%c",&cContinue); 
		if(cContinue=='Y' || cContinue=='y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void deletestudent(struct studentNode* list)
{
	struct student tempData;
	char cContinue;
	
	system("cls");
	head_menu();
	printList(list);
	
	while(TRUE)
	{
		printf("\t\t������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%s",tempData.num);
		
		deleteNodeByStudentNum(list,tempData.num);
		
		system("cls");
	    head_menu();
	    printList(list);
	    
	    printf("\t\t�Ƿ����ɾ��ѧ����Y/N");
		getchar();
		scanf("%c",&cContinue); 
		if(cContinue=='Y' || cContinue=='y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void querystudentClassification(struct studentNode* list)
{
	int classification;
	struct student tempData;
	char cContinue;
	
	system("cls");
	head_menu();
	printList(list);
	
	while(TRUE)
	{
		printf("\t\t| 1----�����Ա��ѯ |\n");
		printf("\t\t| 2----����רҵ��ѯ |\n");
		scanf("%d",&classification);
		
		if(classification==1)
		{
			printf("\t\t�������������ѧ���Ա�");
			scanf("%s",tempData.sex);
			system("cls");
			
			head_menu();
			
			printf("\t\t-----------------------------------\n");
			printf("\t\t| ѧ�� | ����   | �Ա� | רҵ |\n");
			printf("\t\t-----------------------------------\n");
			
			printNodeBySex(list,tempData.sex);
		}
		else if(classification==2)
		{
			printf("\t\t�������������ѧ��רҵ��");
			scanf("s",tempData.major);
			system("cls");
			
			head_menu();
			
			printf("\t\t-----------------------------------\n");
			printf("\t\t| ѧ�� | ����   | �Ա� | רҵ |\n");
			printf("\t\t-----------------------------------\n");
			
			printNodeByMajor(list,tempData.major);
		}
		else
		{
			printf("\t\t�������"); 
		}
		
		printf("\t\t�Ƿ������ѯ��Y/N");
		getchar();
		scanf("%c",&cContinue); 
		if(cContinue=='Y' || cContinue=='y')
		{
			system("cls");
			head_menu();
			printList(list);
		}
		else
		{
			break;
		}
	}
}

void updatestudent(struct studentNode* list)
{
	struct student tempData;
	struct studentNode* newDataNode;
	char cContinue;
	
	system("cls");
	head_menu();
	printList(list);
	
	while(TRUE)
	{
		printf("\t\t��������Ҫ�޸�ѧ����ѧ�ţ�");
		scanf(" %s",tempData.num);
		if(searchNodeByNum(list,tempData.num)==NULL)
		{
			printf("\t\tû�������Ϣ\n");
		}
		else
		{
			newDataNode=(struct studentNode*)malloc(sizeof(struct studentNode));
			
			printf("\t\t�������µ�ѧ����Ϣ\n");
			printf("\t\tѧ��\t����\t�Ա�\tרҵ\n");
			scanf("%s%s%s%s",newDataNode->data.num,newDataNode->data.name,newDataNode->data.sex,newDataNode->data.major);
			
			updateStudent(list,tempData.num,newDataNode);
			
			system("cls");
	        head_menu();
	        printList(list);
		}
		
		printf("\t\t�Ƿ�����޸ģ�Y/N");
		getchar();
		scanf("%c",&cContinue); 
		if(cContinue=='Y' || cContinue=='y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	saveInfoToFile("student.text",list);
}

int mystrcmp(const char *s1, const char *s2)
{
	while(*s1==*s2)
	{
		if(*s1=='\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1-*s2;
}

STATUS isUserValid(char *userAcount,char *userPassword)
{
	if(mystrcmp(userAcount,"xiaobin")==0 && mystrcmp(userPassword,"swpu")==0)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}
