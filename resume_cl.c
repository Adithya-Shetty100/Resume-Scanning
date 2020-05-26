#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resume.h"

int main(int argc, char *argv[])
{
	//argc stores number of arguments
	//char *argv[] is an array of pointers for the arguments entered in command line(string)

	char key_word[50];char search_term_1[50];char search_term_2[50];
	/*search_term_1 and search_term_2 are two key words extracted from key_word after removing the condition like OR/AND
	  If no condition then key_word stores the key words*/
	
	strcpy(key_word, argv[1]);
	//key_word stores a copy of the key words to be searched in the files
	
	lower_string(key_word);
	int flag=check(key_word,search_term_1,search_term_2);
	//flag tells if the key_word has OR/AND/None of the above
	 
	search(argc,flag,key_word,search_term_1,search_term_2,&argv[0]);
	//&argv[0] passes address of first element of array 
	return 0;
}



