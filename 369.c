#include <stdio.h>
#include <stdlib.h>

int count_num_digits(int num)
{
    int count = 0;
    while (num != 0)
    {
        num = num / 10;
        count++;
    }
    return count;
}

int *slice_num(int num)
{
    int num_digits = count_num_digits(num); //숫자의 자리수
    int *num_array;
    int i;
    num_array = (int *)malloc(num_digits * sizeof(int)); //자리수만큼 배열 생성

    for (i = 0; i < num_digits; i++)
    {
        num_array[num_digits - i - 1] = num % 10; //각자리수 배열에 넣기
        num /= 10;
    }

    return num_array; //배열 반환
}

int count_3_from_array()
{
    return 0;
}

int main()
{
    int order = 1;
    int input_n;
    int i;
    scanf("%d", &input_n);
    int num_digits = count_num_digits(input_n);
    int *f_output = slice_num(input_n);
    printf("%d\n", num_digits);
    for (i = 0; i < num_digits; i++)
    {
        printf("%d", f_output[i]);
    }

    while (1)
    {
        scanf("%d", &input_n);
        if (order == input_n) //순서와 입력값이 같은가
        {
            printf("PASS");
            order++; //다음순서
        }
    }
    free(f_output);

    return 0;
}