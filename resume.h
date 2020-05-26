int check(char *key_word,char *search_term_1,char *search_term_2);
//This function is for checking if it is OR/And condition and to extract the search terms by removing the condition like OR, AND etc.

void lower_string(char lwr_case[]);
//to convert the key words and file contents to lower string, so that the contents can be verified without worrying about case
 
void search(int argc,int flag,char *key_word,char *search_term_1,char *search_term_2,char *argv[]);
//This if for searching if the key words are present in the given files, and print the files containg the key words
