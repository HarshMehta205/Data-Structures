/*
To write a C program to create student database using array of structures . Apply searching(Linear and Binary Search) and sorting techniques(Bubble sort,Insertion sort and selection sort).

*/


#include<stdio.h>
#include<stdlib.h>

struct student                       //define a structure for student database 
    {             
  	char name[20];
  	int rollno;
  	char city[20];
  	int marks;
    };
typedef struct student stud;         //changing the name of structure "struct student" to "stud"

stud accept(stud s[50],int n);

void display( stud s[50],int n);

void linearsearch(stud s[50],int n);

void binarysearch(stud s[50],int n,int low,int high);

void bubblesort(stud s[50],int n);

void selectionsort(stud s[50] ,int n);

void insertionsort(stud s[50] ,int n);

int main(void) 
  {
	int i,n;
	int choice;
	stud s[50];

	printf("enter the total number of students\n");
	scanf("%d",&n);

	printf("enter the database of students\n"); 

	do                          //creating a menu driven program
    	{
      	printf("Menu\n0.Exit\n1.Accept\n2.Display\n3.Linear Search\n4.Binary Search\n5.Bubble Sort\n6.Selection Sort\n7.Insertion Sort\n");
      	scanf("%d",&choice);
      	switch(choice)
        	{
          	case 0:
            		printf("Thank you\n");
        		return 0;
          		break;

          	case 1:
            		accept(s,n);
            		break;

          	case 2:
            		display(s,n);
          		break;

          	case 3:
            		printf("linear search \n");
			linearsearch(s,n);
          		break;

            	case 4:
            		printf("binary search \n");
			int low=0;                          //declaring the first term as low and the last term as high
			int high=n-1;
			binarysearch(s,n,low,high);
          		break;

           	case 5:
                        bubblesort(s,n);             
            		break;

            	case 6:
                        selectionsort(s,n);
            		break;

            	case 7:
                	insertionsort(s,n);
            		break;

            	default:
          		printf("Error.Please retry");

        	}
	    }while(choice!=0);
       
	return 0;
}

stud accept(stud s[50],int n)                  //accepting the datas of the 
  {
   	int i;
   	for(i=0;i<n;i++)
	{
		printf("enter the name of student :");
		scanf("%s",s[i].name);
		printf("enter the roll number :");
		scanf("%d",&s[i].rollno);
		printf("enetr the city :");
		scanf("%s",s[i].city);
		printf("enter the marks of the student :");
		scanf("%d",&s[i].marks);
		printf("\n");
	}
  } 



void display(stud s[50],int n)                       //displaying the elements of the structures
   { 
        int i;
	for(i=0;i<n;i++)
		{
		    printf("Name: %s \t",s[i].name);
		    printf("Roll number: %d \t",s[i].rollno);
		    printf("Marks: %d \t", s[i].marks);
		    printf("City: %s\n",s[i].city);
		}
  }



void linearsearch(stud s[50] ,int n)           //performing linear serch to find out datas
{
     int k,i;
     printf("enter the roll  number you want to find out \n");
     scanf("%d",&k);
     for(i=0;i<n;i++)
       { 
	  if(k==s[i].rollno)                   //if the k rollno element is same as the i rollno then print 
	  {
		  printf("record found at %d \n",i);
		  printf("Name: %s \t",s[i].name);
		  printf("Roll number: %d \t",s[i].rollno);
		  printf("Marks: %d \t", s[i].marks);
		  printf("City: %s\n",s[i].city);
	      break;
      }
	  else if(i==n-1 && s[i].rollno!=k)         //condition for not found
	  {
		  printf("record not found \n");
	      break;
	  }
  }
}


