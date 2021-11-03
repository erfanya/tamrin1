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

int find_matrix_index(const string & name, vector<Matrix> & mat)// peyda kardan khoone matrisi ke ba esm hamkhooni dare
{   
    for (size_t i = 0; i < mat.size(); i++)
    {
        if (mat[i].name == name)// peyda kardan esm matrs
        {
            return i;// bargardoondan khoone e az vector ke matris dakhelesh zakhire shode
        }
    }
    cout << "matrix not found!" << endl;
    return -1;// age esm peyda nashe -1 barmigarde ke neshoone vojod nashtane matrise
}

string find_name(const string & command)// peyda kardan esm matrix
{
    int pos = command.find(" ");// avalin space 
    int pos2 = command.find(" ", pos + 1);// dovomin space bad az avalin space
    
    string name_mat = command.substr(pos, pos2 - pos);// esm = harchiz beyn 2 space 
    
    return name_mat;
}

void add_matrix(string command, vector<Matrix> & mat)//baraye ezafe kardan matris
{   
    struct matrix temp; 

    
    int pos = command.find(" ");// peyda kardan avalim space 
    int pos2 = command.find(" ", pos + 1); // peyda kardan dovomin space nesbat be space aval
        
    string name_mat = command.substr(pos, pos2 - pos); // name = harchiz beyn space 2 - space 1
    temp.name = name_mat;// save kardan name dakhel struct

    int pos3 =  command.find(" ", pos2 + 1);// peyda kardan sevomin space nesbat be space 2
    int row = stoi(command.substr(pos2, pos3 - pos2)); // row = spcae 3 = space 2 

    int col = row; // col = row (by default)

    if (row < 0 || col < 0)
    {
        cout << "You cant add a matrix with invalid row or column" << endl;
    }

    if(command.find(",", pos3 + 1) > command.find(" ", pos3 + 1)) // if input col
    {
        col = stoi(command.substr(pos3 + 1, command.find(" ", pos3 + 1) - pos3));// peyda kardan sootoon 
        
        command = command.substr(command.find(" ", pos3 + 1) + 1);// element ha
    }
    else
    {
        command = command.substr(pos3 + 1);// element ha 
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

bool is_diagonal(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan ghotri boodan matris   
{   
    string name_mat = find_name(command);// peyda kardan esm matris

    int index = find_matrix_index(name_mat,  mat); // peyda kardan khoone matrisi ke ba esm hamkhooni dare 

    if (index != -1)
    {      
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if (i != j)
                { 
                    if((mat[index].matris[i][j] != 0))// shart ghotri naboodan
                    {
                        return false;// ghotri nist
                    }
                }
            }
        }
        return true;
    }   
    return false;
}

bool is_upper_triangular(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan bala mosalasi boodan matris
{    
    string name_mat = find_name(command);// peyda kardan esm matrix
    
    int index = find_matrix_index(name_mat,  mat); // peyda kardan khoone matrisi ke ba esm hamkhooni dare

    if (index != -1)
    {      
        for(int i = 0; i < mat[index].matris.size(); i++)
        {
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                if(j < i)
                {
                    if(mat[index].matris[i][j] != 0)// check kardan payeen mosalasi boodan
                    {
                        return false;// payeen mosalasi nist
                    }
                }
            }
        }    
        return true;
    }
    return false;
}

bool is_lower_triangular(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan payeen mosalasi boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix
    
    int index = find_matrix_index(name_mat,  mat); // peyda kardan khoone matrisi ke ba esm hamkhooni dare
    
    if (index != -1)
    {      
        for(int i = 0; i < mat[index].matris.size(); i++)
        {
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                if(j > i)
                {
                    if(mat[index].matris[i][j] != 0)// check kardan payeen mosalasi boodan
                    {
                        return false;// payeen mosalasi nist
                    }
                }
            }
        }    
        return true;
    }
    return false;
}

