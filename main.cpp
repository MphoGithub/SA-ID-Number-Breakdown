#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Identity
{
private:
    string idNumber;

public:
    Identity();
    void setIdNumber(const string& idNumberP);
    string getIdNumber() const;
    bool validateIDNumber(const string& idNumberP) const;
    void displayIdNumberBreakdown(const string& idNumberP) const;
};

// Constructor definition
Identity::Identity() {}

// Method to set ID number
void Identity::setIdNumber(const string& idNumberP)
{
    idNumber = idNumberP;
}

// Method to get ID number
string Identity::getIdNumber() const
{
    return idNumber;
}

// Method to validate ID number
bool Identity::validateIDNumber(const string& idNumberP) const
{
    if (idNumberP.length() != 13)
    {
        return false;
    }

    for (char ch : idNumberP)
    {
        if (!isdigit(ch))
            return false;
    }

    return true;
}

// Method to display ID number breakdown
void Identity::displayIdNumberBreakdown(const string& idNumberP) const
{
    string dateOfBirth = idNumberP.substr(0, 6);
    string gender = idNumberP.substr(6, 4);
    string citizenStatus = idNumberP.substr(10, 1);

    cout << dateOfBirth << ": " << "This is the date of birth of the ID holder" << endl;

    int genderNum = stoi(gender);
    if (genderNum >= 0000 && genderNum <= 4999)
    {
        cout << gender << ": " << "This number indicates that the ID holder is female" << endl;
    }
    else if (genderNum >= 5000 && genderNum <= 9999)
    {
        cout << gender << ": " << "This number indicates that the ID holder is male" << endl;
    }

    int citizenStatusNum = stoi(citizenStatus);
    if (citizenStatusNum == 0)
    {
        cout << citizenStatus << ": " << "The ID holder was born a SA Citizen" << endl;
    }
    else if (citizenStatusNum == 1)
    {
        cout << citizenStatus << ": " << "The ID holder is a permanent resident" << endl;
    }
}

int main()
{
    string idNumber;
    Identity identity;

    cout << "Welcome to the South African ID Number breakdown program" << endl;
    cout << endl;
    cout << "To use the program, you will have to enter a 13-digit South African ID number" << endl;
    cout << "The ID number will then be broken down to provide you with information about the following:" << endl;
    cout << "1. The Date of Birth of the person who the ID number belongs to" << endl;
    cout << "2. Their Gender" << endl;
    cout << "3. Their citizenship status" << endl;
    cout << endl;

    while (true)
    {
        cout << "Enter a South African 13-digit ID number:" << endl;
        cin >> idNumber;

        if (identity.validateIDNumber(idNumber))
        {
            identity.setIdNumber(idNumber);
            identity.displayIdNumberBreakdown(idNumber);
            break;
        }
        else
        {
            cout << "Invalid ID number. Please enter a valid 13-digit number." << endl;
        }
    }

    return 0;
}