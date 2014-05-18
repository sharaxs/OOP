#include <iostream>
#include <cstring>
using namespace std;

class employee{ 
private:
    char * name; // ім я
    int age; // вік
    int work; // стаж работы

    // копирование строки в сроку имя
    void set_name( char * source ){
        if( name ) delete name;
        name = new char[strlen(source)+1];
        strcpy( name, source );
    }
    // копирование данных
    void copy( const employee & employee ){
        age = employee.age;
        work = employee.work;
        set_name( employee.name );
    }
public:
    explicit employee( char * Name = "", int Age=0, int Work=0 )
        :name(NULL), age(Age), work(Work) { set_name(Name); }  
    employee( const employee & employee )
        :name(NULL){ copy( employee ); }
    employee & operator=( const employee & employee ){
        if( this != &employee )
            copy( employee );
        return *this;
    }
    ~employee(){
        delete name;
    }
    friend ostream & operator<<( ostream & out, employee & m ); 
    friend istream & operator>>( istream & in, employee & m ); 
};


ostream & operator<<( ostream & out, employee & m ){
    out << "Name\t" << m.name;
    out << "\nAge\t" << m.age;
    out << "\nWork\t" << m.work << endl;
    return out;
}//операртор show //виводить в cout
istream & operator>>( istream & in, employee & m ){
    char buf[1000];
    cout << "Name\t";        in >> buf;
    cout << "Age\t";            in >> m.age;
    cout << "Work\t";        in >> m.work;
    m.set_name(buf);
    return in;
}

int main(){
    employee employee; 
    cin >> employee; 
    cout << "\n\n" << employee; 

    cin.sync();
    cin.clear();
    cout << "\n\nPress enter key to continue";
    cin.get(); 
    return 0;
}
