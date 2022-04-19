#include <stdio.h>
#include <math.h>

/****************************************
num: a 4-digit integer number
 dn:  total number of digits
 return value: if num is an Armstrong number, return 1, otherwise return 0
****************************************/
int checkingArmstrong(int num, int dn)
{
    int a, b, c, d, m=num;
    a = num % 10;
    num = num/10;
    b = num % 10;
    num = num / 10;
    c = num % 10;
    num = num / 10;
    d = num % 10;
    if (pow(a, dn) + pow(b, dn) + pow(c, dn) + pow(d, dn) == m)
    {
        return 1;
    }
    else return 0;
}

int main() {
    int num, result = 0;
    printf("Enter an integer with 4 digits: ");
    scanf("%d", &num);
    if (checkingArmstrong(num, 4) == 1)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);
    return 0;
}
