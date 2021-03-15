#include "header.h"
#include<stdio.h>
#include<string.h>

int CountNumOfElements(node* pnHead) {
	int c = 1;
	while (pnHead->pNext != NULL) {
		c++;
		pnHead = pnHead->pNext;
	}
	return c;
}

void AddNewElement(node** pnHead, int nCountOfElements){
	int nNewElementPosition = 0;
	char cAuthor[20];

	printf("Enter author name: ");
	gets(cAuthor);
	strcpy(slNewElement.pcAuthor,cAuthor);
	gets(slNewElement.pcAuthor);
	printf("Enter book name: ");
	gets(slNewElement.pcBookName);
	printf("Enter year: ");
	scanf("%d", &slNewElement.nYear);
	printf("Enter number of pages: ");
	scanf("%d", &slNewElement.nPages);
	printf("Enter value of the book: ");
	scanf("%d", &slNewElement.nValue);

	node* pnWorkingElement = (node*)malloc(sizeof(node));
	strcpy((pnWorkingElement->data).pcAuthor, slNewElement.pcAuthor);
	strcpy((pnWorkingElement->data).pcBookName, slNewElement.pcBookName);
	(pnWorkingElement->data).nPages = slNewElement.nPages;
	(pnWorkingElement->data).nValue = slNewElement.nValue;
	(pnWorkingElement->data).nYear = slNewElement.nYear;

	if (slNewElement.nPages < (((*pnHead)->data).nPages)) {
		pnWorkingElement->pNext = *pnHead;
		*pnHead = pnWorkingElement;
		return;
	}

	node* temp = *pnHead;
	while (temp->pNext != NULL) {
		temp = temp->pNext;
	}

	if (slNewElement.nPages > (temp->data).nPages) {
		temp->pNext = pnWorkingElement;
		pnWorkingElement->pNext = NULL;
		return;
	}

	temp = *pnHead;
	for (int i = 0; i < nCountOfElements; i++) {
		temp = temp->pNext;
		if (slNewElement.nPages < (temp->data).nPages) {
			nNewElementPosition = i + 2;
			break;
		}
	}

	temp = *pnHead;
	for (int i = 1; i < (nCountOfElements + 1); i++) {
		temp = temp->pNext;
		if ((i + 1) == (nNewElementPosition)) {
			pnWorkingElement->pNext = temp;
			break;
		}
	}

	temp = *pnHead;
	for (int i = 1; i < (nCountOfElements + 1); i++) {
		if ((i) == (nNewElementPosition - 1)) {
			temp->pNext = pnWorkingElement;
			break;
		}
		temp = temp->pNext;
	}
	return;
}

void PrintAllElements(node* pnHead, int nCountOfElements) {
	printf("\n");
	printf("%9s%9s%9s%9s%9s\n","author","book","year","pages","value");
	printf("_____________________________________________\n");

	for (int i = 0; i < nCountOfElements; i++) {
		printf("%9s", (pnHead->data).pcAuthor);
		printf("%9s", (pnHead->data).pcBookName);
		printf("%9d", (pnHead->data).nYear);
		printf("%9d", (pnHead->data).nPages);
		printf("%9d", (pnHead->data).nValue);
		printf("\n");
		pnHead = pnHead->pNext;
	}
	printf("\n");
}

//Function gets index of element to delete from the node, as second parameter
void DeleteTheElement(node** pnHead, int nIndextoDelete, int nCountOfElements) {
	node* temp = *pnHead;
	node* temp1 = NULL;
	node* temp2 = NULL;
	
	if (nIndextoDelete == 0) {
		*pnHead = (*pnHead)->pNext;
		free(temp);
	}

	else if (nIndextoDelete == (nCountOfElements - 1)) {
		int i = 0;
		while (i < nIndextoDelete - 1) {
			temp = temp->pNext;
			i++;
		}
		temp1 = temp;
		temp->pNext = NULL;
		free(temp1->pNext);
	}else {
		for (int j = 0; j < nCountOfElements; j++) {
			if (j == nIndextoDelete - 1) {
				temp1 = temp;
			}
			else if (j == nIndextoDelete + 1) {
				temp2 = temp;
			}
			if ((temp1 != NULL) && (temp2 != NULL)) {
				temp1->pNext = temp2;
				return;
			}
			temp = temp->pNext;
		}
		temp->pNext = NULL;
	}
}

//This function uses another function "DeleteTheElement" to delete elements 
//that does not satisfy the condition from technical task
void DeleteByCondition(node** pnHead, int nCountOfElements) {
	node* pnCurrentUnit = *pnHead;
	int nCurrentIndex = 0;

	while (1) {
		if (((pnCurrentUnit->data).nPages < 90) && ((pnCurrentUnit->data).nYear < 1980)) {
			DeleteTheElement(pnHead, nCurrentIndex, nCountOfElements);
			if (nCurrentIndex) {
				free(pnCurrentUnit);
			}
			pnCurrentUnit = *pnHead;
			nCurrentIndex = 0;
			nCountOfElements--;
			continue;
		}

		nCurrentIndex++;
		pnCurrentUnit = pnCurrentUnit->pNext;

		if (NULL == pnCurrentUnit) {
			return;
		}
	}
}

