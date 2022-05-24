#include <iostream>  
#include <string>

using std::string;
using std::cout;
using std::cin;

#define TEST_SIZE 2

static const string test[TEST_SIZE][3] = {  
    {"ambigue","abduce","aberrated"},  
    {"An ambiguous statement or expression.","To draw or take away.","Characterized by defects, abnormality, or deviation from the usual, typical, or expected course."} 
};

ssize_t calc(string a) {
    for (ssize_t i = 0; i <= TEST_SIZE; i++)
    {
        if (a == test[0][i])
        {
            return i;
        }
    }
    
    return -1;
}

int main()  
{  
    string inp = "";

    cout << "Enter word:\n";
    cin >> inp;
    
    const ssize_t calculated = calc(inp);
    
    if (calculated < 0)
    {
        cout << "Not found\n";
    }
    else
    {
        cout << test[1][calculated] << '\n';
    }
    return 0;
}
