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
	printf("\n\n\t\t输入错误......");
	printf("操作完毕，返回主菜单继续......");
}

void quit()
{
	head_menu();
	printf("\t\t程序即将退出......\n");
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
	printf("\t\t|\t 学号 \t|  姓名  | 性别 |  专业  |\n");
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
		printf("\t\t请输入学号，姓名，性别，专业\n");
		scanf("%s %s %s %s",tempData.num,tempData.name,tempData.sex,tempData.major);
		flag=check(list,tempData); 
		if(flag==ISEXIST)
		{
			printf("重复学号不能输入！！！！\n");
			printf("任意建继续\n");
			system("pause");
		}
		else
		{
			insertNodeByHead(list,tempData);
		}
		system("cls");
		head_menu();
	    printList(list);
	    printf("\t\t是否继续添加学生？Y/N：");
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
	printf("\t\t按任意键回到主菜单......");
	system("pause");
}

void sortstudent(struct studentNode* list)
{
	head_menu();
	printf("\t\t排序前：\n");
	printList(list);
	sort(list);
	printf("\t\t排序后：\n");
	printList(list);
	printf("\t\t按任意键回到上一级菜单......\n");
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
		printf("\t\t| 1----查询所有信息 |\n");
		printf("\t\t| 2----按照学号查询 |\n");
		printf("\t\t| 3----按照姓名查询 |\n");
		
		scanf("%d",&queryType);
		if(queryType==1)
		{
			printList(list);
		}
		else if(queryType==2)
		{
			printf("\t\t请输入查找学生的学号："); 
			scanf("%s",tempData.num);
			
			p=searchNodeByNum(list,tempData.num);
			if(p==NULL)
			{
				printf("\t\t没有相关的信息\n");
			}
			else
			{
				printNode(p);
			} 
		}
		else if(queryType==3)
		{
			printf("\t\t请输入查找学生的姓名："); 
			scanf("%s",tempData.name);
			
			p=searchNodeByName(list,tempData.name);
			if(p==NULL)
			{
				printf("\t\t没有相关的信息\n");
			}
			else
			{
				printNode(p);
			} 
		}
		else
		{
			printf("\t\t输入错误\n");
		}
		printf("\t\t是否继续查询？Y/N ");
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
		printf("\t\t请输入要删除的学生学号：");
		scanf("%s",tempData.num);
		
		deleteNodeByStudentNum(list,tempData.num);
		
		system("cls");
	    head_menu();
	    printList(list);
	    
	    printf("\t\t是否继续删除学生？Y/N");
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
		printf("\t\t| 1----按照性别查询 |\n");
		printf("\t\t| 2----按照专业查询 |\n");
		scanf("%d",&classification);
		
		if(classification==1)
		{
			printf("\t\t请输入想输出的学生性别：");
			scanf("%s",tempData.sex);
			system("cls");
			
			head_menu();
			
			printf("\t\t-----------------------------------\n");
			printf("\t\t| 学号 | 姓名   | 性别 | 专业 |\n");
			printf("\t\t-----------------------------------\n");
			
			printNodeBySex(list,tempData.sex);
		}
		else if(classification==2)
		{
			printf("\t\t请输入想输出的学生专业：");
			scanf("s",tempData.major);
			system("cls");
			
			head_menu();
			
			printf("\t\t-----------------------------------\n");
			printf("\t\t| 学号 | 姓名   | 性别 | 专业 |\n");
			printf("\t\t-----------------------------------\n");
			
			printNodeByMajor(list,tempData.major);
		}
		else
		{
			printf("\t\t输入错误"); 
		}
		
		printf("\t\t是否继续查询？Y/N");
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
		printf("\t\t请输入想要修改学生的学号：");
		scanf(" %s",tempData.num);
		if(searchNodeByNum(list,tempData.num)==NULL)
		{
			printf("\t\t没有相关信息\n");
		}
		else
		{
			newDataNode=(struct studentNode*)malloc(sizeof(struct studentNode));
			
			printf("\t\t请输入新的学生信息\n");
			printf("\t\t学号\t姓名\t性别\t专业\n");
			scanf("%s%s%s%s",newDataNode->data.num,newDataNode->data.name,newDataNode->data.sex,newDataNode->data.major);
			
			updateStudent(list,tempData.num,newDataNode);
			
			system("cls");
	        head_menu();
	        printList(list);
		}
		
		printf("\t\t是否继续修改？Y/N");
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
