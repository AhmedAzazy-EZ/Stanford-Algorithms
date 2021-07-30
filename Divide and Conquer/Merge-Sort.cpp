#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <array>
#include <fstream>
#include <limits>

using namespace std;

int * Merge_Sort(int * arr , int length);
void copyArray(int * dest ,int * source ,int start , int length );
static int * Static_Merge_Sort(int * arr , int length);
static int * Dynamic_Arrays[100];
static int counter = 0;

int main()
{
    int arr[] = {10, 3, 2, 7, 2, 11, 9};
    int * result = Merge_Sort(arr , 7);


    for(int i = 0 ; i < 7 ; i ++)
        cout<<result[i]<<"  ";

    free(result);
    return 0 ;
}

static int * Static_Merge_Sort(int * arr ,int length)
{
    if(length == 1 || length == 0)
        return arr;

    int start1 = 0;
    int end1 = length/2 - 1;
    int start2 = end1 + 1;
    int end2 = length - 1;


    int length1 = (end1 - start1) + 1;
    int length2 = (end2 - start2) + 1 ;

    int * sorted1 ;
    int * sorted2 ;

    int temp1[length1] , temp2[length2];
    int * result = (int *) malloc(sizeof(int ) * length);

    copyArray(temp1 , arr , start1 , length1);
    copyArray(temp2 , arr , start2 , length2);

    sorted1 = Static_Merge_Sort(temp1 , length1);
    sorted2 = Static_Merge_Sort(temp2 , length2);

    int index1 = 0, index2 = 0;

    for(int i = 0 ; i < length ; i++)
    {
        if(sorted1[index1] <= sorted2[index2])
        {
            result[i] = sorted1[index1];
                index1++;

        if(index1 == length1)
        {
            for(int loop = i+1 ; loop < length ; loop++)
            {
             result[loop] = sorted2[index2];
             index2++;
            }

            break;
        }
        }

        else if(sorted2[index2] <= sorted1[index1])
        {

            result[i] = sorted2[index2];
                index2++;

        if(index2 == length2)
        {
            for(int loop = i+1 ; loop < length ; loop++)
            {
             result[loop] = sorted1[index1];
             index1++;
            }

            break;
        }
        }
    }
    Dynamic_Arrays[counter] = result;
    counter++;
    return result;
}


void copyArray(int * dest ,int * source ,int start , int length)
{
    for(int i = 0 ; i  < length ; i++)
    {
        dest[i] = source[start];
        start++;
    }
}

int * Merge_Sort(int * arr , int length)
{
    int * result = Static_Merge_Sort( arr ,length);

    //free all the unwanted dynamically allocated memory space
    //except the one the must been returned
    for(int i = 0 ; i < counter - 1 ; i ++)
    {
        free(Dynamic_Arrays[i]);
        Dynamic_Arrays[i] = NULL;
    }
    return result;
}
