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
	printf("\t      * ˧����Ů�ǣ���ӭʹ����Ϣ����ϵͳ *\n\n");
	printf("\t*      ~~~~~~���˺ܸ���Ϊ������~~~~~~      *\n\n");
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
	printf("\t                            --------������ƻ����γ���");
	SetColor(BLACK, BRIGHTWHITE);
	printf("\n\n\n\t");
	system("pause");
	SetColor(BLACK, PALEYELLOW);
}

void main_menu()
{
	system("cls");
	printf("\t\t|* * * * * * * ѧ������ϵͳ * * * * * *|\n");
	printf("\t\t|...........................|\n");
	printf("\t\t|��ѡ������˵���ţ�0-6��|\n");
	printf("\t\t|...........................|\n");
	printf("\t\t|1----ѧ����Ϣ¼��|\n");
	printf("\t\t|2----ѧ����Ϣ����|\n");
	printf("\t\t|3----ѧ����Ϣ��ѯ|\n");
	printf("\t\t|4----ѧ�������ѯ|\n");
	printf("\t\t|5----ѧ����Ϣɾ��|\n");
	printf("\t\t|6----ѧ����Ϣ�޸�|\n");
	printf("\t\t|0----�� �� |\n");
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
	printf("\t\t               ����������㣡����");
	printf("\n\n\n\n\n\n");
	SetColor(BLACK, PALEYELLOW);
}
