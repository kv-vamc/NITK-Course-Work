#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//10000, 100000, 200000, 300000, 400000, 500000, 600000
int main()
{   
    std::vector<int> input_sizes = {100, 1000, 10000, 100000, 200000, 300000, 400000, 500000, 600000, 
                                        700000, 800000, 900000, 1000000};
    int j = 0, n = input_sizes.size();
    
    while(j < n)
    {
        cout << input_sizes[j] << endl;

        for (int i = 0; i < input_sizes[j]; i++)
        {
            long int num = rand() % input_sizes[j] + 1;
            std::cout << num << " ";
        }
        cout << endl;
        j++;
    }
    return 0;
}
