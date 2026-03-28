#include <iostream>
using namespace std;
int main()
{
    int *memory = new int[1];
    int *tmp;
    int size = 1, index, value;
    cout << "Enter the array (press -1 when done): ";
    cin >> value;
    for (index = 0; value != -1; index++)
    {
        if (index == size)
        {
            tmp = new int[size *= 2]();
            for (int j = 0; j < index; j++)
            {
                tmp[j] = memory[j];
            }
            delete[] memory;
            memory = tmp;
        }
        memory[index] = value;
        cin>>value;
    }
    if (size > index)
    {
        tmp = new int[index];
        for (int i = 0; i < index; i++)
        {
            tmp[i] = memory[i];
        }
        delete[] memory;
        memory =  tmp;
    }
    cout<<"The array is: ";
    for (int i = 0; i < index ; i++)
    {
        cout<<memory[i]<<" ";
    }
    delete[] memory;
    return 0;
}