#include "sys_menu.h" 
#include "StudentBLL.h" 
#include "APP_CONFIG.h" 
#include "StudentADT.h" 
#include "StudentFile.h" 
#include "commoncolortool.h" 
#include "commonpositiontool.h" 
#include "sys_menu.h" 
#include "StudentAction.h" 

#include <stdio.h> 
#include <Windows.h>

STATUS login()
{
	char userAcount[20];
	char userPassword[20];
	int i;
	system("cls");
	login_menu();
	printf("\t\t账号:");
	scanf("%s",userAcount);
	printf("\t\t密码:");
	for(i=0;i<20;i++)
	{
		userPassword[i]=getch();
		if(userPassword[i]=='\r')
		{
			break;
		}
		printf("*");
	}
	userPassword[i]='\0';
	if(isUserValid(userAcount,userPassword)==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int loginCounter=0; 
	int menu_number;
	struct studentNode* list = NULL;
	
	welcome_menu();
	
	while(loginCounter<3)
	{
		if(login()==1)
		{
			printf("\t\t欢迎进入系统，请稍后......\n");
			Sleep(1000);
			list = createlist();
			while(1)
			{
				main_menu();
		        printf("\n\t请选择序号： ");
		        scanf("%d",&menu_number);
		        
		        main_menu_choose(list,menu_number); 
			}
		}
		else
		{
			fflush(stdin);
			printf("\n\t\t用户和密码输入错误，按任意键请重新输入\n");
			Sleep(1);
			getchar();
			loginCounter++;
		}
	}
	if(loginCounter==3)
	{
		printf("\n\t\t连续输错3次，程序即将退出......\n");
		Sleep(2000);
		exit(ERROR);
	}
	return 0;
}
