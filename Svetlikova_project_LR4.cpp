#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

double a;
double b;

bool user_input(string input){
    if (input.empty())return false;
    try{
        double number=stod(input);
        
    }
    catch(...)
    {return false;}
    return true;

}

//branch_func_0
function<void()>enter_choice(int&var_link,string label){
    return[&var_link,label](){
        string raw_input;
        cout<<label<<" = ";
        getline(cin,raw_input);
        while (!user_input(raw_input))
        {
            cout<<label<<" = ";
            getline(cin,raw_input);

        }
        var_link=stoi(raw_input);
    };

}
//branch_func_1
function<void()>enter_number(double&var_link,string label){
    return[&var_link,label](){
        string raw_input;
        cout<<label<<": ";
        getline(cin,raw_input);
        while (!user_input(raw_input))
        {
            cout<<label<<": ";
            getline(cin,raw_input);

        }
        var_link=stod(raw_input);
    };

}


void modul(){

    //branch_fun_2
    cout<<"модуль комплексного числа: "<<pow((a*a+b*b),0.5)<<endl;

}

void argument(){
    //branch_fun_3
    cout<<"комплексная часть числа а= "<<a<<"  комплексная часть числа b= "<<b<<endl;
    if (a>0){
        cout<<"аргумент функции"<<atan2(b,a)<<endl;
    }
    if (a<0 && b>0){
        cout<<"аргумент функции"<<atan2(b,a)+acos(-1.0) <<endl;
    }if(a<0 && b<0){ 
        cout<<"аргумент функции"<<atan2(b,a)-acos(-1.0) <<endl;
    }if(a==0&&b>0){
        cout<<"аргумент функции"<<acos(-1.0)/2<<endl;
    }
    if(a==0&&b<0){
        cout<<"аргумент функции"<<- acos(-1.0)/2 <<endl;
    }if (a==0 && b==0){
        cout<<"аргумента не существует"<<endl;
    }

}
struct menu_item{
    string title;
    function<void()>action;
};
int main(){
    

    map<int, menu_item > menu = {
        {1,{"Bвод вещественной части комплексного числа - a",enter_number(a,"введите целую часть комсплексного числа - а")}},
        {2,{"Bвод мнимой части комплексного числа - b",enter_number(b,"введите мнимую часть комсплексного числа - b")}},
        {3,{"Найти модуль комплексного числа",modul}},
        {4,{"Найти аргумент комплексного числа",argument}},
        
    };
    int choice = 0;

    while (true) {
        cout << "Меню:" <<endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << std::endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Вы вышли из программы" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод.";
        }
        cout << endl ;
    }
    return 0;
}
