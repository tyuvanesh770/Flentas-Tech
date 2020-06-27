#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Test_Cases;
    char *ptr1, *ptr2;
    int *ptr3;
    int counter_flag = 0;
    int n,m;
    int ret;
    
    n=0;
    m=0;
    
    ptr3 = (int*)malloc(Test_Cases * sizeof(int));
    
    scanf("%d",&Test_Cases);
    
    for (int i=0;i<Test_Cases;i++)
    {
        ptr1 = (char*)malloc(1000 * sizeof(char)); 
        ptr2 = (char*)malloc(100000 * sizeof(char)); 
    
        if (ptr1 == NULL || ptr2 == NULL) { 
            printf("Memory not allocated.\n"); 
            exit(0); 
        }
        else { 
            
            scanf("%s",ptr1);
            //printf("%s\n",ptr1);
            scanf("%s",ptr2);
            //printf("%s\n",ptr2);
            
            n = strlen(ptr1);
            m = strlen(ptr2);
            
            //printf("%d,%d",n,m);
            
            /*for(int a=0; (ptr1+a)!='\0';a++)
            {
               if(a<n)
               {
                    scanf("%c",ptr1+a);
               }
               else
                   break;
            }
            
            for(int a=0; (ptr2+a)!='\0';a++)
            {
               if(a<n)
               {
                    scanf("%c",ptr2+a);
               }
               else
                   break;
            }*/
        
            for (int j=0;j<n;)
            {
                for(int k=0;k<m;k++)
                {
                    if ((*(ptr2+k))==(*(ptr1+j)))
                    {
                        counter_flag++;
                        //printf("%d",counter_flag);
                        j++;
                        break;
                    }
                    else
                        continue;
                }
                if(counter_flag == 0)
                   break;
            }
        }
        
        if (counter_flag == n)
            *(ptr3+i) = 1;
        else
            *(ptr3+i) = 0;
        
        free(ptr1);
        free(ptr2);
        counter_flag = 0;
    }    
    
    for(int i=0;i<Test_Cases;i++){
        if(*(ptr3+i)==1)
           printf("\nYes");
        else
           printf("\nNo");
    }