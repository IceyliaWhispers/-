#include "student.h"

struct studentNode* createlist();//1������������ 
void insertNodeByHead(struct studentNode* listHeadNode, struct student data);//2��ͷ�巨����ӽ�� 
struct studentNode* createNode(struct student data);//3����̬����һ���½�� 

void sort(struct studentNode* listNodeHead);//4����ѧ������ 
struct studentNode* searchNodeByNum(struct studentNode* listHeadNode, char* num);//5����ѧ�Ų�ѯ 

void printNode(struct studentNode* curNode);//6����ӡĳ�������Ϣ 
struct studentNode* searchNodeByName(struct studentNode* listHeadNode, char* name);//7�������ֲ�ѯ 

void printNodeBySex(struct studentNode* listHeadNode, char* sex);//8�����Ա��ӡ 

void printNodeByMajor(struct studentNode* listHeadNode, char* major);//9����רҵ��ӡ 

void deleteNodeByStudentNum(struct studentNode* listHeadNode, char* num);//10����ѧ��ɾ�� 

void updateStudent(struct studentNode* listHeadNode, char* num,struct studentNode* newDataNode);//11������ѧ����Ϣ 
