#include <iostream>
#include <vector>
#include <string>

template <typename T>
T square(T a)
{
    return a * a;
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (const T& element : arr){
        std::cout << element << std::endl;
    }
}

int main()
{   
    std::cout << "Square of 2 is " << square(2) << std::endl; 
    std::cout << "Square of 2.1 is " << square(2.1f) << std::endl; 
    std::cout << "Square of 12345 is " << square(12345.0) << std::endl; 

    std::vector<int> arrInt = {1, 2, 3, 4, 5};
    std::vector<float> arrFloat = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<std::string> arrString = {"one", "two", "three", "four", "five"};

    printArray(arrInt);
    printArray(arrFloat);
    printArray(arrString);

    return 0;
}