#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct matrix Matrix;

struct matrix
{
    string name;//esm matris

    vector<vector<int>> matris;//2nd vector
};



void help();
void add_matrix(string & command, vector<Matrix> & mat);
void is_diagonal(const string & command, vector<Matrix> & mat);
void is_upper_triangular(const string & command, vector<Matrix> & mat);
void is_lower_triangular(string & command, vector<Matrix> & mat);
void is_triangular(string & command, vector<Matrix> & mat);
void is_identtity(string & command, vector<Matrix> & mat);
void is_normal_symmetric(string & command, vector<Matrix> & mat);
void is_skew_symmetric(string & command, vector<Matrix> & mat);
void is_symmetric(string & command, vector<Matrix> & mat);
void inverse(string & command, vector<Matrix> & mat);
void show(const string & command, vector<Matrix> & mat);
void deletee(string & command, vector<Matrix> & mat);
void change(string & command, vector<Matrix> & mat);
int find_matrix_index(const string & name, vector<Matrix> & mat);
string find_name(const string & command);

void add_matrix(string & command, vector<Matrix> & mat)//baraye ezafe kardan matris
{   
    struct matrix temp;

    int pos = command.find(" ");
    string temp_command = command.substr(0, pos);

    int pos2 = command.find(" ", pos + 1);
    string name_mat = command.substr(pos, pos2 - pos);

    temp.name = name_mat;

    int row = command[pos2 + 1] - 48;

    int col = row;
  
    if (command[pos2 + 4] == ' ')
    {
        col = command[pos2 + 3] - 48;
    }

    command = command.substr(pos2 + 5);
  
    int temp_mat[row][col];

    for(int i = 0; command != "" && i < row; i++)
    {
        temp.matris.push_back(vector<int>());
    
        for(int j = 0; command != "" && j < col; j++)
        {
            temp.matris[i].push_back(command[0] - 48);
           
            if(command.size() <= 2)
            {          
                mat.push_back(temp);
                break;
            }
            command = command.substr(command.find(',') + 1);
        }
    }
    
    cout << "Matrix Added" << endl;
}

void is_diagonal(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan ghotri boodan matris 
{   
    string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);

    int flag = 0;
   
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {      
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((i != j) && (mat[index].matris[i][j] != 0))
                {
                    flag = 1;
                }
            }
        }
    }
    
    if (flag == 0)
    {
        cout << "Its Diagonal" << endl;
    }
    if (flag == 1)
    {
        cout << "Its not Diagonal" << endl;
    }
}

void is_upper_triangular(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan bala mosalasi boodan matris
{    
    string name_mat = find_name(command);
    
    int index = find_matrix_index(name_mat,  mat);

    int flag = 0;
   
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {      
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] != 0))
                {
                    flag = 1;
                }
            }
        }
    }
    
    if (flag == 0)
    {
        cout << "Its upper triangular" << endl;
    }
    if (flag == 1)
    {
        cout << "Its not upper triangular" << endl;
    }
}

void is_lower_triangular(string & command, vector<Matrix> & mat)//baraye moshakhas kardan payeen mosalasi boodan matris
{
    /*  for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                if (mat[i][j] != 0)
                {
                    return false;
                }
            }
        }    
    
    */
    string name_mat = find_name(command);
    
    int index = find_matrix_index(name_mat,  mat);

    int flag = 0;
   
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {      
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] != 0))
                {
                    flag = 1;
                }
            }
        }
    }
    
    if (flag == 0)
    {
        cout << "Its lower triangular" << endl;
    }
    if (flag == 1)
    {
        cout << "Its not lower triangular" << endl;
    }
    
}

void is_triangular(string & command, vector<Matrix> & mat)//baraye moshakhas kardan mosalasi boodan matris
{
    int pos = command.find("");
    string temp_command = command.substr(0, pos);

    int pos2 = command.find("", pos+1);
    string name = command.substr(pos, pos2 - pos);

    int flag = 0;

    //if ( row != col)
    //{
    //    return false;
    //}

    /*  for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (mat[i][j] != 0)
                {
                    flag = 0;
                }
                else 
                {
                    flag = 1;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                if (mat[i][j] != 0)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }    
        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        else if (flag == 0)
        {
            cout << "NO" << endl;
        }    
    */

}

void is_identtity(string & command, vector<Matrix> & mat)//baraye moshakhas kardan hamani ya hamooni boodan matris
{
    string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);

    int flag = 0;
   
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {      
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((i != j) && (mat[index].matris[i][j] != 0))
                {
                    flag = 1;
                }
            }
        }
    }
    
    if (flag == 0)
    {   
        int flag1 = 0;

        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if (mat[index].matris[i][j] != mat[index].matris[i+1][j+1])
                {
                    flag1 = 1;
                }
            }
        }
        if (flag1 == 0)
        {
            cout << "Its Identtity" << endl;
        }
        if (flag1 == 1)
        {
            cout << "Its not Identtity" << endl;
        }
    }
    if (flag == 1)
    {
        cout << "Its not Identtity" << endl;
    }
}

void is_normal_symmetric(string & command, vector<Matrix> & mat)//baraye moshakhas kardan motegharen boodan matris
{
    string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);

    int flag = 0;
   
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] != mat[index].matris[j][i]))
                {
                    flag = 1;
                }
            }
        }
    }   
    if (flag == 0)
    {
        cout << "Its Normal Symmetric" << endl;
    }
    if (flag == 1)
    {
        cout << "Its not Normal Symmetric" << endl;
    }
}

