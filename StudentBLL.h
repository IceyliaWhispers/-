#include "APP_CONFIG.h"
#include "Student.h"

void quit();
void addstudent(struct studentNode* list);
void sortstudent(struct studentNode* list);
void querystudent(struct studentNode* list);
void querystudentClassification(struct studentNode* list);
void deletestudent(struct studentNode* list);
void updatestudent(struct studentNode* list);
void showMessage();
 
STATUS isUserValid(char *userAcount,char *userPassword);
STATUS login();

void printList(struct studentNode* listHeadNode);

int check(struct studentNode* list,struct student tempData);
