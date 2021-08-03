#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <array>
#include <fstream>
#include <limits>

using namespace std;

int * NumofInversions(int * arr , int length , int & result);
static int * Static_NumOfInversions(int * arr , int length , int  & result);
void copyArray(int * dest ,int * source ,int start , int length);


int * Dynamic_Arrays[100];
int counter = 0;
int main()
{
    int inversions = 0;
    int arr[] = {8, 4, 2, 1};
    int * result = NumofInversions(arr , 4 , inversions);


    for(int i = 0 ; i < 4 ; i ++)
        cout<<result[i]<<"  ";


    cout<<"\n"<<inversions;
    free(result);
    return 0 ;
}

static int * Static_NumOfInversions(int * arr , int length , int & result)
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
    int * output = (int *) malloc(sizeof(int ) * length);

    copyArray(temp1 , arr , start1 , length1);
    copyArray(temp2 , arr , start2 , length2);

    sorted1 = Static_NumOfInversions(temp1 , length1 , result);
    sorted2 = Static_NumOfInversions(temp2 , length2 , result);

    int index1 = 0, index2 = 0;

    for(int i = 0 ; i < length ; i++)
    {
        if(sorted1[index1] <= sorted2[index2])
        {
            output[i] = sorted1[index1];
                index1++;

        if(index1 == length1)
        {
            for(int loop = i+1 ; loop < length ; loop++)
            {
             output[loop] = sorted2[index2];
             index2++;
            }

            break;
        }
        }

        else if(sorted2[index2] <= sorted1[index1])
        {

            output[i] = sorted2[index2];
                index2++;

            result += length1 - (index1);

        if(index2 == length2)
        {
            for(int loop = i+1 ; loop < length ; loop++)
            {
             output[loop] = sorted1[index1];
             index1++;
            }

            break;
        }
        }
    }
    Dynamic_Arrays[counter] = output;
    counter++;
    return output;
}


void copyArray(int * dest ,int * source ,int start , int length)
{
    for(int i = 0 ; i  < length ; i++)
    {
        dest[i] = source[start];
        start++;
    }
}


int * NumofInversions(int * arr , int length , int &result)
{
    int * sorted = Static_NumOfInversions( arr ,length , result);

    //free all the unwanted dynamically allocated memory space
    //except the one that must been returned
    for(int i = 0 ; i < counter - 1 ; i ++)
    {
        free(Dynamic_Arrays[i]);
        Dynamic_Arrays[i] = NULL;
    }
    return sorted;
}
