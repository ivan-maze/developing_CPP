#include <iostream>
#include <cstring> // for strcpy or strncpy
using namespace std;

class DataTypes {
    public: 
        DataTypes(char *s = "", int i = 0, double d = 1) {
            strncpy(dataMember1, s, sizeof(dataMember1));
            dataMember1[sizeof(dataMember1) - 1] = '\0'; // Null-terminate just in case
            dataMember2 = i;
            dataMember3 = d;
        }

        void functionMember1() {
            cout << dataMember1 << "" << dataMember2 << "" << dataMember3 << endl;
        }

        void functionMember2(int i, char *s = "unknown") {
            dataMember2 = i;
            cout << i << "received from" << s << endl;
        }
    protected:
        char dataMember1[20];
        int dataMember2;
        double dataMember3;

};

DataTypes object1("object1", 100, 200), object2("object2"), object3;