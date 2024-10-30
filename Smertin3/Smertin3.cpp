#include <iostream>
#include <string>
#include <clocale>

using namespace std;

//#1-3
class Name {
public:
    string surname;    // Фамилия
    string firstName;  // Имя
    string patronymic; // Отчество

    Name(const string& surname = "", const string& firstName = "", const string& patronymic = "")
        : surname(surname), firstName(firstName), patronymic(patronymic) {}

    string toString(){
        string result;

        if (!surname.empty()) {
            result += surname + " "; // Добавляем фамилию
        }
        if (!firstName.empty()) {
            result += firstName + " "; // Добавляем личное имя
        }
        if (!patronymic.empty()) {
            result += patronymic; // Добавляем отчество
        }

        // Убираем лишний пробел в конце строки
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result; // Возвращаем результат
    }

    // Метод для вывода имени на экран
    void print(){
        cout << toString() << endl; // Вызываем toString() и выводим результат
    }
};

//#2-2
class Person {
public:
    Name name; // Имя человека
    int height; // Рост человека
    // Конструктор для инициализации объекта Person
    Person(const Name& name, int height) : name(name), height(height) {}

    // Метод для вывода информации о человеке
    void print(){
        cout << "Человек: " << name.toString() << ", Рост: " << height << " см" << endl;
    }
};

//#5-2
class Cat {
public:
    string cat_name;
    int count;
    Cat(const string cat_name, int count) : cat_name(cat_name), count(count) {}
    void printname() {
        cout << "Кот по имени " << cat_name << endl;
    }
    void meow() {
        int i = 0;
        cout << cat_name << ": ";
        while (count != 0) {
            if (i == 0) {
                cout << "МЯУ ";
                i++;
                count--;
            }
            else {
                cout << "- МЯУ ";
                count--;
            }
            
        }
        cout << "!" << endl;
    }

};
int main() {
    setlocale(LC_ALL, "rus");
    //#1-3
    // Создаем имена
    cout << "#1-3" << endl;
    Name name1{ "Клеопатра" };
    Name name2{ "Пушкин", "Александр", "Сергеевич" };
    Name name3{ "Маяковский", "Владимир" };
    // Выводим имена на экран с помощью метода print()
    name1.print();
    name2.print();
    name3.print();
    cout << endl;
    //#2-2
    // Создаем людей
    cout << "#2-2" << endl;
    Person person1{ name1, 152 };
    Person person2{ name2, 167 };
    Person person3{name3, 189};

    // Выводим информацию о людях
    person1.print(); 
    person2.print(); 
    person3.print(); 
    cout << endl;
    
    //#5-2
    cout << "#5-2" << endl;
    Cat cat1("Барсик", 1);
    cat1.printname();
    cat1.meow();
    int n;
    cout << "Введите количество мяуканий: ";
    cin >> n;
    cat1.count = n;
    cat1.meow();
    return 0;
}
