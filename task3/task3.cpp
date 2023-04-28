#include <iostream>



template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class CircularLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    CircularLinkedList() : 
head(nullptr), tail(nullptr) {}

    ~CircularLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insert(T data) {
        Node<T>* new_node = new Node<T>(data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            tail->next = head;
        }
        else {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
        }
    }

    void remove(T data) {
        if (head == nullptr) {
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != tail) {
            if (current->data == data) {
                break;
            }
            prev = current;
            current = current->next;
        }
        if (current == tail && current->data == data) {
            tail = prev;
            tail->next = head;
            delete current;
            return;
        }
        if (current == head && current->data == data) {
            head = current->next;
            tail->next = head;
            delete current;
            return;
        }
        if (current != head && current != tail) {
            prev->next = current->next;
            delete current;
        }
    }

    void print_list() {
        Node<T>* current = head;
        while (current != tail) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << tail->data << std::endl;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    CircularLinkedList<int> list_int;

    // Ввод значений с клавиатуры и добавление в список
    std::cout << "Введите числа для добавления в список (0 - завершить):" << std::endl;
    int num;
    do {
        std::cin >> num;
        if (num != 0) {
            list_int.insert(num);
        }
    } while (num != 0);

    // Вывод списка на экран
    std::cout << "Содержимое списка: ";
    list_int.print_list();

    // Удаление значения из списка
    std::cout << "Введите значение, которое хотите удалить из списка: ";
    std::cin >> num;
    list_int.remove(num);

    // Вывод списка на экран после удаления значения
    std::cout << "Содержимое списка после удаления: ";
    list_int.print_list();

    CircularLinkedList<std::string> list_str;

    // Ввод значений с клавиатуры и добавление в список
    std::cout << "Введите значение для добавления в список(exit - выход):" << std::endl;
    std::string str;
    do {
        std::cin >> str;
        if (str != "exit") {
            list_str.insert(str);
        }
    } while (str != "exit");

    // Вывод списка на экран
    std::cout << "Содержимое списка: ";
    list_str.print_list();

    // Удаление значения из списка
    std::cout << "Введите значение, которое хотите удалить из списка: ";
    std::cin >> str;
    list_str.remove(str);

    // Вывод списка на экран после удаления значения
    std::cout << "Содержимое списка после удаления: ";
    list_str.print_list();

}