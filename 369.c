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

int count_X_from_array(int arr[], int num_digits, char X)
{
    int count = 0;
    if (X == 'n')
    {
        for (int i = 0; i < num_digits; i++)
        {
            if (arr[i] == 3 || arr[i] == 6 || arr[i] == 9)
            {
                count++;
            }
        }
    }
    else
    {
        for (int i = 0; i < num_digits; i++)
        {
            if (arr[i] ==)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int order = 1;
    int input_n;
    int i;
    int num_digits = count_num_digits(input_n);
    int *sliced_input = slice_num(input_n);
    int *sliced_order = slice_num(order);

    while (1)
    {
        scanf("%d", &input_n);
        num_digits = count_num_digits(input_n);
        sliced_input = slice_num(input_n);
        sliced_order = slice_num(order);

        if (input_n == 0)
            break;

        if (count_X_from_array(sliced_order, num_digits, 'n') != 0) //순서에 3,6,9 존재한다면
        {
            if (count_X_from_array(sliced_order, num_digits, 'n') == count_X_from_array(sliced_order, num_digits, 'X')) //입력값의 X의 개수와 순서의 3,6,9의 개수가 같다면
            {
                printf("PASS\n");
                order++;
            }
            else
                break; //다르면 끝냄
        }
        else if (order == input_n) //순서와 입력값이 같은가
        {
            printf("PASS\n");
            order++; //다음순서
        }
        else
        {
            printf("XXXXXXXXXXXXXXXXXXXXXXXX");
            break;
        }
        free(sliced_input);
        free(sliced_order);
    }
    return 0;
}