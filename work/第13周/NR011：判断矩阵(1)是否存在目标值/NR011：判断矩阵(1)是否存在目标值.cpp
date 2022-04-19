#include<stdio.h>
int Search_Bin(int ST[], int key,int length)
{ // 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为
  //该元素在表中的位置，否则为0。
    int low = 0; int high = length-1,mid;  // 置区间初值
    while (low <= high) {
        mid = (low + high) / 2;
        if (key==ST[mid])   return mid;
        if (key == ST[low])return low;
        if (key == ST[high])return high;//找到待查元素
        else if (key<ST[mid])   high = mid-1; //继续在前半区间进行查找
        else  low = mid+1;  // 继续在后半区间进行查找
    }
    return 0; // 顺序表中不存在待查元素
}
int searchMartix(int matrix[50][50],int length,int tibe, int target) {
    int m = length; //获取行数
    int n = tibe;//获取列数
    int i = m - 1, j = 0;
    while (i >= 0 || j <= n - 1) {
        if (target > matrix[i][j]) {
            j++;
            if (j > n - 1) return false;
        }
        else if (target < matrix[i][j]) {
            i--;
            if (i < 0) return false;
        }
        else if (target == matrix[i][j]) {
            return true;
        }
    }
    return false;
}
int main()
{
    char c;
    for (int i = 0; i < 9; i++)
    {
        c=getchar();
    }
    int temp2, num=1;
    int temp[30][30],temp3[10];
    int i=0, j=0,k=0;
    while (c!=']')
    {
        j = 0;
        while (c != ']')
        {
            c = getchar();
            temp2 = 0;
            while (c >= '0' && c <= '9')
            {
                temp3[k++] = c - '0';
                c = getchar();
            }
            for (int m = k-1; m >= 0; m--)
            {
                temp2 = temp2 + num * temp3[m];
                num = num * 10;
            }
            num = 1;
            temp[i][j++] = temp2;
            k = 0;
        }
        c = getchar();
        if (c == ' ')c = getchar();
        i++;
        
    }
    for (int k = 0; k < 8; k++)
    {
        getchar();
    }
    int target;
    int temp4[50][50];
    int e = 0,eee=0;
    scanf("%d", &target);
    for (int ee = 0; ee < j; ee++)
    {
        eee = 0;
        for (int m = 0; m < i; m++)
        {
            temp4[e][eee++] = temp[m][ee];
        }
        e++;
    }
    int order=searchMartix(temp4,e,eee,target);
    if (order == 1)printf("true\n");
    else printf("false\n");
}