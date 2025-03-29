#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


struct Teletype {
    string name;
    string phoneno;
    Teletype* nexaddr;
};

void display(Teletype* contents)
{
    int count = 0;
    cout << endl << "The linked list records:" << endl;
    while (contents != NULL)
    {
        cout << endl << setw(1) << contents->name << setw(20) << contents->phoneno;
        contents = contents->nexaddr;
        count++;
    }
    cout << endl << setw(0) << "There are " << count - 1 << " records in the data file." << endl;
    cout << endl;
}


int find(Teletype* contents, string name)
{
    int found = 0;

    while (contents != NULL)
    {
        if ((contents->name)._Equal(name))
        {
            found = 1;
            cout << endl << setw(30) << contents->name << setw(20) << contents->phoneno;
            break;
        }
        else
            contents = contents->nexaddr;
        cout << endl;
    }
    cout << endl;
    return found;
}

void populate(Teletype* record) {
    cout << "Enter a name: ";
    getline(cin, record->name);
    cout << "Enter the phone number: ";
    getline(cin, record->phoneno);
    return;
}

int check(Teletype* addr) {
    if (addr == NULL)
        return 0;
    else
        return 1;
}

void deleteLinkedList(Teletype* list) {
    while (list != NULL) {
        Teletype* nextRecord = list->nexaddr;
        delete list;
        list = nextRecord;
    }
}

void insert(Teletype*& list, int position) {
    if (position <= 0) {
        cout << "Invalid insertion position." << endl;
        return;
    }

    Teletype* newRecord = new Teletype;
    if (!check(newRecord)) {
        cout << "Insufficient memory";
        exit(0);
    }
    populate(newRecord);

    if (position == 1) {
        newRecord->nexaddr = list;
        list = newRecord;
    }
    else {
        Teletype* current = list;
        int count = 1;
        while (current != NULL && count < position - 1) {
            current = current->nexaddr;
            count++;
        }

        newRecord->nexaddr = current->nexaddr;
        current->nexaddr = newRecord;
    }

    cout << "Record inserted at position " << position << "." << endl;
}

void modify(Teletype*& list, string name) {
    Teletype* current = list;
    while (current != NULL) {
        if (current->name == name) {
            populate(current);
            return;
        }
        current = current->nexaddr;
    }
    cout << "Record not in data set." << endl;
    return;
}

void remove(Teletype*& list, int position) {
    if (position <= 0) {
        cout << "Invalid deletion position." << endl;
        return;
    }

    if (list == NULL) {
        cout << "List is empty. Cannot remove." << endl;
        return;
    }

    if (position == 1) {
        Teletype* toDelete = list;
        list = list->nexaddr;
        delete toDelete;
        cout << "Record at position " << position << " deleted." << endl;
    }
    else {
        Teletype* current = list;
        int count = 1;
        while (current != NULL && count < position - 1) {
            current = current->nexaddr;
            count++;
        }

        if (current == NULL || current->nexaddr == NULL) {
            cout << "Invalid deletion position." << endl;
            return;
        }

        Teletype* toDelete = current->nexaddr;
        current->nexaddr = toDelete->nexaddr;
        delete toDelete;
        cout << "Record at position " << position << " deleted." << endl;
    }
}


int main() {
    char c;
    int choice, i, count = 0;
    string name;
    Teletype* list = NULL, * current = NULL;


    do {
        cout << "MENU" << endl;
        cout << "1. Create a linked list" << endl;
        cout << "2. Insert a new structure in the linked list" << endl;
        cout << "3. Modify an existing structure in the linked list" << endl;
        cout << "4. Delete an existing structure from the list" << endl;
        cout << "5. Find an existing structure" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            deleteLinkedList(list);
            list = new Teletype;
            if (!check(list)) {
                cout << "Insufficient memory";
                exit(0);
            }
            current = list;
            do {
                populate(current);
                current->nexaddr = new Teletype;
                if (!check(current->nexaddr)) {
                    cout << "Insufficient memory";
                    exit(0);
                }
                current = current->nexaddr;
                current->nexaddr = NULL;
                cout << "Would you like to input more data? y/n ?: ";
                cin >> c;
                cin.ignore();
            } while (c != 'n');

            display(list);
            break;
        }
        case 2: {
            cout << "Insert a record after records 1, 2, 3...\n";
            cin >> i;
            cin.ignore();
            insert(list, i);
            display(list);
            break;
        }
        case 3: {
            cout << "Enter the name you want to modify: ";
            getline(cin, name);
            modify(list, name);
            display(list);
            break;
        }
        case 4: {
            cout << "Delete a record after records 1, 2, 3...\n";
            cin >> i;
            cin.ignore();
            remove(list, i);
            display(list);
            break;
        }
        case 5: {
            cout << "Enter the name you want to find: ";
            getline(cin, name);
            if (!find(list, name))
                cout << "The names is not in the list." << endl;
            break;
        }
        case 6: {
            deleteLinkedList(list);
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
        }
        cout << endl;
    } while (choice != 6);

    system("pause");
    return 0;
}
