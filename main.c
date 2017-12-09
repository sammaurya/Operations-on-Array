#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0
//Function Prototypes
void Bubble_Sort(int [],int *);
void Selection_Sort(int [],int *);
void Insert_Beg(int [],int *);
void Insert_Mid(int [],int *);
void Insert_End(int [],int *);
void Delete_Beg(int [],int *);
void Delete_Mid(int [],int *);
void Delete_End(int [],int *);
int Linear_Search(int [],int *,int);
int Binary_Search(int [],int *);
void Print(int [],int *);
int GetData();
void GetDateTime();

int i,j,choice,temp;
int size,data,pos,element;

int main()
{
    GetDateTime();      //Get System Date & Time
    int arr[100];
    printf("Enter Size of Array (Max 100) : ");
    scanf("%d",&size);
    printf("\nEnter Elements in Array : ");
    for(i=0;i<size;++i)
    {
        scanf("%d",&arr[i]);
    }
    Menu:
    printf("\n\tOperation in Array\n");
    printf("------------------------------------");
    printf("\n1.Sort\n2.Insert\n3.Search\n4.Delete\n5.Print\n6.Clear Screen\n7.Exit\n");
    do
    {
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n  1.Bubble Sort\n  2.Selection Sort\n\n");
                    do
                    {
                        printf("Enter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: Bubble_Sort(arr,&size);
                                    break;
                            case 2: Selection_Sort(arr,&size);
                                    break;
                            default:printf("\nWrong Choice!!!\n");
                        }
                    }while(choice!=1&&choice!=2);
                    break;
            case 2: printf("\n  1.Insert at Begining\n  2.Insert at Middle\n  3.Insert at End\n");
                    do
                    {
                        printf("Enter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: Insert_Beg(arr,&size);
                                    break;
                            case 2: Insert_Mid(arr,&size);
                                    break;
                            case 3: Insert_End(arr,&size);
                                    break;
                            default:printf("\nWrong Choice!!!\n");
                        }
                    }while(choice!=1&&choice!=2&&choice!=3);
                    break;
            case 3: printf("\n 1.Linear Search\n 2.Binary Search");
                    int element=NULL;
                    do
                    {
                        printf("\nEnter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: Linear_Search(arr,&size,element);
                                    break;
                            case 2: Binary_Search(arr,&size);
                                    break;
                            default:printf("\nWrong Choice!!!");
                        }
                    }while(choice!=1&&choice!=2);
                    break;
            case 4: printf("\n 1.Delete Begining\n 2.Delete Middle\n 3.Delete End ");
                    do
                    {
                        printf("\nEnter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: Delete_Beg(arr,&size);
                                    break;
                            case 2: Delete_Mid(arr,&size);
                                    break;
                            case 3: Delete_End(arr,&size);
                                    break;
                            default: printf("\nWrong Choice!!!");
                        }
                    }while(choice!=1&&choice!=2&&choice!=3);
                    break;
            case 5: Print(arr,&size);
                    break;
            case 6: system("cls");
                    goto Menu;
                    break;
            case 7: printf("\nExiting...");
                    break;
            default:printf("\nWrong Choice!!!\n");

        }
    }while(choice!=7);
    getch();
    return 0;
}
void Bubble_Sort(int arr[],int *size)
{
    for(i=0;i<(*size)-1;++i)
    {
        for(j=0;j<(*size)-i-1;++j)
        {
            if(arr[j] > arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nArray is Sorted\n");
}
void Selection_Sort(int arr[],int *size)
{
    int smallest;
    for(i=0;i<(*size)-1;++i)
    {
        smallest=arr[i];
        pos=i;
        for(j=i+1;j<(*size);++j)
        {
            if(arr[j]<smallest)
            {
                smallest=arr[j];
                pos=j;
            }
        }
        arr[pos]=arr[i];
        arr[i]=smallest;
    }
    printf("\nArray is Sorted\n");
}
void Insert_Beg(int arr[],int *size)
{
    printf("Enter Data You Want to Insert : ");
    data=GetData();
    for(i=(*size);i>0;--i)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=data;
    *size=*size+1;
}
void Insert_Mid(int arr[],int *size)
{
    printf("\nEnter the Element After Which You Want to Insert : ");
    element=GetData();
    int max=*size;
    int flag=Linear_Search(arr,&max,element);
    if(flag==true)
    {
        printf("\nEnter the Position after which you want to Insert : ");
        pos=GetData();
        for(i=(*size)+1;i>pos-1;--i)
        {
            arr[i]=arr[i-1];
        }
        printf("\nEnter Data You Want to Insert : ");
        data=GetData();
        arr[i+1]=data;
        *size=*size+1;
    }
}
void Insert_End(int arr[],int *size)
{
    printf("\nEnter Data You Want to Insert : ");
    data=GetData();
    i=*size;
    arr[i]=data;
    *size=*size+1;
}
int Linear_Search(int arr[],int *size,int element)
{
    int pos[*size],flag=false;
    if(element==NULL)
    {
        printf("Enter the Element You Want to Search : ");
        element=GetData();
    }
    j=-1;
    for(i=0;i<(*size);++i)
    {
        if(arr[i]==element)
        {
            pos[++j]=i+1;
            flag=true;
        }
    }
    if(flag==false)
    {
        printf("\nElement %d is not Found",element);
    }
    else
    {
        printf("\nElement found at Position : ");
        for(i=0;i<j+1;++i)
            printf("%d ",pos[i]);
    }
    printf("\n");
    return flag;
}
int Binary_Search(int arr[],int *size)
{
    int lb=0,ub=*size-1,mid;
    int max=*size,pos[max],flag=false;
    printf("For Binary Search Array Must Be Sorted.");
    printf("\nPress 1 to Sort and 0 to Exit : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        Bubble_Sort(arr,&max);
        printf("Enter Element You Want to Search : ");
        scanf("%d",&element);
        j=-1;
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            if(arr[mid]==element)
            {
                pos[++j]=mid+1;
                flag=true;
            }
            if(arr[mid]>element)
            {
                ub=mid-1;
            }
            else
            {
                lb=mid+1;
            }
        }
        if(flag==false)
        {
            printf("\nElement %d is not Found",element);
        }
        else
        {
            printf("Element found at Position : ");
            for(i=0;i<j+1;++i)
                printf("%d ",pos[i]);
        }
        printf("\n");
    }
    else
        printf("\nExiting...");

    return flag;
}
void Delete_Beg(int arr[],int *size)
{
    printf("\nData Deleted : %d\n",arr[0]);
    for(i=0;i<(*size)-1;++i)
        arr[i]=arr[i+1];
    *size=*size-1;
}
void Delete_Mid(int arr[],int *size)
{
    int max=*size;
    printf("\nEnter Data You Want to Delete : ");
    data=GetData();
    Linear_Search(arr,&max,data);
    printf("Enter Position of Data You Want to Delete : ");
    scanf("%d",&pos);
    printf("\nData Deleted : %d\n",arr[pos-1]);
    for(i=pos-1;i<(*size);++i)
    {
        arr[i]=arr[i+1];
    }
    *size=*size-1;
}
void Delete_End(int arr[],int *size)
{
    i=*size-1;
    printf("\nData Deleted : %d\n",arr[i]);
    arr[i]==NULL;
    *size=*size-1;
}
void Print(int arr[],int *size)
{
    printf("\nElements in Array : ");
    for(i=0;i<(*size);++i)
        printf("%d ",arr[i]);
    printf("\n");
}
int GetData()
{
    scanf("%d",&data);
    return data;
}
void GetDateTime()
{
    time_t t;
    time(&t);
    printf("System Date & Time : %s\n",ctime(&t));
}
