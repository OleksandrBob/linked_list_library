#ifndef HEADER_H
#define HEADER_H

struct Slibrary {
	char pcAuthor[50];
	char pcBookName[50];
	int nYear;
	int nPages;
	int nValue;
}slNewElement;

typedef struct Node {
	struct Slibrary data;
	struct Node* pNext;
}node;


int CountNumOfElements(node* head);
void AddNewElement(node** pnHead, int nCountOfElements);
void PrintAllElements(node* pnHead, int nCountOfElements);
void DeleteTheElement(node** pnHead, int nIndextoDelete, int nCountOfElements);
void DeleteByCondition(node** pnHead, int nCountOfElements);
void DumpDataToFile(node* pnHead, int nCountOfElements);
void PrintBiggerThanMedium(node* pnHead, int nCountOfElements);
void EditNode(node* pnHead);
void SearchElement(node* pnHead);
node* GetDataFromFile();
void FreeMemory(node* pnHead, int nCountOfElements);


#endif