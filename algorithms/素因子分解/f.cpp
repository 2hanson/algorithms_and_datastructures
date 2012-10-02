#include <iostream>
#include <cmath>
using namespace std;

void pfactor(int input)
{
    for (int d = 2; d <= input; ++d)
    {
        if (input % d == 0)
        {
            cout<<" "<<d<<endl;
            input /= d;
            if (input == 1)
                break;
            --d;
        }
    }
}

int main()
{
    int input;
    cin>>input;
    pfactor(input);
    return 0;
}
