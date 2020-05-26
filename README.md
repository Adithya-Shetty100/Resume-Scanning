# Resume-Scanning
To sort out resume files having the required key words given by user

My project is a resume scanning software. Given a set of resume files present in current directory, my software sorts out the files having the required key words(eg: JAVA or Python,Project Management etc. ), which are given by the user. The user input was given through command line.So the command line accepts key words to be searched including logical combinations like OR, AND. In the end files satisfying this condition are given as the output.

Command line argument:
./a.out  <search key-words> <text-filename-1> <text-filename-2> <text-filename-3> ...

Eg: $ make -f resume.mk
      $ ./a.out "JAVA Or Python" file1.txt file2.txt file3.txt file4.txt  

    • There are no limitations to the number of files given in command line(but the files should be present in the same directory)
    • The search key-words can be given in any case(upper/lower case) as the lower_string() convets both search terms and file contents into lower case(so it ignores case-sensitivity)
    • If there is only one search term word like java, HTML then double-qoutes are not required. But if search terms as  more than two terms or has some condition like OR/AND the enclose in double qoutes so that code will take it as condition and not confuse it with some other file type.

Eg: When one word: $ ./a.out JAVA file1.txt file2.txt file3.txt file4.txt

      When multiple words: $ ./a.out "JAVA Or Python" file1.txt file2.txt file3.txt file4.txt  



Functions

    • int main(int argc, char *argv[]): To accept input from command line and call the  required functions.


    • int check(char *key_word,char *search_term_1,char *search_term_2): This function is for checking if it is OR/And condition and to extract the search terms by removing the condition like OR, AND etc.
      
    • void lower_string(char lwr_case[]): to convert the key words and file contents to lower string, so that the contents can be verified without worrying about case
      
    • void search(int argc,int flag,char *key_word,char *search_term_1,char *search_term_2,char *argv[]): This if for searching if the key words are present in the given files, and print the files containg the key words


FILES

    • resume_cl.c :Client side C program file
    • resume_ser.c :Server side C program file
    • resume.h : Header file
    • resume.mk : Make file


