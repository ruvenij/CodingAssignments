#include <bits/stdc++.h>

class MyString
{
    public:
        MyString() 
        {
            std::cout << "Deafult constr" << std::endl;
        };

        MyString(const MyString& copy)
        {
            std::cout << "Copy Constr" << std::endl;
            length = std::strlen(copy.content);
            content = new char(length + 1);
            std::strcpy(content, copy.content);
        };

        MyString(const char* copyContent)
        {
            if (content != nullptr) delete[] content;
            
            std::cout << "Parameterized constr" << std::endl;
            length = std::strlen(copyContent);
            content = new char(length + 1);
            std::strcpy(content, copyContent);
        }

        MyString(MyString&& movedStr)
        {
            if (content != nullptr) delete[] content;

            std::cout << "Move constr" << std::endl;
            length = movedStr.length;
            content = movedStr.content;
            movedStr.content = nullptr;
        }

        ~MyString()
        {
            std::cout << "Destructor " << content << std::endl;
            if (content != nullptr) delete[] content;
            content = nullptr;
            length = 0;
        }

        void print()
        {
            std::cout << content << std::endl;
        }

        MyString& operator= (const MyString& str)
        {
            if (content != nullptr) delete[] content;

            std::cout << "Copy Assignment" << std::endl;
            length = std::strlen(str.content);
            content = new char(length + 1);
            std::strcpy(content, str.content);
            return *this;
        }

        MyString& operator= (const char* str)
        {
            if (content != nullptr) delete[] content;

            std::cout << "Parameterized Assignment" << std::endl;
            length = std::strlen(str);
            content = new char(length + 1);
            std::strcpy(content, str);
            return *this;
        }

        friend std::ostream& operator<< (std::ostream& os, const MyString& str);

    private:
        char* content = nullptr;
        unsigned int length = 0;
};

std::ostream& operator<< (std::ostream& os, const MyString& str)
{
    if (str.content != nullptr ) 
    {
        os << str.content;
    }
    else
    {
        os << " ";
    }
    return os;
}

int main()
{
    MyString str; //Default constructor
    MyString test = "Test"; //Parameterized constructor
    MyString next("Next"); //Parameterized constructor
    str = "str"; //Assignment
    MyString assignedTest;
    assignedTest = test; //Copy assignment
    MyString copyTest(assignedTest); //Copy Constructor
    MyString moved(std::move(str));

    std::cout << str << " -> " << test << " -> " << next << " -> " << assignedTest << " -> " << copyTest << " -> " << moved << std::endl;

    return 0;
}