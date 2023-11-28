
#include <iostream>
class smartArray
{
private:
    int asize;
    int* array;
    int index = 0;
public:

    smartArray(int size)
    {
        asize = size;
        array = new int[2 * asize];

    };
    ~smartArray()
    {
        delete[] array;

    }

    void elementValue(int value)
    {
        
        
        std::cout << " / Element index" << index << " / " << " 2*asize" << 2 * asize << std::endl;
        if ((index >= 2 * asize)||(index < 0))

        {
           // std::cout << "throw" << std::endl;
            throw std::runtime_error("\n Error. Index is out of range.");
        }
        else {
            std::cout << " / " << index << " / " << std::endl;
            array[index] = value;
        }
            index++;
    }
    int getElement(int position)
    {
        if ((position < 0) || (position >= index))

        {
            
            throw std::exception("\n Error. No valuable element.");
        }
        std::cout << " /  index " << index << " / " << std::endl;
        std::cout << " / position" << position << " / " << std::endl;
        return array[position];
    }
};

int main()
 {
    smartArray a(2);
    for (int i = 0; i < 10; i++)
    {
        try {
            a.elementValue(i);
        }

        catch (const std::exception& e) {
            std::cout << e.what();
        }

    }
    for (int i = 0; i < 10; i++)
    {
        try {
            std::cout << "Array element (index): " << "(" << i << ") " << a.getElement(i) << std::endl;
        }

        catch (const std::exception& e) {
            std::cout << e.what();

        };
    }
    /*try
    {
        a.elementValue(20);
        std::cout << a.getElement(20) << std::endl;
    }
    catch (const std::exception& e) { std::cout << e.what(); };*/

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
