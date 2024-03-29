#include <iostream>
#include <sstream>

#define ARRAY_SIZE 100

int subTail_idx = 0;
int subTail[ARRAY_SIZE];

int subSoFar_idx = 0;
int subSoFar[ARRAY_SIZE];

int get_max(int num1, int num2)
{
    if(num1 <= num2)
        return num2;
    else
        return num1;
}

void reset(int* array, int* array_idx)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
        array[i] = 0;
        
    *array_idx = 0;
}

void append(int* array, int value, int* array_idx)
{
    array[(*array_idx)++] = value;
}

void assign(int* array1, int* array1_idx, int* array2, int* array2_idx)
{
    for(int i = 0; i < *array2_idx; i++)
    {
        array1[i] = array2[i];
    }
    
    *array1_idx = *array2_idx;
}

void max_sub(int* arg, int size)
{
    int MaxTail = 0; 
    int MaxSoFar = 0;
  
    for(int i = 0; i < size; i++)
    {
        MaxTail = MaxTail + arg[i];
        if(MaxTail < 0)
        {
            reset(subTail, &subTail_idx);
            MaxTail = 0;
        }
        else
        {
            append(subTail, arg[i], &subTail_idx);
        }

        if(MaxSoFar < MaxTail)
        {
            MaxSoFar = MaxTail;
            assign(subSoFar, &subSoFar_idx, subTail, &subTail_idx);
        }
    }    
}

int main()
{
    int lst[] = {31, -41, 59, 26, -53, 58, 97, 12, -93, -23, 84};
    max_sub(lst, 10);
    
    std::stringstream sstream;
    
    int max_val = 0;
    sstream << "seq:{";
    for(int i = 0; i < (subSoFar_idx); i++)
    {
        max_val += subSoFar[i];
        sstream << subSoFar[i] << ", ";
    }
        
    sstream << "}";
    
    std::cout << sstream.str() << ", " <<  max_val << std::endl;
    return 0;
}