void is_triangular(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan mosalasi boodan matris
{
    int upper = is_upper_triangular(command, mat);
    int lower = is_lower_triangular(command, mat);

    if (upper == true)
    {
        cout << "YES --> Upper Triangular" << endl;
    }
    if (lower == true)
    {
        cout << "YES --> Lower Triangular" << endl;
    }
    else if (lower == false && upper == false)
    {
        cout << "NO" << endl;
    }
}

bool is_identtity(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan hamani ya hamooni boodan matris
{
    string name_mat = find_name(command);//peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare
 
    if (index != -1)
    {      
        int diagonal = is_diagonal(command, mat);//jahat check kardan ghotri boodan
        
        if (diagonal == true)
        {
            for (int i = 0; i < mat[index].matris.size(); i++)
            {
                 for (int j = 0; j < mat[index].matris[i].size(); j++)
                {   
                    if (i == j)
                    {
                        if (mat[index].matris[i][j] != 1) // check kardan hamani boodan
                        {   
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    }
    return false;   
}

bool is_normal_symmetric(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan motegharen boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    if (index != -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if ((mat[index].matris[i][j] != mat[index].matris[j][i]))//check kardan motegharen boodan
                {
                    return false;//motegharen nist
                }
            }
        }
        return true;
    }   
    return false;
}

bool is_skew_symmetric(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan padmotegharen boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    if(index != -1)
    {
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            for (int j = 0; j < mat[index].matris[i].size(); j++)
            {
                if (j > i)
                {
                    if ((mat[index].matris[j][i] != -(mat[index].matris[i][j])))// check kardan pad motegharn boodan
                    {
                        return false;// pad motegharen nist
                    }
                }
                if (j < i)
                {
                    if ((mat[index].matris[i][j] != -(mat[index].matris[j][i])))// check kardan pad motegharn boodan
                    {
                        return false;// pad motegharen nist
                    }
                }
            }
        }
        return true;
    }
    return false;
}

void is_symmetric(const string & command, vector<Matrix> & mat)//baraye moshakhas kardan motegharen boodan matris
{
    string name_mat = find_name(command);// peyda kardan esm matrix

    int index = find_matrix_index(name_mat,  mat);// peyda kardan khoone matrisi ke ba esm hamkhooni dare

    if (index > -1)
    {
        int normal = is_normal_symmetric(command, mat);
        int skew = is_skew_symmetric(command, mat);
   
        if (normal == true)
        {
            cout << "YES --> Normal Symmetric" << endl;
        }
        if (skew == true)
        {
            cout << "YES --> Skew Symmetric" << endl;
        }
        if (normal == 0 && skew == 0)
        {
            cout << "NO" << endl;
        }
    }
}

void inverse(const string & command, vector<Matrix> & mat)//baraye makoos kardan matris
{
    int pos = command.find(" ");// peyda kardan avalin space
    int pos2 = command.find(" ", pos + 1);// peyda kardan dovomin space
    
    string name_mat1 = command.substr(pos, pos2 - pos);// harchiz beyn space 1 va 2 = name 1
    
    int pos3 = command.find(" ", pos2 + 1);// peyda kardan space 3 
    
    string name_mat2 = command.substr(pos2, pos3 - pos2);// harchiz beyn space 3 va 2 = name 2

    int index = find_matrix_index(name_mat1, mat);

    if (index != -1)
    {
        Matrix temp;
        temp.name = name_mat2;
    
        for (int i = 0; i < mat[index].matris.size(); i++)
        {
            temp.matris.push_back(vector<int>());
            
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                temp.matris.back().push_back(0);
            }
        }
        
        for(int i = 0; i < mat[index].matris.size(); i++)
        {
            for(int j = 0; j < mat[index].matris.size(); j++)
            {
                temp.matris[j][i] = mat[index].matris[i][j];
            }
        }
        mat.push_back(temp);
    }
}

void show(const string & command, vector<Matrix> & mat)//baraye namayesh matris
{   
    string name_mat = find_name(command);
    
    int index = find_matrix_index(name_mat,  mat);
    
    if (index != -1)
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

void deletee(string & command, vector<Matrix> & mat)//baraye hazf matris
{
    string name_mat = find_name(command);

    int index = find_matrix_index(name_mat,  mat);
    
    if (index != -1)
    {  
        vector<Matrix> temp;
        
        for(int i = 0; i < mat.size(); i++)
        {
            if(i != index)
            {
                temp.push_back(mat[i]);
            }

        }
        mat = temp;
        cout << name_mat << ": Deleted" << endl;
    }
}

void change(string & command, vector<Matrix> & mat)//baraye viyraesh yek khoone az matris 
{
    int pos = command.find(" ");
    int pos2 = command.find(" ", pos + 1);
        
    string name_mat = command.substr(pos, pos2 - pos);

    int pos3 =  command.find(" ", pos2 + 1);
    int row = stoi(command.substr(pos2, pos3 - pos2));
    
    int pos4 = command.find(" ", pos3 + 1);
    int col = stoi(command.substr(pos3, pos4 - pos3));
    
    if (row < 0 || col < 0)
    {
        cout << "You cant change a matrix with invalid row or column" << endl;  
    }
    
    int new_element = stoi(command.substr(pos4 + 1));

    if (row > 0 && col > 0)
    {
        int index = find_matrix_index(name_mat, mat);

        if (index != -1)
        {   
            for (int i = 1; i < mat[index].matris.size(); i++)
            {
                for (int j = 1; j < mat[index].matris[i].size(); i++)
                {
                    mat[index].matris[row-1][col-1] = new_element; 
                }
            }   
        cout << "Change was successful" << endl;
        }
    }
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
