#include <stdio.h>
#include <string.h>
#define MAIN_STR_LEN 100   
int MyStrAssign(char* StrTobeAssigned, char* StrInput)
{
    int n = strlen(StrInput);
    StrTobeAssigned[0] = n;
    for (int i = 1; i <= n; i++)
    {
        StrTobeAssigned[i] = StrInput[i - 1];
    }
    return 0;
}
int main()
{
    char MainStr[MAIN_STR_LEN],test[2*MAIN_STR_LEN];
    char InputBuf[MAIN_STR_LEN],temp[2*MAIN_STR_LEN];
    scanf("%s", InputBuf);
    strcpy(temp, InputBuf);
    strcat(temp, InputBuf);
    MyStrAssign(MainStr, InputBuf);
    MyStrAssign(test, temp);
    int k,num=0,max=0,end,mid;
    for (int i = 2; i <= MainStr[0]; i++)
    {
        k = i;
        for (int j = 1; j < MainStr[0]; j++)
        {
            if (test[k] == MainStr[j]) {
                num++;
                mid = j;
            }
            else
            {
                if (num >= 2) {
                    if (max < num) {
                        max = num;
                        end = mid;
                    }
                }
                num = 0;
            }
            k++;
        }
    }
    for (int i = end-max+1; i <= end; i++)
    {
        printf("%c", MainStr[i]);
    }
    printf("\n");
}
