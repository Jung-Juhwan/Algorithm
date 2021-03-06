#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	char myString[1000];
	printf("Input string..\n:");
	scanf_s("%s", myString, 1000);
	int size = 0;
	while (myString[size] != '\0')
	{
		size++;
	}

	Slice answer = *algorithm(myString, size);

	return 0;
}

Slice* algorithm(char myString[], int size)
{
	int slices = (int)size / 2;
	Slice* value = (Slice*)malloc(sizeof(Slice));
	value->value = (char*)malloc(sizeof(char) * 1000);
	value->size = size;
	value->value = myString;
	int bbb = 0;
	int tempi = 0;
	for (int k = 2; k <= slices; k++)
	{
		charArray2D* my = split(myString, size, k);
		char** tempo = my->value;
		int count = 0;
		int tm = 0;

		while (count < my->size)
		{
			int v = 0;
			while (strcmp(tempo[count], tempo[v+count]) == 0)
			{
				if (v+count + 1 < my->size)
					v++;
				else
					break;
			}
			count += v;
		}
	}
	printf("%d",tempi);

	return value;
}

charArray2D* split(char* myString, int size, int splitNumber)
{
	charArray2D* my = (charArray2D*)malloc(sizeof(charArray2D));
	int index = 0;
	int count = 0;
	char** temp = (char**)malloc(sizeof(char*) * ((int)(size / splitNumber) + 1));
	char* temp2 = NULL;
	bool fi = true;

	while (fi)
	{
		temp2 = (char*)malloc(sizeof(char) * (splitNumber + 1));
		bool flag = false;

		for (int i = 0; i < splitNumber; i++)
		{
			temp2[i] = myString[i + count];
			if (myString[i + count] == '\0')
			{
				flag = true;
				break;
			}
		}
		temp2[splitNumber] = '\0';

		temp[index] = &temp2[0];

		if (flag)
		{
			fi = false;
		}

		index++;
		count += splitNumber;
	}

	my->size = index;
	my->value = temp;

	return my;
}