void DumpDataToFile(node* pnHead, int nCountOfElements) {
	FILE* fMainFile = fopen("text.txt", "w");

	if (fMainFile == NULL) {
		printf("Cant open a file in write_in_file function.");
		return;
	}

	node* temp = pnHead;
	for (int i = 0; i < nCountOfElements; i++) {
		fprintf(fMainFile, "%s %s %d %d %d \n", pnHead->data.pcAuthor,
												pnHead->data.pcBookName,
												pnHead->data.nYear,
												pnHead->data.nPages,
												pnHead->data.nValue);

		pnHead = pnHead->pNext;
	}

	fclose(fMainFile);
}

//Function prints elements with number of pages higher than medium
void PrintBiggerThanMedium(node* pnHead, int nCountOfElements) {
	int nMedium = 0;
	node* pnCurrentElement = pnHead;
	for (int i = 0; i < nCountOfElements; i++) {
		nMedium += pnCurrentElement->data.nPages;
		pnCurrentElement = pnCurrentElement->pNext;
	}

	nMedium = nMedium / nCountOfElements;
	pnCurrentElement = pnHead;

	printf("%9s%9s%9s%9s%9s\n", "author", "book", "year", "pages", "value");
	printf("_____________________________________________\n");

	for (int i = 0; i < nCountOfElements; i++) {
		if (pnCurrentElement->data.nPages > nMedium) {
			printf("%9s%9s%9d%9d%9d \n",pnCurrentElement->data.pcAuthor,
										pnCurrentElement->data.pcBookName,
										pnCurrentElement->data.nYear,
										pnCurrentElement->data.nPages,
										pnCurrentElement->data.nValue);
		}
		pnCurrentElement = pnCurrentElement->pNext;
	}
}

//User enters an index
//Function asks new data for element with that index
void EditNode (node* pnHead) {
	int nCurrentIndex = 0;
	int nIndexForChange;

	printf("Enter index of element for editing: ");
	scanf("%d",&nIndexForChange);

	node* pnCurrentElement = pnHead;
	while (nCurrentIndex != nIndexForChange) {
		nCurrentIndex++;
		pnCurrentElement = pnCurrentElement->pNext;
	}
	printf("Enter author name: ");
	scanf("%s",&pnCurrentElement->data.pcAuthor);

	printf("Enter book name: ");
	scanf("%s", &pnCurrentElement->data.pcBookName);

	printf("Enter year: ");
	scanf("%d", &pnCurrentElement->data.nYear);

	printf("Enter number of pages: ");
	scanf("%d", &pnCurrentElement->data.nPages);

	printf("Enter value: ");
	scanf("%d", &pnCurrentElement->data.nValue);
}

//User enters an index
//Function prints all information about an element with that index
void SearchElement(node* pnHead){
	node *pnWorkingElement = pnHead;
	int nSearchingIndex;

	printf("Enter index of element for searching: ");
	scanf("%d", &nSearchingIndex);

	for (int i = 0; i < nSearchingIndex; i++) {
		pnWorkingElement = pnWorkingElement->pNext;
	}
	
	printf("%s %s %d %d %d \n", pnWorkingElement->data.pcAuthor,
								pnWorkingElement->data.pcBookName,
								pnWorkingElement->data.nYear,
								pnWorkingElement->data.nPages,
								pnWorkingElement->data.nValue);
}
node* GetDataFromFile() {
	FILE* fMainFile;
	fMainFile = fopen("result1.bin", "rb");

	node* pnHead = NULL;
	node* pnWorkingUnit = (node*)malloc(sizeof(node));
	node* pnTemp = NULL;

	while (1)
	{
		if (pnHead == NULL) {
			pnHead = pnWorkingUnit;
			fread(&pnWorkingUnit->data, sizeof(struct Slibrary), 1, fMainFile);
		}
		else {
			node* pnWorkingUnitTemp = (node*)malloc(sizeof(node));
			pnWorkingUnit->pNext = pnWorkingUnitTemp;
			pnTemp = pnWorkingUnit;
			pnWorkingUnit = pnWorkingUnitTemp;
			pnWorkingUnit->pNext = NULL;

			fread(&pnWorkingUnit->data, sizeof(struct Slibrary), 1, fMainFile);
		}
		//nCountOfElements++;
		if (feof(fMainFile)) {
			free(pnWorkingUnit);
			pnWorkingUnit = pnTemp;
			//nCountOfElements--;
			break;
		}
	}
	pnWorkingUnit->pNext = NULL;

	fclose(fMainFile);
	return pnHead;
}

void FreeMemory(node* pnHead, int nCountOfElements) {
	node* pnWorkingUnit = pnHead;
	node* pnTemp;
	for (int i = 0; i < nCountOfElements; i++) {
		pnTemp = pnWorkingUnit->pNext;
		free(pnWorkingUnit);
		pnWorkingUnit = pnTemp;
	}
}