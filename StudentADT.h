#include "student.h"

struct studentNode* createlist();//1、创建空链表 
void insertNodeByHead(struct studentNode* listHeadNode, struct student data);//2、头插法，添加结点 
struct studentNode* createNode(struct student data);//3、动态创建一个新结点 

void sort(struct studentNode* listNodeHead);//4、按学号排序 
struct studentNode* searchNodeByNum(struct studentNode* listHeadNode, char* num);//5、按学号查询 

void printNode(struct studentNode* curNode);//6、打印某个结点信息 
struct studentNode* searchNodeByName(struct studentNode* listHeadNode, char* name);//7、按名字查询 

void printNodeBySex(struct studentNode* listHeadNode, char* sex);//8、按性别打印 

void printNodeByMajor(struct studentNode* listHeadNode, char* major);//9、按专业打印 

void deleteNodeByStudentNum(struct studentNode* listHeadNode, char* num);//10、按学号删除 

void updateStudent(struct studentNode* listHeadNode, char* num,struct studentNode* newDataNode);//11、更新学生信息 
