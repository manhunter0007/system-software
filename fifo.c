#include<stdio.h>
int main()
{
int f,p,i,j,k,fault=0,avail;
printf("Enter the no. of pages in refernce string:");
scanf("%d",&p);
printf("Enter the no. of frames:");
scanf("%d",&f);
int frame[f],pages[p];
printf("Enter the reference string:");
for(i=0;i<p;i++)
{
scanf("%d",&pages[i]);
}
for(i=0;i<f;i++)
{
frame[i]=-1;
}
j=0;
printf("Ref string\tframes\n");
for(i=0;i<p;i++)
{
printf("%d\t\t",pages[i]);
avail=0;
for(k=0;k<f;k++)
{
if(frame[k]==pages[i])
avail=1;
}
if(avail==0)
{
frame[j]=pages[i];
j=(j+1)%f;
fault++;
for(k=0;k<f;k++)
printf("%d",frame[k]);
}
else
{
for(k=0;k<f;k++)
printf("%d",frame[k]);
}
printf("\n");
}
printf("Page fault:%d\nPage hit:%d\n",fault,p-fault);
}
