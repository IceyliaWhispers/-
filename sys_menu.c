#include<stdio.h>
#include "commoncolortool.h"
#define HEAD_ONE 30
#define HEAD_TWO 28
#define HEAD_THREE 30
#define HEAD_FOUR 16

void welcome_menu()
{
	
	int menu_number;
	printf("\n\n\n");
	printf("\t************************************************************\n\n");
	printf("\t      * 帅哥美女们，欢迎使用信息管理系统 *\n\n");
	printf("\t*      ~~~~~~本人很高兴为您服务~~~~~~      *\n\n");
	printf("\t         *     *           *     *\n");
	printf("\t        *  *  *  *        *  *  *  *\n");
	printf("\t       *    *     *      *     *    *     **\n");
	printf("\t      *            *    *            *    ***\n");
	printf("\t**********************************************\n");
	printf("\t      *            *    *            *    ***\n");
	printf("\t       *          *      *          *     **\n");
	printf("\t        *        *        *        *\n");
	printf("\t         *      *          *      *\n");
	printf("\t          *    *            *    *\n");
	printf("\t           *  *              *  *\n");
	printf("\t            **                **\n");
	printf("\t          \n");
	printf("\t                            --------程序设计基础课程组");
	SetColor(BLACK, BRIGHTWHITE);
	printf("\n\n\n\t");
	system("pause");
	SetColor(BLACK, PALEYELLOW);
}

void main_menu()
{
	system("cls");
	printf("\t\t|* * * * * * * 学生管理系统 * * * * * *|\n");
	printf("\t\t|...........................|\n");
	printf("\t\t|请选择操作菜单序号（0-6）|\n");
	printf("\t\t|...........................|\n");
	printf("\t\t|1----学生信息录入|\n");
	printf("\t\t|2----学生信息排序|\n");
	printf("\t\t|3----学生信息查询|\n");
	printf("\t\t|4----学生分类查询|\n");
	printf("\t\t|5----学生信息删除|\n");
	printf("\t\t|6----学生信息修改|\n");
	printf("\t\t|0----退 出 |\n");
	printf("\t\t|...........................|\n");
	printf("\t\t|* * * * * * * * * * * * * * * * * * * *|\n");
}

void head_menu()
{SetColor(BLACK, PALEYELLOW);
	gotoxy(HEAD_ONE,3);
	printf("    @");
	gotoxy(HEAD_TWO,4);
	printf("     / \\\n  ");
	printf("\t\t                 ***\n");
	printf("\t\t                 ***\n");
	printf("\t\t                *****\n");
	printf("\t\t               *******");
	gotoxy(HEAD_THREE,5);
	printf("\n\n\n\n\t\t             ***************\n");
	printf("\t\t          **************************");
	gotoxy(HEAD_FOUR,6);
	printf("\n\n\n\n\n\t\t      *+-------o00o-----(_)-----o00o-------+*\n");
	printf("\t\t    *******************************************\n");
	printf("\t\t                 *******\n");
	printf("\t\t                **********\n");
	printf("\t\t               ************\n");
	printf("\t\t              **************\n");
	printf("\t\t               软件工程真香！！！");
	printf("\n\n\n\n\n\n");
	SetColor(BLACK, PALEYELLOW);
}
