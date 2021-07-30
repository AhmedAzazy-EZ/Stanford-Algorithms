/**************************
                         *
 Not Completed yet       *
                         *
 *************************


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <array>
#include <fstream>
#include <limits>
using namespace std;


uint64_t karatsuba_Multiplication( uint64_t x , uint64_t y);
uint64_t reminder (uint64_t divied ,uint64_t divisor);
uint64_t power (uint64_t num , uint64_t expon);

int main()
{
    cout<<karatsuba_Multiplication(453,361);
    return 0;
}


uint64_t karatsuba_Multiplication(uint64_t x ,uint64_t y)
{
    unsigned long int ad = 0 , bc = 0 ,ac = 0 , bd = 0 ,x_Length = 1 , y_Lenght = 1 , hold_x = x  , hold_y = y;

    for(;;)
    {
        hold_x = hold_x/10;
        hold_y = hold_y/10;

        if(hold_x == 0 && hold_y == 0)
            break;

        if (hold_x != 0)
        {
            x_Length ++;

        }

        if(hold_y != 0)
        {
             y_Lenght++;
        }
    }

    if((x_Length == 2 && y_Lenght == 2 )||
       (x_Length == 1 && y_Lenght == 1 )||
       (x_Length == 1 && y_Lenght == 2 ) ||
       (x_Length == 2 && y_Lenght == 1 ))
    {
        return x * y;
    }

    else
    {
        uint64_t a = x/pow(10, (double)(x_Length/2));
        uint64_t c = y / pow(10 ,(double) (y_Lenght/2));
        hold_y = power(10 , y_Lenght / 2);
        uint64_t d =  reminder(y , hold_y);
        hold_x = power(10 , y_Lenght / 2);
        uint64_t b = remainder(x, hold_x);
        ac = karatsuba_Multiplication(a , c);
        bd = karatsuba_Multiplication(b , d);
        ad = karatsuba_Multiplication(a , d);
        bc = karatsuba_Multiplication(b , c);
        hold_x = b;
    }

    return (power(10 , x_Length) * ac) + (power(10 , x_Length / 2) * (ad + bc)) + bd;

}


uint64_t reminder (uint64_t divied ,uint64_t divisor)
{

    return divied % divisor;
}

uint64_t power (uint64_t num , uint64_t expon)
{
    uint64_t result = 1;
    for(uint64_t i = 0 ; i < expon ; i++)
    {
        result*=num;
    }

    return result;
}