void binarysearch(stud s[50],int n,int low,int high)    //performing binary serch to find out datas
  {
  	selectionsort(s,n);
  	int k,mid;
  	printf("\n enter the roll  number you want to find out \n");
  	scanf("%d",&k);
  	while(low<=high)
  	  {
		  mid =(low+high)/2;                     //calculate mid term of the rollno
		  if(k==s[mid].rollno)                  //if the k rollno element is same as the i rollno then print 
		  {
			  printf("record found ");
			  printf("Name: %s \t",s[mid].name);
			  printf("Roll number: %d \t",s[mid].rollno);
			  printf("Marks: %d \t", s[mid].marks);
			  printf("City: %s\n",s[mid].city);
  	        	  break;
		  }
	
		  if(k<s[mid].rollno)
		     {
			 	  high=mid-1;
		     }
		  if(k>s[mid].rollno)
		     {
		  		  low=mid+1;
		     }
		  else
		     {
			  printf("record not found \n");
		     	  break;
		     }
  	   }
  }  
	


void bubblesort(stud s[50],int n)    //performing bubble sorting of roll numbers
{
	int i,j,o,temp;
  	printf("using bubble sort : \n");
  	printf("before sorting the elements are :");
	for(i=0;i<n;i++)
	  printf("%d \t",s[i].rollno);
	for(i=0;i<n-1;i++)        //conditions for bubble sort
	 {
	   for(j=0;j<n-1-i;j++)
	     {
		if(s[j].rollno > s[j+1].rollno)        //swapping of elements 
	    	 {
	       		temp =s[j].rollno;
	       		s[j].rollno =s[j+1].rollno;
	       		s[j+1].rollno = temp;      
	       		printf("\nafter pass:");
	                for(o=0;o<n;o++)
	                    printf("%d \t",s[o].rollno); 
	                printf("\n");	
	     	 }
	     }
	       
	 }
	printf("\nafter sorting:");
	for(i=0;i<n;i++)
	  printf("%d \t",s[i].rollno);
}	

void selectionsort(stud s[50] ,int n)      //performing selection sorting of roll numbers
  {
	int i,j,o,temp;
        //int smallest;
	printf("using selection sort \n");
	printf("before sorting the elements are :");
	for(i=0;i<n;i++)
	  printf("%d \t",s[i].rollno);
        for(i=0;i<n-1;i++)               // //conditions for selection sort
          {
            for(j=i+1;j<n;j++)
                {
                  if(s[i].rollno>s[j].rollno)
                    {
                      temp=s[i].rollno;
                      s[i].rollno=s[j].rollno;
                      s[j].rollno=temp;
                      printf("\nafter pass:");
	              for(o=0;o<n;o++)
	                    printf("%d \t",s[o].rollno); 
	              printf("\n");	
                    }
                }
          }
        /*for(i=0;i<n-1;i++);
	 {
	   smallest = i;
	   for(j=i+1;j<n;j++);
	   {
	   	if(s[smallest].rollno >s[j].rollno )
	   	smallest=j;  
	   }
	   if(i!= smallest)
	    {
	     	temp =s[i].rollno;
	     	s[i].rollno = s[smallest].rollno;
	     	s[smallest].rollno = temp;
	    }
	 }*/
	printf("\nafter sorting the elements are :");
	for(i=0;i<n;i++)
	  printf("%d \t",s[i].rollno);
       
  }

void insertionsort(stud s[50] ,int n)     //performing insertion sorting of roll numbers
 {	
   int i,temp, j,o; 
   printf("before sorting the elements are :");
   for(i=0;i<n;i++)
     printf("%d \t",s[i].rollno);
   for (i = 1; i < n; i++) 
   { 
       temp = s[i].rollno; 
       j = i-1; 
       while (j >= 0 && s[j].rollno >temp) 
       { 
           s[j+1].rollno = s[j].rollno; 
           j = j-1; 
       } 
       s[j+1].rollno =temp; 
       printf("\nafter pass:");
       for(o=0;o<n;o++)
	                    printf("%d \t",s[o].rollno); 
       printf("\n");	
   }
   printf("\nafter sorting the elements are :");
	for(i=0;i<n;i++)
	  printf("%d \t",s[i].rollno);
 }

