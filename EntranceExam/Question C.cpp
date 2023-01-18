#include <iostream>
#include <vector>

int getMaxSum(std::vector<int> mem)
{
    int max = 0;
    int size = mem.size();
    std::vector<int> sum(size);

    for ( int i = 0; i < size; i++)
    {
        sum[i] = mem[i];
    }

    for (int i = 1; i < size; i++)
    {
        for(int j = 0; j < i; j++)
        {
          if((mem[i] > mem[j]) && (sum[i] < sum[j] + mem[i]))
          {
            sum[i] = sum[j] +mem[i];
          }
        }
    }

    for(int i = 0; i < size; i++)
    {
        if (max < sum[i])
        {
            max = sum[i];
        }
    }

    return max;
}

int main() {
    int n;
    int input;

    std::vector<int> memory;

    std::cin>>n;

    for (int i = 0; i < n; i++)
    {
        std::cin>>input;
        memory.push_back(input);
    }

    std::cout<<getMaxSum(memory);


    return 0;
}