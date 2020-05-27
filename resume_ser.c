/*
ADITHYA B SHETTY
Q SECTION
ROLL NO.18
PES1UG19EC009*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *key_word,char *search_term_1,char *search_term_2)
{
	int flag;    //to check if condition like OR/AND is present or not
	char *count=strstr(key_word,"or");
	//count gives pointer to first occurence of sub-string in given string
	 
	if(count)  //if sub-string is present enters if block
	{
		flag=1;  //1 for OR condtion

		while(key_word<(count-1))  //pointer goes from beginning till the occurence of substring
		{
			*search_term_1=*key_word;  //copying string
			
			search_term_1++;key_word++;  //incrementing address so that pointer refers to next character
		}
		*search_term_1='\0';
		
		key_word+=4;
		//incrementing address in order to start copying next sub-string after the condion OR and white spaces( _OR_)
		
		while(*key_word !='\0')
		{
			*search_term_2=*key_word;
			search_term_2++;key_word++;
		}
		*search_term_2='\0';  //null character appended as string ends with '\0'	
	}
	
	count=strstr(key_word,"and");  //gives NULL if no sub-string found, in that case it does not enter the next if block 
	if(count)
	{
		flag=2;  //2 for AND condtion
		while(key_word<(count-1))
		{
			*search_term_1=*key_word;
			search_term_1++;key_word++;
		}
		*search_term_1='\0';  //null character appended as string ends with '\0'
		
		key_word+=5;
		//incrementing address in order to start copying next sub-string after the condion AND and white spaces( _AND_)
		
		while(*key_word !='\0')
		{
			*search_term_2=*key_word;
			search_term_2++;key_word++;
		}
		*search_term_2='\0';		
	}
	
	if(flag!=2 && flag!=1)
	{
		flag=0;	 //0 for NOT condtion(No OR?AND condtion)
	}	
	
	return flag;  //returns number 1,2,0 to tell which condition has been satisfied
	
}


void lower_string(char lwr_case[]) {
   int c= 0;  //c acts as counter for the loop to go through every character in array
   
   while (lwr_case[c] != '\0') {
      if (lwr_case[c] >= 'A' && lwr_case[c] <= 'Z') {
	 //The ASCII value difference between uppercase and lower case letters in alphabet is 32

         lwr_case[c] = lwr_case[c] + 32;   //ASCII value for lower case letter is 97-122
      }
      c++;
   }
}


void search(int argc,int flag,char *key_word,char *search_term_1,char *search_term_2,char *argv[])
{

	FILE *ft; //file address is collected in structure pointer ft
	
	char copy[100]; //to store the copy of each line in .txt file
	
	int present=0; //to check if search term is present in any of the files
	
	for(int i=2;i<argc;i++)
	{

		ft=fopen(argv[i],"r"); //opening the text files by looping through them

		if(ft==NULL)  //if file fails to open it returns a NULL value
		{
			puts("Cannot open the file"); 
			exit(1); //exit point to indicate abnormal termination 
		}
		
		int check1=0,check2=0,check=0; 
		//For checking if the search key-words are present in the file, if present gives 1



		while((fgets(copy,99,ft))!=NULL) /*1st argument is address where string is stored, 
		2nd maximum length of string, 3rd file pointer*/
		{
			lower_string(copy);	
			if(flag==1 || flag==2) // AND/OR condtion have two search terms like JAVA and Python
			{
				if(strstr(copy,search_term_1))
				{    check1=1;}
				
				if(strstr(copy,search_term_2))
				{    check2=1;} //gives 1 if term present
			}
			
			else
			{
				if(strstr(copy,key_word))
				{    check=1;}
			}
		}
		
		if(flag==1)
		{
			if(check1==1 || check2==1) //OR condtion like java or python
			{	
				printf("%s\n",argv[i]); //to print file if it satisfies the searched condition
				
				present=1; //value changed to 1 as search term is present
			} 
		}
		
		else if(flag==2)
		{
			if(check1==1 && check2==1)  //AND condition like JAVA and Python
			{	printf("%s\n", argv[i]);
				present=1;
				
			}
		}
		
		else 
		{
			if(check==1) //when only one search term is there without condtions like OR/AND
			{	printf("%s\n",argv[i]);
				
				present=1;
			}
		}

		fclose(ft); //to close file after performing all tasks
	}
	
	if(present==0)
	{
		printf("Sorry! None of the files have the above searched key-words\n");
	}
		

}


