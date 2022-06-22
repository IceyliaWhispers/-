#include "Student.h"
//将内存链表中的数据保存到磁盘文件，参数为链表和文件 
void saveInfoToFile(char* fileName, struct studentNode* listHeadNode);

//将磁盘文件的内容读入内存链表，参数为链表和文件 
void readInfoFromFile(char* fileName, struct studentNode* listHeadNode);