void is_skew_symmetric(string & command, vector<Matrix> & mat)//baraye moshakhas kardan padmotegharen boodan matris
{
    string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);

    int flag = 0;
   
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] == -(mat[index].matris[j][i])))
                {
                    flag = 1;
                }
            }
        }
    }   
    if (flag == 0)
    {
        cout << "Its Skew Symmetric" << endl;
    }
    if (flag == 1)
    {
        cout << "Its not Skew Symmetric" << endl;
    }    
}

void is_symmetric(string & command, vector<Matrix> & mat)//baraye moshakhas kardan motegharen boodan matris
{
     string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);

    int flag1, flag2 = 0;
   
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] != mat[index].matris[j][i]))
                {
                    flag1 = 1;
                }
                else if((mat[index].matris[i][j] == -(mat[index].matris[j][i])))
                {
                    flag2 = 1;
                }
            }
        }
    }   
    if (flag1 == 0)
    {
        cout << "Its Normal Symmetric" << endl;
    }
    if (flag2 == 0)
    {
        cout << "Its Skew Symmetric" << endl;
    }
    if (flag1 == 1 && flag2 == 1)
    {
        cout << "The matrix isnt symmetric." << endl;
    }
}

void inverse(string & command, vector<Matrix> & mat)//baraye makoos kardan matris
{

}

void show(const string & command, vector<Matrix> & mat)//baraye namayesh matris
{   
    string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);
    
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    
    if (index > -1)
    {   
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                cout << mat[index].matris[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void deletee(string & command, vector<Matrix> & mat)//baraye hazf matris //bug ********************************************
{
    string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);
    
    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    if (index > -1)
    {   
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                mat[index].matris[i][j];//**********************************************************************************
                
            }
        }
    }

}

void change(string & command, vector<Matrix> & mat)//baraye viyraesh yek khoone az matris //bug**********************************
{
    int pos = command.find(" ");
    string temp_command = command.substr(0, pos);

    int pos2 = command.find(" ", pos + 1);
    string name_mat = command.substr(pos, pos2 - pos);

    int row = command[pos2 + 1] - 48;

    int col = row;
  
    if (command[pos2 + 4] == ' ')
    {
        col = command[pos2 + 3] - 48;
    }

    command = command.substr(pos2 + 5);

    int index = find_matrix_index(name_mat, mat);

    cout << command[0]-48 << index << name_mat << row << col << endl;    

    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    
    if (index > -1)
    {   
        mat[index].matris[row][col] = (command[0] - 48); // ****************************************************************
    }

}

int find_matrix_index(const string & name, vector<Matrix> & mat)
{   
    for (size_t i = 0; i < mat.size(); i++)
    {
        if (mat[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

string find_name(const string & command)
{
    int pos = command.find(" ");
    string temp_command = command.substr(0, pos);

    int pos2 = command.find(" ", pos + 1);
    string name_mat = command.substr(pos, pos2 - pos);

    return name_mat;
}

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
        else if (check == "is_diagonal")
        {
            is_diagonal(command, mat);
        }
        else if (check == "is_upper_triangular")
        {
            is_upper_triangular(command, mat);
        }
        else if (check == "is_lower_triangular")
        {
            is_lower_triangular(command, mat);
        }
        else if (check == "is_triangular")
        {
            is_triangular(command, mat);
        }
        else if (check == "is_identtity")
        {
            is_identtity(command, mat);
        }
        else if (check == "is_normal_symmetric")
        {
            is_normal_symmetric(command, mat);
        }
        else if (check == "is_skew_symmetric")
        {
            is_skew_symmetric(command, mat);
        }
        else if (check == "is_symmetric")
        {
            is_symmetric(command, mat);
        }
        else if (check == "inverse")
        {
            inverse(command, mat);
        }
        else if (check == "show")
        {
            show(command, mat);
        }
        else if (check == "deletee")
        {
            deletee(command, mat);
        }
        else if (check == "change")
        {
            change(command, mat);
        }
        else if (check == "help")
        {
            help();
        }
        else if (check == "exit")
        {
            break;
        }
    }
    return 0;
}

void help()//baraye komak be karbar va modiriyat barname
{
    cout<< "------------------------------------------------------------------------------------"<< "\n"
        << "- add_matrix          ---> example : add_matrix (name)_mat (row) (colnum) (elements)"<< "\n" 
        << "- is_diagonal         ---> example : is_diagonal (name)_mat"                         << "\n"
        << "- is_upper_triangular ---> example : is_upper_triangular (name)_mat"                 << "\n"
        << "- is_lower_triangular ---> example : is_lower_triangular (name)_mat"                 << "\n"
        << "- is_triangular       ---> example : is_triangular (name)_mat"                       << "\n"
        << "- is_identtity        ---> example : is_identity (name)_mat"                         << "\n"
        << "- is_normal_symmetric ---> example : is_normal_symmetric (name)_mat"                 << "\n"
        << "- is_skew_symmetric   ---> example : is_skew_symmetric (name)_mat"                   << "\n"
        << "- is_symmetric        ---> example : is_symmetric (name)_mat"                        << "\n"
        << "- inverse             ---> example : inverse mat_2 (name)_mat (name)_mat"            << "\n"
        << "- show                ---> example : show (name)_mat"                                << "\n"
        << "- deletee             ---> example : deletee (name)_mat"                             << "\n"
        << "- change              ---> example : change (name)_mat (row) (colnum) (new element)" << "\n"
        << "- help"                                                                              << "\n"
        << "- exit"                                                                              << "\n"
        << "------------------------------------------------------------------------------------"<< endl;   
}