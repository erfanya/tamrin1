#include <iostream>
#include <header.hpp>

using namespace std;

int main()
{   
    help();

    vector<Matrix> mat;
    
    while (1)
    {   
        string command;
        getline(cin, command);

        for (size_t i = 0; i < command.length(); i++)
        {
            command[i] = tolower(command[i]);
        }
    
        string check = command.substr(0, command.find(" "));

        if (check == "add_matrix")
        { 
            add_matrix(command, mat);
        }

        if (check == "is_diagonal")
        {
            if (is_diagonal(command, mat))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        
        if (check == "is_upper_triangular")
        {
            if (is_upper_triangular(command, mat))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            
        }

        if (check == "is_lower_triangular")
        {
            if (is_lower_triangular(command, mat))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        
        if (check == "is_triangular")
        {
            is_triangular(command, mat);
        }
        
        if (check == "is_identtity")
        {
            if(is_identtity(command, mat))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }

        if (check == "is_normal_symmetric")
        {
            if(is_normal_symmetric(command, mat))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }

        if (check == "is_skew_symmetric")
        {
            if(is_skew_symmetric(command, mat))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        
        if (check == "is_symmetric")
        {
            is_symmetric(command, mat);
        }

        if (check == "inverse")
        {
            inverse(command, mat);
        }

        if (check == "show")
        {
            show(command, mat);
        }
        
        if (check == "deletee")
        {
            deletee(command, mat);
        }
        
        if (check == "change")
        {
            change(command, mat);
        }
        
        if (check == "help")
        {
            help();
        }
        
        if (check == "exit")
        {
            break;
        }
    }
    return 0;
}