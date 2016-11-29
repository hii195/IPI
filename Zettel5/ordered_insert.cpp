#include <iostream>
#include <vector>


//Swap two numbers a and b
void swap(int &a, int &b);

//Insert the number next_number such as the vector data_vector is sorted after the number is inserted
//The vector is a reference. This means, that it is manipulated directly in the function and isn't handles as a copy
void insert(std::vector<int> &data_vector, int next_number);

int main()
{
    //Define the dat
    std::vector<int> vec;

    //use z like
    int num = 0;

    //loop will break after a negative integer is entered
    while (true)
    {
        //input of the new number
        std::cin >> num;

        //break loop if the input is an negative integer
        if (num < 0)
        {
            break;
        }

        //insert the new number in the array
        insert(vec, num);
    }

    //Outout of the vector entries
    for (int n : vec)
    {
        std::cout << n << ' ';
    }
    return 0;
}

void swap(int &a, int &b)
{
    //This is a mathematical stable algorithm to swap two numbers
    //'^' donats the XOR operator
    a = a ^ b; 
    b = a ^ b;
    a = a ^ b;
    return;
}

void insert(std::vector<int> &data_vector, int next_number)
{
    //Insert the new number at the end of the vector
    data_vector.push_back(next_number);

    //This loop goes through all elements of the vector
    for (int i = data_vector.size()-1; i > 0; i--)
    {
        //Compare the entry
        if (data_vector[i] < data_vector[i - 1])
        {
            //Swap the new number with the previous number
            swap(data_vector[i], data_vector[i - 1]);
        }
        else
        {
            //if the previous number is lover, break the loop
            break;
        }
    }
    return;
}