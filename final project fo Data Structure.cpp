// final project fo Data Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mohamed Elnakshbandy
//Mosatafa Mohamed Ali
//Mohamed Yasser Saad

#include <iostream>
#include <string>
using namespace std;

struct Data 
{
    string name;
    string address;
    string disease; 
    string gender;
    string description;
    int specialRoomNo;
    int age;
};


struct Node 
{
    Data data;
    Node* next;
};

Data inputPatients()
{
    string name, address, disease, gender, description;
    int specialRoomNo, age;
    Data p;

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Patient Address: ";
    getline(cin, address);

    cout << "Enter Patient Disease: ";
    getline(cin, disease);

    cout << "Enter Patient Gender: ";
    getline(cin, gender);

    cout << "Enter Disease Description: ";
    getline(cin, description);

    cout << "Enter Patient Special Room No.: ";
    cin >> specialRoomNo;

    cout << "Enter Patient Age: ";
    cin >> age;

    p.name = name;
    p.address = address;
    p.gender = gender;
    p.description = description;
    p.specialRoomNo = specialRoomNo;
    p.age = age;

    cout << "\t\t\t\t\tCompleted input operation" << endl;

    return p;

}
//end of inputPatients function
void delElement(Node* head, int loc)
{
    Node* temp = new Node;

    temp = head;

    if (head == NULL) {

        cout << "\t\t\t\t\tNod is null" << endl;
        return;
    }


    for (int i = 1; i <= loc; ++i)
    {
        temp = temp->next;
        if (i < loc) {
            head = head->next;
        }//end of if statement

    }//end of for statement

    head->next = temp->next;

}
//end of delElement function
Node* searchList(Node* head, Data v) {

    if (head == NULL)
    {
        cout << "\t\t\t\t\tNode is empty returning null" << endl;
        return NULL;
    }

    int l = 1;

    while (head->next != NULL && head->data.name != v.name)
    {
        head = head->next;
        ++l;
    }

    cout << "Element found at location " << l << endl;

    return head;

}
//end of searchList function

Node* searchList(Node* head, string v)
{

    if (head == NULL)
    {
        cout << "\t\t\t\t\tNode is empty returning null" << endl;
        return NULL;
    }

    int l = 1;

    while (head->next != NULL && head->data.name != v)
    {
        head = head->next;
        ++l;
    }

    cout << "Element found at location " << l << endl;

    return head;

}
//end of searchList function
int listLength(Node* head) {
    int temp = 0;

    if (head == NULL)
    {
        cout << "\t\t\t\t\tNode is empty" << endl;
        return 0;
    }

    while (head->next != NULL)
    {
        ++temp;
        head = head->next;
    }

    return temp + 1;
}
//end of the listLength function

void printLinkedList(Node* head)
{
    if (head == NULL)
    {
        cout << "\t\t\t\t\tHead is null" << endl;
        return;
    }

    while (head->next != NULL)
    {
        cout << "Name: " << head->data.name << endl;
        cout << "Address: " << head->data.address << endl;
        cout << "Gender: " << head->data.gender << endl;
        cout << "Disease: " << head->data.disease << endl;
        cout << "Description: " << head->data.description << endl;
        cout << "Age: " << head->data.age << endl;
        cout << "Specialist No: " << head->data.specialRoomNo << endl;
        head = head->next;
    }
    cout << "Name: " << head->data.name << endl;
    cout << "Address: " << head->data.address << endl;
    cout << "Gender: " << head->data.gender << endl;
    cout << "Disease: " << head->data.disease << endl;
    cout << "Description: " << head->data.description << endl;
    cout << "Age: " << head->data.age << endl;
    cout << "Specialist No: " << head->data.specialRoomNo << endl;

}
//end of printLinkedList function
void changeNode(Node* head, Data data, Data newData)
{
    while (head != NULL)
    {
        if (head->data.name == data.name)
        {
            head->data = newData;
            break;
        }

        head = head->next;
    }
}//end of changeNode function

void changeNode(Node* head, string data, string newData)
{
    while (head != NULL)
    {
        if (head->data.name == data)
        {
            head->data.name = newData;
            break;
        }

        head = head->next;
    }
}
//end of changeNode function
Node* insertFront(Node* head, Data data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;

}//end of insertFront Function

Node* append(Node* head, Data data) {

    Node* temp = new Node;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return head;
    }

    Node* last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;

    cout << "\t\t\t\t\tAppend completed" << endl;

    return head;

}
//end of append function

int main()
{

    Node* head = NULL;
    Data patient;
    string nameToSearch;
    string oldName, newName;

    int op;
        cout <<"\n\n\t\t\t\t\tHospital Management System"<<endl;
        cout <<"\t\t1-Add Patient:"<<endl;
        cout <<"\t\t2-Del Patient:" << endl;
        cout <<"\t\t3-Search by Name:" << endl;
        cout <<"\t\t4-List Length:" << endl;
        cout <<"\t\t5-print List:"<<endl;
        cout <<"\t\t6-Change Patient Name:" << endl; 
        cout <<"\t\t7-Insert new at front:" << endl;
        cout <<"\t\t8-clear Screen:" << endl;
        cout <<"\t\t\t\t\t(CTRL + Z)To exit:" << endl;
    while (cin >> op)
    {

        switch (op) 
        {
        case 1:
            cout << "\t\t\t\t\tEnter Patient Details Below" << endl;
            patient = inputPatients();
            head = append(head, patient);
            break;

        case 2:

            if (listLength(head) < 2)
            {
                cout << "Length is less then two.\nTerminating program" << endl;
                exit(1);
            }
            else {
                cout << "Enter location where you want to delete a patient, at least three patients must be in list? ";
                int l;
                cin >> l;
                delElement(head, l - 1);
            }
            break;

        case 3:
            cout << "Enter name to search patient: ";
            cin.ignore();
            getline(cin, nameToSearch);
            searchList(head, nameToSearch);
            break;

        case 4:

            cout << "\t\t\t\t\tYou have " << listLength(head) << " Patients in your Hospital." << endl;

            break;

        case 5:
            printLinkedList(head);
            break;

        case 6:
            cin.ignore();
            cout << "Enter old name ";
            getline(cin, oldName);
            cout << "Enter New Name ";
            getline(cin, newName);

            changeNode(head, oldName, newName);
            break;

        case 7:
            patient = inputPatients();
            head = insertFront(head, patient);
            break;
        case 8:
            system("cls");
            break;

        default:
            cout << "\t\t\t\t\tWrong option Selected" << endl;
        }

        cout << "\t\t1-Add Patient:" << endl;
        cout << "\t\t2-Del Patient:" << endl;
        cout << "\t\t3-Search by Name:" << endl;
        cout << "\t\t4-List Length:" << endl;
        cout << "\t\t5-print List:" << endl;
        cout << "\t\t6-Change Patient Name:" << endl;
        cout << "\t\t7-Insert new at front:" << endl;
        cout << "\t\t8-clear Screen:" << endl;
        cout << "\t\t\t\t\t(CTRL + Z)To exit:" << endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
