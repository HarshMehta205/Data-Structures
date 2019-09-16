/*
To write a C program for sparse matrix realization and operations on it - Transpose and Fast transpose

*/



#include<stdio.h>
#include<stdlib.h>

void compact(int [100][100],int ,int,int [100][3]);  //function declaration for converting the matrix to compact form
void simpletrans(int [100][3],int ,int [100][3]);  //function declaration for simple transposing the matrix
void fasttrans(int [100][3],int [100][3]);  //function declaration for fast transposing the matrix


int main()
{
	int i,j,m,n;
	int counter;
	int arr[100][100]; //main matrix to be used for storing user input
   	int comp[100][3];  //compact matrix
	int simple[100][3];  //simple transpose matrix of compact matrix
	int fast[100][3];   //fast transpose matrix of compact matrix

	printf("Enter the number of rows \n");
	scanf("%d",&m);
	printf("Enter the number of coloumns \n");
	scanf("%d",&n);


	printf("Array elements are \n");   //scan the elments of the array
	for(i=0;i<m;i++)
	 {
	   for(j=0;j<n;j++)
	    {
	      printf("the %d * %d element of the matrix is :",i,j);
	      scanf("%d",&arr[i][j]);
	      if(arr[i][j] != 0)
	      { 
	        counter++;
	      }
	    }
	 } 

	printf("the elements of array are : \n");   //print the elments of the array
	for(i=0;i<m;i++)
	 {
	   for(j=0;j<n;j++)
	    {
	      printf("%d\t",arr[i][j]);
	    }
	   printf("\n");
	 }

	printf("Number of non zero elements in the matrix are : %d \n\n",counter);


	do
    	{
      	printf("Menu\n0.Exit\n1.compact matrix\n2.Simple transpose\n3.FAst transpose\n");
      	scanf("%d",&choice);
      	switch(choice)
        	{
          	case 0:
            		printf("Thank you\n");  //case 0 is selected
        		return 0;
          		break;

          	case 1:
            		compact(arr,m,n,comp);  //case 1 is selected
          		break;

            	case 2:
        		simpletrans(comp,counter,simple);  //case 2 is selected
          		break;

                case 3:
			fasttrans(comp,fast);  //case 3 is selected
			break;

            	default:
          		printf("Error.Please retry");

        	}
	    }while(choice!=0);
       
	return 0;
	}
	

void compact(int A[100][100],int row ,int col,int B[100][3])  //function definition for converting the matrix to compact form
{
	int i,j;
        B[0][0]=row;
 	B[0][1]=col;
	int k=1;
	for(i=0;i<row;i++)
	 {
	   for(j=0;j<col;j++)
	    {
	      if(A[i][j] != 0)
	         {
	           B[k][0]=i;
	           B[k][1]=j;
	           B[k][2]=A[i][j];
		   k++;
	         }
	    }
	 }
	B[0][2]=k-1;
	printf("the elements of triplet are : \n");
	for(i=0;i<k;i++)
	 {
	   for(j=0;j<3;j++)
	    {
	      printf("%d\t",B[i][j]);
	    }
	   printf("\n");
	 }
}

void simpletrans(int B[100][3],int counter,int C[100][3])  //function definition for simple transposing the matrix
{
        int i,j;
	int m=0,n=0,t=0;
	printf("SIMPLE TRANSPOSE");
	printf("\n");
        m=B[0][0];
 	n=B[0][1];
	t=B[0][2];
  	C[0][0]=n;
	C[0][1]=m;
	C[0][2]=t;
	int k=1;
        for(i=0;i<n;i++)
 	  {
	       for(j=1;j<=t;j++)
		 {
		     if(B[j][1]==i)
			{
				C[k][0]=B[j][1];
	           		C[k][1]=B[j][0];
	          	        C[k][2]=B[j][2];
		   		k++;	
			}
		 }
          }
	printf("the elements of SIMPLE TRANSPOSE MATRIX are : \n");
	for(i=0;i<k;i++)
	 {
	   for(j=0;j<3;j++)
	    {
	      printf("%d\t",C[i][j]);
	    }
	   printf("\n");
	 }

}


void fasttrans(int B[50][3],int D[50][3]) //function definition for fast transposing the matrix
{
     int i,m,n,l,j,pos[50],count[50];
     for(i=0;i<B[0][1];i++)
     {
         pos[i]=0;

     }
     for(i=0;i<50;i++)
     {
             count[i]=0;
     }
     for (i=1;i<=B[0][2];i++)
    {
             m = B[i][1];
             count[m]++;
    }
    pos[0] = 1;
    for (i=1;i<B[0][1];i++)
    {
        pos[i] = pos [i-1] + count[i-1];
    }
    for (i=1;i<=B[0][2];i++)
    {
        m = B[i][1];
        n= pos[m];
        pos[m]++;
        D[n][0] = B[i][1];
        D[n][1] = B[i][0];
        D[n][2] = B[i][2];
    }
    D[0][0] = B[0][1];
    D[0][1] = B[0][0];
    D[0][2] = B[0][2];

    l=B[0][2]+1;

    printf("the elements of FAST TRANSPOSE MATRIX are : \n");
    for(i=0;i<l;i++)
	 {
	   for(j=0;j<3;j++)
	    {
	      printf("%d \t",D[i][j]);
	    }
	   printf("\n");
	 }

}
