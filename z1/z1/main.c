#include<stdio.h>
#include <string.h>
#include "header.h"


int main(void) {
	int nCountOfElements = 0;

	node* pnHead = GetDataFromFile();
	node* pnWorkingUnit = (node*)malloc(sizeof(node));
	node* pnTemp = NULL;

	int nUsersChoise;
	nCountOfElements = CountNumOfElements(pnHead);


	while (1) {
		printf("\n\n1)Print elements\n2)Add new element\n\
3)Edit node\n4)Search element by index\n5)Dump data to File\n6)Print bigger than medium\n7)Delete the element\n8)Delete elements by condition\n9)Exit\n\n");

		printf("Choose what to do: ");

		scanf("%d", &nUsersChoise);


		if (nUsersChoise == 1) {
			PrintAllElements(pnHead, nCountOfElements);
		}
		else if(nUsersChoise == 2){
			AddNewElement(&pnHead, nCountOfElements);
			nCountOfElements = CountNumOfElements(pnHead);
		}
		else if (nUsersChoise == 3) {
			EditNode(pnHead);
		}
		else if (nUsersChoise == 4) {
			SearchElement(pnHead);
		}
		else if (nUsersChoise == 5) {
			DumpDataToFile(pnHead, nCountOfElements);
		}
		else if (nUsersChoise == 6) {
			PrintBiggerThanMedium(pnHead, nCountOfElements);
		}
		else if (nUsersChoise == 7) {
			int choise;
			printf("Enter index of element to delete: ");
			scanf("%d",&choise);
			DeleteTheElement(&pnHead, choise, nCountOfElements);
			nCountOfElements = CountNumOfElements(pnHead);
		}
		else if (nUsersChoise == 8) {
			DeleteByCondition(&pnHead, nCountOfElements);
			nCountOfElements = CountNumOfElements(pnHead);
		}
		else{
			break;
		}
}



	void FreeMemory(pnHead, nCountOfElements);
	pnWorkingUnit = NULL;
	pnTemp = NULL;
	pnHead = NULL;

	return 0;
}