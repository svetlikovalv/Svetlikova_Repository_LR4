#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

double a;
double b;

function<void()> enter_number(double&var_link,string label){
    //branch_fun_1
}
void modul(){
    //branch_fun_2
}
void argument(){
    //branch_fun_3
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
    double choice = 0;

    cout<<"Меню: "<<endl;
    for (const auto& item : menu){
        cout<<"Task "<<item.first<<". "<<item.second.title<<endl;
    }
    cout<<"0. Выход"<<endl;
    while (true){
        enter_number(choice,"Введите номер задачи: ")();
        if (choice==0){
            cout<<"Вы вышли из программы"<<endl;
            break;
        }
        cout<<"==========Action=========="<<endl;
        if (menu.find(choice)!=menu.end()){
            menu[choice].action;
        }
        else{
            cout<<"Некорректный ввод. ";
        }
        cout<<endl;
    }
    return 0;
}