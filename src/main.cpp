#include <iostream>
#include <header.hpp>// header shamel hameye func haye lazem ke baraye rahati va nazm kar joda shodan

using namespace std;

int main()
{   
    help();

    vector<Matrix> mat;//vectori 2bodi az jens sturct matrix
    
    while (1)
    {   
        string command;
        getline(cin, command);//gereftan dastoor az karbar

        for (size_t i = 0; i < command.length(); i++)
        {
            command[i] = tolower(command[i]);// jahat lowercase kardan dastoor vared shode 
        }
    
        string check = command.substr(0, command.find(" ")); // peyda kardan avalin bakhsh dastoor 

        if (check == "add_matrix")
        { 
            add_matrix(command, mat);
        }

        if (check == "is_diagonal")//ghotri
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
        
        if (check == "is_upper_triangular")//bala mosalasi
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

        if (check == "is_lower_triangular")//payeen mosalasi
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
        
        if (check == "is_triangular")//mosalasi
        {
            is_triangular(command, mat);
        }
        
        if (check == "is_identtity")// hamani
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

        if (check == "is_normal_symmetric")// motegharen
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

        if (check == "is_skew_symmetric")//pad motegharen
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
        
        if (check == "is_symmetric")// motegharen ya pad motegharen
        {
            is_symmetric(command, mat);
        }

        if (check == "inverse")// makoos kardan
        {
            inverse(command, mat);
        }

        if (check == "show")//namayesh
        {
            show(command, mat);
        }
        
        if (check == "deletee")// hazf yek matrix ************* az delete nmishod estefade kard pas az deletee estefade shod ***********************
        {
            deletee(command, mat);
        }
        
        if (check == "change")// avaz kardan yek meghdar az matrix 
        {
            change(command, mat);
        }
        
        if (check == "help")// help
        {
            help();
        }
        
        if (check == "exit")// khorooj az barname
        {
            break;
        }
    }
    return 0;
}