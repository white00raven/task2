#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
void strreplace(char*pszRezult, const char*pcszSubstr, const char *pcszStr2)
{
	char *tempptr = pszRezult;
	if (strlen(pcszSubstr) < strlen(pcszStr2))
	{
		while (*tempptr != '\0')
		{
			tempptr++;
		}
	}
	char *tempptr2=strstr(pszRezult,pcszSubstr);
	while (tempptr2 != nullptr)
	{
		int i = 0;
		for (; pcszSubstr[i] != '\0'&&pcszStr2[i] != '\0'; i++,tempptr2++)
		{
			
			*tempptr2  = pcszStr2[i];
		}
		if (pcszSubstr[i] == '\0'&&pcszStr2[i] == '\0')
		{
			continue;
		}
		if (pcszSubstr[i] == '\0')
		{
			int j = strlen(pcszStr2) - strlen(pcszSubstr); 
			int l = 0;
			for ( ; (tempptr  - l) != tempptr2; l++)
			{
				*(tempptr + j-l) = *(tempptr-l);
			}
			*(tempptr + j - l) = *(tempptr - l);
			for (; pcszStr2[i] != '\0'; i++,tempptr2++)
			{
				*tempptr2  = pcszStr2[i];
			}
			tempptr += j;
		}
		else
		{
			int j= strlen(pcszSubstr)-strlen(pcszStr2);
			int l = 0;
			for (; *(tempptr2 + l + j) != '\0'; l++)
			{
				
				*(tempptr2 + l) = *(tempptr2 + l + j);
			}
			*(tempptr2 + l) = *(tempptr2 + l + j);
		}
		
		tempptr2 = strstr(tempptr2, pcszSubstr);
	}
		
}
void main()
{
	fstream file("text.txt");
	if (file.is_open()) {
		setlocale(LC_ALL, "Russian");
		int sizestr, sizesubstr, sizestr2;
		char *pszstr, *pszsubstr, *pszstr2;
		string str, substr;
		file >> str;
		sizestr = str.length();
		file >> substr;
		pszsubstr = (char*)calloc(substr.length() + 1, sizeof(char));
		sizesubstr = substr.copy(pszsubstr, substr.length());
		pszsubstr[sizesubstr] = '\0';
		file >> substr;
		pszstr2 = (char*)calloc(substr.length() + 1, sizeof(char));
		sizestr2 = substr.copy(pszstr2, substr.length());
		pszstr2[sizestr2] = '\0';
		if (sizestr2 > sizesubstr&&sizesubstr!=0)
		{
			sizestr +=(sizestr / sizesubstr)*(sizestr2 - sizesubstr);
		}
		pszstr = (char*)calloc(sizestr + 1, sizeof(char));
		sizestr = str.copy(pszstr, str.length());
		pszstr[sizestr] = '\0';
		strreplace(pszstr, pszsubstr, pszstr2);
		cout <<"результат преобразования-"<< pszstr << endl;
		free(pszstr);
	}
	file.close();
	}