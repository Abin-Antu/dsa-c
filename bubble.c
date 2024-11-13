#include<stdio.h>
int main(){
    int a[20];
    int temp;


// size of the array
int size;
scanf("%d",&size);
for(int i =0;i<size;i++)
{
    scanf("%d",&a[i]);
}

for( int i=0;i<size;i++){
    for ( int j = 0; j < size; j++)
    {
        if(a[i]>a[j+1])
        {
            temp = a[i];
            a[i]=a[j+1];
            a[j+1]=temp;
        }
    }
    
}
for (int  i = 0; i<size; i++)
{
    printf("%d ",a[i],"/n");
}

}3