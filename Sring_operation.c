/*
To write a C progam for string operations - lenght, copy , concatenation , palindrome ,check substring ,equal ,reverse
*/



#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//declaring various functions
void accept(char *);				//declaration for accepting a string
void display(char *);    			//declaration for displaying a string               
int  length(char *);				//declaration for calculating lenght of a string
void copy(char *,char *);			//declaration for copying of a string
void concet(char *,char *);			//declaration for concentation of a string
void reverse(char *,char *);			//declaration for reversing a string
void palin(char *,char *);			//declaration for palindrome in string
void occurence(char [],char []);		//declaration for occurence in string
int  comparestring(char *, char *);		//declaration for comparing of strings

int main()
{
        char string1[20],string2[20],string3[20]="",string4[20]="",string5[20]="";
        int x=0,z=0,result;
        accept(string1);
        display(string1);
        printf("\n");
        accept(string2);
        display(string2);
        int choice;
        
        //writing a menu driven program
                  do {
			      printf("\n");
                              printf("\nEnter the choice of operationyou want to perform -");
                              printf("\n1.Length  2.Copy  3.Concat 4.reverse 5.compare 6.palindrome 7.occurence 0.Exit\n");
                              scanf("%d",&choice);

                    switch(choice)          //writing various switch cases 

                    {
                        case 1 :             //case for calculating lenght of a string

                                x=length(string1);
                                printf("length of string 1 is : %d \n",x);
                                z=length(string2);
                                printf("length of string 2 is : %d \n",z);
                            break;

                        case 2 :             //case for copying of a string

                                copy(string1,string2);
                                printf("string 1 after copy is:");
                                puts(string1);
                                printf("string 2 after copy is:");
                                puts(string2);
				printf("\n");
                                break;

                        case 3 :                 ///case for concentation of a string

                                concet(string1,string2); 
                                printf("string 1 after concet is:");
                                puts(string1);
                                printf("string 2 after concet is:");
                                puts(string2);
				printf("\n");
                                break;

                        case 4 :		//case for reversing a string

                                reverse(string3,string1);
                                printf("string 1 after reverse is:");
                                puts(string1);
                                printf("string 3 after reverse is:");
                                puts(string3);
				printf("\n");
                                break;

                        case 5 :                 //case for comparing of strings

                                comparestring(string1,string3);
                                if (result == 0)
                                printf("The strings are same.\n");
                                else
                                printf("The strings are different.\n");
                                break;

 
                        case 6 :                 //case for palindrome in string

                                palin(string4,string1);
                                break;

                        case 7 :		//case for occurence in string

                                printf("\nenter the substring you wanna find out : ");
                                scanf("%s",string5);
                                printf("\nso you want to find out string:");
                                printf("%s",string5);
                                occurence(string1,string5);
                                break;

                    }
                 }while(choice!=0);
        printf("Program terminated !");
        return 0;
}

void accept(char *a)                  //writing the contents of accept function
  {
            printf("enter the elements of strings : \n");
            scanf("%s",a);
  }

void display(char *a)                 //writing the contents of display function
 {
            printf("the string is : \n");
            puts(a);
 }

int length(char* str3)                //writing the contents of lenght function
 {
    int l=0;
    for(;*str3!='\0';)                //condition string 3 works till end of file
      {
        str3++;
        l++;
      }
        return l;
 }

void copy(char *str1,char *str2)         //writing the contents of cpoy function
 {
        while(*str1!='\0')               //condition string 1 works till end of file
          {
                *str2=*str1;
                str1++;
                str2++;
          }
        *str2='\0';
 }


void concet(char *str1,char *str2)        //writing the contents of concetation function
  {
        while(*str1!='\0')                //condition string 1 works till end of file
          {
                str1++;
          }
        while(*str2!='\0')                //condition string 2 works till end of file
          {
                *str1=*str2;
                str1++;
                str2++;
          }
        *str1='\0';
}

void reverse(char *str3,char *str1)       //writing the contents of reverse function
 {
        int l=0;
        l=length(str1);
        l--;
        while(l>=0)
                {
                        *str3=*(str1+l);
                        l--;
                        str3++;
                }
        *str3='\0';
 }

void palin(char *str4,char *str1)        //writing the contents of palindrome function
 {
        int l;
        reverse(str4,str1);
        l=strcmp(str4,str1);            //using comparsion function to see fi the strings are equal
        if(l==0)
        {
             printf("palindrome");      //if the value of comparsion is 0 then it is a palindrome
        }
        else
        {
             printf("not a palindrome");      //if the value of comparsion is 0 then it is a not palindrome
        }
 }

void occurence(char str1[],char str5[]) 		//writing the contents of occurence function 
{ 
        int q,y;
        int i,j;
       
        q=length(str1);
        printf("length of string 1 is : %d \n",q);
        y=length(str5);
        printf("length of string 5 is : %d \n",y);
        int res = 0; 
    
    // A loop to slide str1[] one by one 
    for (int i = 0; i <= q-y; i++) 
    {  
        // For current index i, check for pattern match 
        int j; 
        for (j = 0; j < y; j++) 
            if (str1[i+j] != str5[j]) 
                break; 
   
        // if [0...M-1] = txt[i, i+1, ...i+M-1] 
        if (j == y)   
        { 
           res++; 
           j = 0; 
        } 
    } 
    printf("\nthus the occurence of the string is %d",res);
} 
  



int comparestring(char *str1, char *str3)        //writing the contents of cpmare string function
 {
   while (*str1 == *str3) 
   {
      if (*str1 == '\0' || *str3 == '\0')
         break;
      str1++;
      str3++;
   }
   if (*str1 == '\0' && *str3 == '\0')
      return -1;
   else
      return -0;
 } 
