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
void add_matrix(string command, vector<Matrix> & mat);
void is_diagonal(const string & command, vector<Matrix> & mat);
void is_upper_triangular(const string & command, vector<Matrix> & mat);
void is_lower_triangular(const string & command, vector<Matrix> & mat);
void is_triangular(const string & command, vector<Matrix> & mat);
void is_identtity(const string & command, vector<Matrix> & mat);
void is_normal_symmetric(const string & command, vector<Matrix> & mat);
void is_skew_symmetric(const string & command, vector<Matrix> & mat);
void is_symmetric(const string & command, vector<Matrix> & mat);
void inverse(string & command, vector<Matrix> & mat);
void show(const string & command, vector<Matrix> & mat);
void deletee(string & command, vector<Matrix> & mat);
void change(string & command, vector<Matrix> & mat);
int find_matrix_index(const string & name, vector<Matrix> & mat);
string find_name(const string & command);

void add_matrix(string command, vector<Matrix> & mat)//baraye ezafe kardan matris
{   
    struct matrix temp;

    if (command == "add_matrix")
    {
        int row, col;
        string name_mat;

        cout << "Enter a name : ";
        cin >> name_mat;
        temp.name = name_mat;

        cout << "Enter rows : ";
        cin >> row;

        cout << "Enter columns : ";
        cin >> col;

        int temp_num;
        
        if (row > 0 && col > 0)
        { 
            for(int i = 0; i < row; i++)
            {
                temp.matris.push_back(vector<int>());
            
                for(int j = 0; j < col; j++)
                {
                    cout << "Enter row[" << i+1 << "] , col[" << j+1 << "] : ";
                    cin >> temp_num;
                    temp.matris[i].push_back(temp_num);          
                }    
            }
            cout << "Matrix Added" << endl;
        }
        else if (row < 0 || col < 0)
        {
            cout << "You cant add a matrix with invalid row or column" << endl;
        }
    }
    else
    {
        int pos = command.find(" ");
        int pos2 = command.find(" ", pos + 1);
        
        string name_mat = command.substr(pos, pos2 - pos);

        temp.name = name_mat;

        int pos3 =  command.find(" ", pos2 + 1);
        int row = stoi(command.substr(pos2, pos3 - pos2));

        int col = row;

        if (row < 0 || col < 0)
        {
            cout << "You cant add a matrix with invalid row or column" << endl;
            
        }

        if(command.find(",", pos3 + 1) > command.find(" ", pos3 + 1)) // if input col
        {
            col = stoi(command.substr(pos3 + 1, command.find(" ", pos3 + 1) - pos3));
        
            command = command.substr(command.find(" ", pos3 + 1) + 1);
        }
        else
        {
           command = command.substr(pos3 + 1);
        }
    
        for(int i = 0; command != "" && i < row; i++)
        {
            temp.matris.push_back(vector<int>());
        
            for(int j = 0; command != "" && j < col; j++)
            {
                temp.matris[i].push_back(stoi(command.substr(0, command.find(","))));
            
                if(command.find(",") == string::npos)
                {          
                    mat.push_back(temp);
                    break;
                }
                command = command.substr(command.find(',') + 1);
            }
        }
        if (row > 0 && col > 0)
        {
            cout << "Matrix Added" << endl;
        }    
    }
}

void is_diagonal(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan ghotri boodan matris   
{   
    string name_mat = find_name(command);// peyda kardan esm matris

    int index = find_matrix_index(name_mat,  mat); // peyda kardan khoone matrisi ke ba esm hamkhooni dare 

    int flag = 1; 
   
    if (index == -1)//esm vared shode eshtebahe ya matrix add nashode
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {      
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if (i != j)
                { 
                    if((mat[index].matris[i][j] != 0))// shart ghotri naboodan
                    {
                        flag = 0;// ghotri nist
                    }
                }
            }
        }
    }   
    
    if (flag == 1)
    {
        cout << "YES" << endl;
    }
    if (flag == 0)
    {
        cout << "NO" << endl;
    }
}

void is_upper_triangular(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan bala mosalasi boodan matris
{    
    string name_mat = find_name(command);// peyda kardan esm matrix
    
    int index = find_matrix_index(name_mat,  mat); // peyda kardan khoone matrisi ke ba esm hamkhooni dare

    int flag = 1;
   
    if (index == -1)
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {      
        for(int i = 0; i < mat[index].matris.size(); i++)
        {
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                if(j > i)
                {
                    if(mat[index].matris[i][j] != 0)// check kardan bala mosalasi boodan
                    {
                        flag = 0;// bala mosalasi nist
                    }
                }
            }
        }    

        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }

}

void is_lower_triangular(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan payeen mosalasi boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix
    
    int index = find_matrix_index(name_mat,  mat); // peyda kardan khoone matrisi ke ba esm hamkhooni dare

    int flag = 1;
   
    if (index == -1)
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {      
        for(int i = 0; i < mat[index].matris.size(); i++)
        {
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                if(j < i)
                {
                    if(mat[index].matris[i][j] != 0)// check kardan payeen mosalasi boodan
                    {
                        flag = 0;// payeen mosalasi nist
                    }
                }
            }
        }    

        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }
}

