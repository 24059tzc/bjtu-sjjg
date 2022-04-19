/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
#include <stdio.h>
#include <string.h>
#define MAIN_STR_LEN 100   /* 主串的长度 */
#define SUB_STR_LEN 20     /* 子串的长度 */
int MyStrCompare(char* Str1, char* Str2)
{
    int i;
    int result = 0;
    for (i = 1; (i <= Str1[0]) && (i <= Str2[0]); i++)
    {
        if (Str1[i] > Str2[i])
        {
            result = 1;
            break;
        }
        else if (Str1[i] < Str2[i])
        {
            result = -1;
            break;
        }
        else
        {
            /*两个字符相等，不用处理，继续循环*/
        }
    }
    /*循环结束后判断result是否为0，如果仍为0则说明至少一个字符串已遍历完但未发现差别*/
    if (result == 0)
    {
        /*有一个字符串已遍历完仍没有差别，判断两个字符串的长度（长的大）*/
        if (Str1[0] > Str2[0])
        {
            result = 1;
        }
        else if (Str1[0] < Str2[0])
        {
            result = -1;
        }
        else
        {
            /*长度和内容都一样，返回0（表示一致），也可不处理（保持默认值）*/
            result = 0;
        }
    }
    else
    {
        /*之前已经判断出结果了，不需要再处理*/
    }
    return result;
}
int MySubStrIndex(char* MainStr, char* SubStr, int pos)
{
    int i, j, result;
    /*基本的防护*/
    if ((pos < 0) || (pos > (MainStr[0] - SubStr[0] + 1)))
    {
        result = 0;
    }
    else
    {
        /*主串中剩余的位置足够存放子串，逐位判断*/
        i = pos;
        j = 1;
        while (i <= MainStr[0] && j <= SubStr[0])
        {
            if (MainStr[i] == SubStr[j]) /* 继续比较后继字符 */
            {
                i++;
                j++;
            }
            else /*该字符不同，针后退重新开始匹配 */
            {
                i = i - j + 2;
                j = 1;
            }
        }
        /*循环结束后,如果j大于子串的长度，则说明找到了匹配的子串，否则没找到*/
        if (j > SubStr[0])
        {
            /*找到子串在主串中的位置*/
            result = i - SubStr[0];
        }
        else
        {
            result = 0;
        }
    }
    return result;
}
char MyStrDelete(char* S, int pos, int len)
{
    int i;
    if (pos<1 || pos>S[0] - len + 1 || len < 0)
        return -1;
    for (i = pos + len; i <= S[0]; i++)
        S[i - len] = S[i];
    S[0] -= len;
    return 1;
}
char MyStrInsert(char* S, int pos, char* T)
{
    int i;
    if (pos<1 || pos>S[0] + 1)
        return -1;
    if (S[0] + T[0] <= MAIN_STR_LEN)
    { /* 完全插入 */
        for (i = S[0]; i >= pos; i--)
        {
            S[i + T[0]] = S[i];
        }
        for (i = pos; i < pos + T[0]; i++)
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = S[0] + T[0];
        return 1;
    }
    else
    { /* 部分插入 */
        for (i = MAIN_STR_LEN; i <= pos; i--)
        {
            S[i] = S[i - T[0]];
        }
        for (i = pos; i < pos + T[0]; i++)
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = MAIN_STR_LEN;
        return 0;
    }
}
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
int MyStrReplace(char* MainStr, char* SubStr1, char* SubStr2)
{
    int i, m = 1, j = 0;
    while (1) {
        i = MySubStrIndex(MainStr, SubStr1, m);
        if (i == 0)break;
        MyStrDelete(MainStr, i, SubStr1[0]);
        MyStrInsert(MainStr, i, SubStr2);
        j++;
        m = m + i;
    }
    return j;
}
void chang(char* str)
{
    for (int i = 1; i < str[0]; i++)
    {
        if (str[i]==' ')
        {
            continue;
        }
        str[i] = (str[i] - 'A' - 5 + 26) % 26 + 'A';
    }
}
int main()
{
    char InputBuf[25][MAIN_STR_LEN];
    char SubStr[10][MAIN_STR_LEN];
    char middle[MAIN_STR_LEN];
    char start[] = "START";
    char end[] = "END";
    char endd[] = "ENDOFINPUT";
    int j = 0;
    while (1)
    {
        gets_s(middle, MAIN_STR_LEN);
        if (strcmp(middle,start)==0||strcmp(middle,end)==0)
        {
            continue;
        }
        else if (strcmp(middle,endd)==0)
        {
            break;
        }
        else
        {
            MyStrAssign(InputBuf[j], middle);
            j++;
        }
    }
    for (int i = 0; i < j; i++)
    {
        chang(InputBuf[i]);
    }
    for (int i = 0; i < j; i++)
    {
        for (int k = 1; k <= InputBuf[i][0]; k++)
        {
            printf("%c", InputBuf[i][k]);
        }
        printf("\n");
    }
   
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */