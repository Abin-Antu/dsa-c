#include<stdio.h>
struct Term
{
int coefficient;
int exponent;
};
void inputpolynomial(struct Term poly[],int n)
{

for(int i=0;i<n;i++)
{
printf("Enter the coefficients and exponent for term %d:\n",i+1);
scanf("%d%d",&poly[i].coefficient,&poly[i].exponent);
}
}
int addpolynomials(struct Term poly1[],int n1,struct Term poly2[],int n2,struct Term result[])
{
int i=0,j=0,k=0;
while(i<n1&&j<n2)
{
if(poly1[i].exponent>poly2[j].exponent)
{
result[k++]=poly1[i++];
}
else if(poly1[i].exponent<poly2[j].exponent)
{
result[k++]=poly2[j++];
}
else
{
result[k].coefficient=poly1[i].coefficient+poly2[j].coefficient;
result[k].exponent=poly1[i].exponent;
i++,j++,k++;
}
}
while(i<n1)
result[k++]=poly1[i++];
while(j<n2)
result[k++]=poly2[j++];
return k;
}
void displayPolynomial(struct Term result[],int n)
{
for(int i=0;i<n;i++)
{
printf("%dx^%d",result[i].coefficient,result[i].exponent);
if(i<n-1)
printf("+");
}
printf("\n");
}
void main()
{
struct Term poly1[10],poly2[10],result[20];
int n1,n2,n3;
printf("Enter the no of terms in first polynomial:");
scanf("%d",&n1);
printf("Enter the first poly:\n");
inputpolynomial(poly1,n1);
printf("Enter the no of terms in second polynomial:");
scanf("%d",&n2);
printf("Enter the second poly:\n");
inputpolynomial(poly2,n2);
n3=addpolynomials(poly1,n1,poly2,n2,result);
printf("Resultant polynomial after addiiton:\n");
displayPolynomial(result,n3);
}