#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    std::fstream myfile("input.txt", std::ios_base::in);

    int a;
    
    while(myfile >> a)
    {
        int arr[a];
        int n;

        for(int i = 0; i < a; ++i)
        {   
            myfile >> n;
            arr[i] = n;
        }

        cout << a << endl;

        for(int i = 0; i < a; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}