void is_triangular(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan mosalasi boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix
    
    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    int flag1 = 1;// jahat check kardan bala mosalasi boodan
    int flag2 = 1;// jahat check kardan payeen mosalasi boodan

    if (index == -1)
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {      
        for(int i = 0; i < mat[index].matris.size(); i++)
        {
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                if(j > i)
                {
                    if(mat[index].matris[i][j] != 0)// check kardan bala mosalasi boodan
                    {
                        flag1 = 0;// bala mosalasi nist
                    }
                }
            }
        } 

            
        for(int i = 0; i < mat[index].matris.size(); i++)
        {
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                if(j < i)
                {
                    if(mat[index].matris[i][j] != 0)// check kardan payeen mosalasi boodan
                    {
                        flag2 = 0;// payeen mosalasi nist
                    }
                }
            }
        }       

        if (flag1 == 1)
        {
            cout << "YES --> Upper Triangular" << endl;
        }
        if (flag2 == 1)
        {
            cout << "YES --> Lower Triangular" << endl;
        }
        else if (flag1 == 0 && flag2 == 0)
        {
            cout << "NO" << endl;
        }
    }
}

void is_identtity(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan hamani ya hamooni boodan matris
{
    string name_mat = find_name(command);//peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    int flag = 1;//jahat check kardan ghotri boodan
   
    if (index == -1)
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {      
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if (i != j )
                {
                    if ((mat[index].matris[i][j] != 0))//check kardan ghotri boodan
                    {
                        flag = 0;
                    }
                }
            }
        }

    
        if (flag == 1)// age ghotri bood vared inja mishe
        {   
            int flag1 = 1;//check kardan hamani boodan

            for (int i = 0; i < mat[index].matris.size(); i++)
            {
                for (int j = 0; j < mat[index].matris[i].size(); j++)
                {   
                    if (i-1 == j-1)
                    {
                        if (mat[index].matris[i ][j] == 1 && mat[index].matris[i+1][j+1] == 1) ////////////////****************
                        {
                            flag1 = 0;
                        }
                    }
                }
            }

            if (flag1 == 1)
            {
                cout << "YES" << endl;
            }
            if (flag1 == 0)
            {
                cout << "NO" << endl;
            }
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }
}

void is_normal_symmetric(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan motegharen boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    int flag = 1;
   
    if (index == -1)
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] != mat[index].matris[j][i]))//check kardan motegharen boodan
                {
                    flag = 0;//motegharen nist
                }
            }
        }
    }   
    if (flag == 1)
    {
        cout << "YES" << endl;
    }
    if (flag == 0)
    {
        cout << "NO" << endl;
    }
}

void is_skew_symmetric(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan padmotegharen boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    int flag = 1;
   
    if (index == -1)
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if (j > i)
                {
                    if ((mat[index].matris[j][i] != -(mat[index].matris[i][j])))// check kardan pad motegharn boodan
                    {
                        flag = 0;// pad motegharen nist
                    }
                }
                if (j < i)
                {
                    if ((mat[index].matris[i][j] != -(mat[index].matris[j][i])))// check kardan pad motegharn boodan
                    {
                        flag = 0;// pad motegharen nist
                    }
                }
            }
        }
       
        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }    
}

void is_symmetric(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan motegharen boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    int flag1 = 1;
    int flag2 = 1;
   
    if (index == -1)
    {
        cout << "matrix not found!" << endl;
    }
    if (index > -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] != mat[index].matris[j][i]))//check kardan motegharen boodan
                {
                    flag1 = 0;//motegharen nist
                }
            }    
        }

        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if (j > i)
                {
                    if ((mat[index].matris[j][i] != -(mat[index].matris[i][j])))// check kardan pad motegharn boodan
                    {
                        flag2 = 0;// pad motegharen nist
                    }
                }
                if (j < i)
                {
                    if ((mat[index].matris[i][j] != -(mat[index].matris[j][i])))// check kardan pad motegharn boodan
                    {
                        flag2 = 0;// pad motegharen nist
                    }
                }
            }
        }  
        
        if (flag1 == 1)
        {
            cout << "YES --> Normal Symmetric" << endl;
        }
        if (flag2 == 1)
        {
            cout << "YES --> Skew Symmetric" << endl;
        }
        if (flag1 == 0 && flag2 == 0)
        {
            cout << "NO" << endl;
        }
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

    if (index == -1)
    {
        cout << "matrix doesnt found!" << endl;
    }
    
    if (index > -1)
    {   
        mat[index].matris[row][col] = (command[0] - 48); // ****************************************************************
    }

}

int find_matrix_index(const string & name, vector<Matrix> & mat)// peyda kardan khoone matrisi ke ba esm hamkhooni dare
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

string find_name(const string & command)// peyda kardan esm matrix
{
    int pos = command.find(" ");
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