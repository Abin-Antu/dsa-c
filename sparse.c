#include<stdio.h>
struct term
{
int row;
int col;
int value;
};
void inputMatrix(int matrix[10][10],int rows,int cols)
{
printf("Enter the elements of the matrix (%dx%d):\n",rows,cols);
for(int i=0;i<rows;i++)
{
for(int j=0;j<cols;j++)
{
scanf("%d",&matrix[i][j]);
}
}
}
int convertToTupleForm(int matrix[10][10],int rows,int cols,struct term tuple[])
{
int k=1;
tuple[0].row=rows;
tuple[0].col=cols;
tuple[0].value=0;
for(int i=0;i<rows;i++)
{
for(int j=0;j<cols;j++)
{
if(matrix[i][j]!=0)
{
tuple[k].row=i;
tuple[k].col=j;
tuple[k].value=matrix[i][j];
k++;
}
}
}
tuple[0].value=k-1;
return k-1;
}
void transpose(struct term a[],struct term b[])
{
int n=a[0].value;
int currentb=1;
b[0].row=a[0].col;
b[0].col=a[0].row;
b[0].value=n;
if(n>0)
{
for(int i=0;i<a[0].col;i++)
{
for(int j=1;j<=n;j++)
{
if(a[j].col==i)
{
b[currentb].row=a[j].col;
b[currentb].col=a[j].row;
b[currentb].value=a[j].value;
currentb++;
}
}
}
}
}
void addMatrices(struct term a[],struct term b[],struct term result[])
{
int i=1,j=1,k=1;
if(a[0].row!=b[0].row||a[0].col!=b[0].col)
{
printf("Matrices cannot be added as their dimensions do not match.\n");
return;
}
result[0].row=a[0].row;
result[0].col=a[0].col;
while(i<=a[0].value&&j<=b[0].value)
{
if(a[i].row==b[j].row&&a[i].col==b[j].col)
{
result[k].row=a[i].row;
result[k].col=a[i].col;
result[k].value=a[i].value+b[j].value;

i++;
j++;
k++;
}
else if(a[i].row<b[j].row||(a[i].row==b[j].row&&a[i].col==b[j].col))
{
result[k]=a[i];
i++;
k++;
}
else
{
result[k]=b[j];
j++;
k++;
}
}
while(i<=a[0].value)
{
result[k]=a[i];
i++;
k++;
}
result[0].value=k-1;
}
void displayTuple(struct term a[])
{
for(int i=0;i<=a[0].value;i++)
{
printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
}
}
int main()
{
int matrix1[10][10],matrix2[10][10];
int rows1,cols1,rows2,cols2;
struct term tuple1[100],tuple2[100],transpose1[100],transpose2[100],sum[100];
printf("Enter the rows for first matrix:");
scanf("%d",&rows1);
printf("Enter the columns for first matrix:");
scanf("%d",&cols1);
inputMatrix(matrix1,rows1,cols1);
printf("Enter the rows for second matrix:");
scanf("%d",&rows2);
printf("Enter the columns for second matrix:");
scanf("%d",&cols2);
inputMatrix(matrix2,rows2,cols2);
convertToTupleForm(matrix1,rows1,cols1,tuple1);
convertToTupleForm(matrix2,rows2,cols2,tuple2);
printf("\nFirst matrix in tuple form:\n");
displayTuple(tuple1);
printf("\nSecond matrix in tuple form:\n");
displayTuple(tuple2);
transpose(tuple1,transpose1);
transpose(tuple2,transpose2);
printf("\nTranspose of the first matrix in tuple form:\n");
displayTuple(transpose1);
printf("\nTranspose of the second matrix in tuple form:\n");
displayTuple(transpose2);
addMatrices(tuple1,tuple2,sum);
printf("\nSum of two matrices in tuple form:\n");
displayTuple(sum);
return 0;
}