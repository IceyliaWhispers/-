#include"StudentBLL.h"
void main_menu_choose(struct studentNode* list,int menu_number)
{
	system("cls");
	switch(menu_number)
	{
		case 0:
			quit();
			break;
		case 1:
			addstudent(list);
			break;
		case 2:
			sortstudent(list);
			break;
		case 3:
			querystudent(list);
			break;
		case 4:
			querystudentClassification(list);
			break;
		case 5:
			deletestudent(list);
			break;
		case 6:
			updatestudent(list);
			break;
		default:
			showMessage();
			break;
	}
	system("pause");
} 
