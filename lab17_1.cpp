#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
ifstream h(filename.c_str());
 string t;
 while(getline(h,t)){
char format[] ="%[^:]:%f %f %f";
char name[100];
float a,b,c;
sscanf(t.c_str(),format,name,&a,&b,&c);
char grade =score2grade(a+b+c);
scores.push_back(a+b+c);
names.push_back(name);
grades.push_back(grade);
 }
}

void getCommand(string &command,string &key){
    cout <<"Please input your command: ";
    cin >> command;
    string g = toUpperStr(command);
    if(g=="GRADE"||g=="NAME"){
    cin.ignore();
    getline(cin,key);
    }


}

void searchName( vector<string> names, vector<int> scores,vector<char> grades,string key){
int n = names.size();
int b=0;
 for(int i=0;i<n;i++){
    if(toUpperStr(names[i])==key.c_str()){
        cout <<"---------------------------------\n";
        cout << names[i]<<"'s score = "<<scores[i]<<"\n";
        cout << names[i]<<"'s grade = "<<grades[i]<<"\n";
        cout <<"---------------------------------\n";
        b++;
    }
 }
 if(b==0){
     cout <<"---------------------------------\n";
     cout << "Cannot found."<<"\n";
     cout <<"---------------------------------\n";
 }
}


void searchGrade(vector<string> names, vector<int> scores,vector<char> grades,string key){
int n = names.size();
int b=0;
cout <<"---------------------------------\n";
 for(int i=0;i<n;i++){
     grades[i]=toupper(grades[i]);
    if(grades[i]==key[0]){
        cout << names[i]<<" "<<"("<<scores[i]<<")"<<"\n";
        b++;
    }
 }
 if(b==0){
     cout <<"---------------------------------\n";
     cout << "Cannot found."<<"\n";
     cout <<"---------------------------------\n";
 }
  cout <<"---------------------------------\n";
}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}