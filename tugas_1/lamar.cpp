#include <iostream>
#include <string>

class Contact {
public:
    Contact() : nama(""), alamat(""), telfon(""), kekuatan("") {} // konstruktor default
    Contact(const std::string& Nama, const std::string& Alamat, const std::string& Telfon, const std::string& Kekuatan) 
        : nama(Nama), alamat(Alamat), telfon(Telfon), kekuatan(Kekuatan) {}

    const std::string& getName() const { return nama; }
    const std::string& getAddress() const { return alamat; }
    const std::string& getElement() const { return telfon; }
    const std::string& getStrength() const { return kekuatan; }

    void display() const {
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Alamat: " << alamat << std::endl;
        std::cout << "Telfon: " << telfon << std::endl;
        std::cout << "Kekuatan: " << kekuatan << std::endl;
    }

private:
    std::string nama;
    std::string alamat;
    std::string telfon;
    std::string kekuatan; // Tambahkan atribut kekuatan
};

class PhoneBook {
public:
    void addContact(const Contact& contact) {
        if (contactCount < 8) {
            contacts[contactCount++] = contact;
        } else {
            for (int i = 0; i < 7; i++) {
                contacts[i] = contacts[i + 1];
            }
            contacts[7] = contact;
        }
    }

    void displayAllContacts() const {
        if (contactCount == 0) {
            std::cout << "PhoneBook kosong." << std::endl;
            return;
        }

        std::cout << "Contacts:" << std::endl;
        for (int i = 0; i < contactCount; i++) {
            std::cout << i + 1 << ". " << contacts[i].getName() << std::endl;
        }
    }

    void displayContactDetails(int index) const {
        if (index < 1 || index > contactCount) {
            std::cout << "Invalid index." << std::endl;
            return;
        }

        contacts[index - 1].display();
    }

private:
    Contact contacts[8];
    int contactCount = 0;
};

int main() {
    PhoneBook phoneBook;
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3. Search Contact Details\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(100, '\n'); // bersihin buffer input

        switch (choice) {
        case 1: {
            std::string nama, alamat, telfon, kekuatan;
            std::cout << "Enter nama: ";
            std::getline(std::cin, nama);
            std::cout << "Enter alamat: ";
            std::getline(std::cin, alamat);
            std::cout << "Enter telfon: ";
            std::getline(std::cin, telfon);
            std::cout << "Enter kekuatan: ";
            std::getline(std::cin, kekuatan);
            phoneBook.addContact(Contact(nama, alamat, telfon, kekuatan));
            std::cout << "Contact added successfully." << std::endl;
            break;
        }
        case 2:
            phoneBook.displayAllContacts();
            break;
        case 3: {
            int index;
            std::cout << "Masukkan index contact: ";
            std::cin >> index;
            std::cin.ignore(100, '\n'); // bersihin buffer input
            phoneBook.displayContactDetails(index);
            break;
        }
        case 4:
            std::cout << "Closing program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
