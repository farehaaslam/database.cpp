#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<numeric>

using namespace std;
struct Employee{
    int id;
    
    string name;
double salary;
};
void displayEmployee(const Employee& emp){
    cout<<"ID: "<<emp.id<<"name: " <<emp.name<<" ,salary:$ "<<emp.salary<<endl;

}
int main(){
    vector<Employee>employees = { 
        {101,"fareha",10000},
        {102,"faizah",90000},
        {103,"zikra",80000},
        {104,"mummy",600000},
    };
    //psorting element in increasing order 
    sort(employees.begin(),employees.end(),[](Employee e1,Employee e2){
        return e1.salary>e2.salary;
    });
    //lamda  are unnamed functions
    cout<<"employee sorted by the salary ";
    for_each(employees.begin(),employees.end(),displayEmployee);
    //printing high achievers 

    vector<Employee>highEarner;
    copy_if(
        employees.begin(),employees.end(),back_inserter(highEarner),[](Employee e1){
            return e1.salary>50000;
        }
    );
    cout<<"employee who leaarn high";
    for_each(highEarner.begin(),highEarner.end(),displayEmployee);
    //accemulate like reduce in javascript   is innumeric header file 
    //initial value is 0.0
    //sum ke andar 0.0 value jayge initially
     double totalsalary=accumulate(employees.begin(),employees.end(),0.0,[](double sum,Employee e){
        return  sum+e.salary;

    });
    double avg=totalsalary/employees.size();
    auto highestpaid=max_element(employees.begin(),employees.end(),[](Employee e1,Employee e2){
        return e1.salary <e2.salary;
    });

}
