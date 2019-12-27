#include <iostream>

void selection_sort(int selection_array[], int num)
{
    printf("待排序数组顺序为：");
    for(int i = 0; i < num; ++i)
      printf("%d ", selection_array[i]);

    printf("\n");

    for(int sort_num = 0; sort_num < num - 1; ++sort_num)
    {
      int min_value = selection_array[sort_num];
      int min_index = sort_num;

      for(int index = sort_num + 1; index < num; ++index)
      {
        if(min_value > selection_array[index])
        {
          min_value = selection_array[index];
          min_index = index;

        }
      }

      if(sort_num!=min_index)
      {
        int tmp_value = selection_array[sort_num];
        selection_array[sort_num] = selection_array[min_index];
        selection_array[min_index] = tmp_value;
      }

    }

    printf("已排序序数组顺序为：");
    for(int i = 0; i < num; ++i)
      printf("%d ", selection_array[i]);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    int i,n,array[];
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter %d number:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",array[i]);
    }

    selection_sort(array, 10);
    printf("\n");
    return 0;
}
