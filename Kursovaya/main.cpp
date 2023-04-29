#include <iostream>
#include <cstring>
//пространство имён
using namespace std;

//классы
//реализация файлов по фалйам C++, остальное в файлы загловка
//базовый класс строка
class stroka //заголовок, приватный
{
//спецификатор доступа
public:
    stroka(int = 0);

    stroka(char);

    stroka(const char *);

    stroka(const stroka &); //последний символ в строке нулевой
    stroka(); //my
    ~stroka(); //деструктор
    char *GetStr(void) const {
        return pCh;
    }

    int GetLen(void) const {
        return len;
    }

    void show(void); //если другие конструкторы, если меньше, то так, если в тз больше, то доопределять.
//добавить из ТЗ
    int len;
    char *pCh;
};

stroka::stroka(int val) : len(val), pCh(new char[len + 1]) {
    if (val == 0) pCh[0] = '\0';
    cout << "stroka::stroka(int val)" << endl;
}

stroka::stroka(char ch) : len(1), pCh(new char[len + 1]) //1 symbol
{
    pCh[0] = ch;
    pCh[1] = '\0';
    cout << "stroka::stroka(char ch)" << endl;
}

stroka::~stroka() {
    if (pCh) delete[]pCh;
    cout << "stroka::~stroka()" << endl;
}

void stroka::show(void) {
    cout << "pCh = " << pCh << endl;
    cout << "len = " << len << endl;
}

stroka::stroka(const char *s) : len(strlen(s)), pCh(new char[len + 1]) {
    strcpy_s(pCh, len + 1, s);
    //strcpy(pCh, s);
    cout << "stroka::stroka(const char* s)" << endl;
}

stroka::stroka(const stroka &from) : len(strlen(from.pCh)), pCh(new char[from.len + 1]) {
    strcpy_s(pCh, len + 1, from.pCh);
    cout << "stroka::stroka(const stroka& from)" << endl;
}

stroka::stroka() //my
{
    len = 0;
    pCh = new char[len + 1];
    pCh[0] = '\n';
    cout << "stroka::stroka()" << endl;
}

class IdentStr : public stroka { //объявить спецификатор защищенный protected
public:
    IdentStr(int = 0); //конструкторы
    IdentStr(char);

    IdentStr(const char *);

    IdentStr(const IdentStr &);

    ~IdentStr();

    IdentStr &operator=(const IdentStr &);

    char &operator[](int);

    IdentStr operator~();

    friend IdentStr operator+(const IdentStr &, const IdentStr &); //obj1 + obj2
    friend IdentStr operator+(const IdentStr &, const char *); //obj + char
    friend IdentStr operator+(const char *, const IdentStr &); //char + obj
    friend IdentStr operator-(const IdentStr &, const IdentStr &); //my
    //добавить из тз переопредление!!!!!!!
};

IdentStr::IdentStr(int val) : stroka(val) {
    cout << "IdentStr::IdentStr(int val):stroka(val), val = " << val << endl;
}

//символы - буквы или подчеркивание
IdentStr::IdentStr(char ch) : stroka(ch) {
    //a-z, A-Z, '_'
    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_'))) {
        cout << "Bad simvol, pCh[0] = " << pCh[0] << endl;
        if (pCh)delete[]pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    cout << "IdentStr::IdentStr(char ch)" << endl;
}

IdentStr::IdentStr(const char *Str) : stroka(Str) {
    const char *keyword[] = {"while", "for", "switch", "break"}; //дописать все ключевые слова
    //проверка 1-го симвлоа, может быть только буква или подчеркивание, если хороший, то проверить остальные символы, буквы. буквы-цифры, подчеркивание, если хорошо, то вывести, что отработал
    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_'))) {
        cout << "Bad simvol, pCh[0] = " << pCh[0] << endl;
        if (pCh)delete[]pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') ||
              (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_'))) {
            cout << "Bad simvol, pCh[" << i << "]=" << pCh[i] << endl;
            if (pCh)delete[]pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (strcmp(pCh, keyword[i]) == 0) {
            cout << "Bad word" << pCh[i] << endl;
            if (pCh)delete[]pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "IdentStr::IdentStr(const char* Str)" << endl;
    //массив указателей на ключевые слова
}

IdentStr::IdentStr(const IdentStr &from) : stroka(from) {
    cout << "IdentStr::IdentStr(const IdentStr& from) :stroka(from)" << endl;
}

IdentStr::~IdentStr() {
    cout << "IdentStr::~IdentStr()" << endl;
}

IdentStr &IdentStr::operator=(const IdentStr &s) {
    if (&s != this) {
        delete[]pCh;
        len = strlen(s.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, s.pCh);

    }
    cout << "IdentStr& IdentStr::operator=(const IdentStr& s)" << endl;
    return *this;
}

char &IdentStr::operator[](int index) {
    if (index >= 0 && index < len) {
        cout << "char&IdentStr::operator[](int index)" << endl;
        return pCh[index];
    }
    return pCh[0];
}

IdentStr IdentStr::operator~() {
    int i, j;
    char tmp;
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        tmp = pCh[i];
        pCh[i] = pCh[j];
        pCh[j] = tmp;
    } //учесть первый символ, в случае, если первый символ цифра - пустая строка
    cout << "IdentStr IdentStr::operator~()" << endl;
    return *this;
}

IdentStr operator+(const IdentStr &pobj1, const IdentStr &pobj2) {
    IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    i--;
    j = 0;
    while (tmp.pCh[i++] = pobj2.pCh[j++]);
    cout << "IdentStr operator + (const IdentStr& pobj1, const IdentStr& pobj2)" << endl;
    return tmp;
}

IdentStr operator+(const IdentStr &pobj1, const char *obj2) {
    IdentStr tmp1(obj2);
    int i = 0, j = 0;
    IdentStr tmp(pobj1.GetLen() + tmp1.GetLen());
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    i--;
    j = 0;
    while (tmp.pCh[i++] = obj2[j++]);
    cout << "IdentStr operator+(const IdentStr& pobj1, const char* obj2)" << endl;
    return tmp;
}

IdentStr operator+(const char *obj2, const IdentStr &pobj1) {
    IdentStr tmp1(obj2);
    int i = 0, j = 0;
    IdentStr tmp(pobj1.GetLen() + tmp1.GetLen());
    while (tmp.pCh[i++] = obj2[j++]);
    i--;
    j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    cout << "IdentStr operator+(const IdentStr& pobj1, const char* obj2)" << endl;
    return tmp;
}

IdentStr operator-(const IdentStr &obj, const IdentStr &obj2) {
    IdentStr tmp1(obj);
    IdentStr tmp2(obj2);
    int i = -1, j = 0, count = tmp1.GetLen(), l = 0;
    while (j++ <= tmp1.GetLen()) {
        while (i++ <= tmp2.GetLen()) {
            if (tmp1[i] == tmp2[j]) {
                for (int l = i; l < tmp1.GetLen(); l++)
                    tmp1[l] = tmp1[l + 1];
                tmp1[tmp1.GetLen() - 1] = '\0';
            }
        }
        i = 0;
    }
    return tmp1;
}

class DecStr : public stroka {
public:
    DecStr(int = 0);

    //DecStr(char)
    DecStr(const char *);

    DecStr(const DecStr &);

    ~DecStr();

    DecStr &operator=(const DecStr &);

    friend DecStr operator+(const DecStr &, const DecStr &); //
    //friend DecStr operator+(const DecStr&, const int);
    //friend DecStr operator-(const DecStr&, const DecStr&);
};

DecStr::DecStr(int val) : stroka(val) {
    cout << "DecStr::DecStr(int val):stroka(val), val =" << val << endl;
}

DecStr::DecStr(const char *str) : stroka(str) {
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || (pCh[0] == '-' || pCh[0] == '+'))) {
        cout << "Bad simvol, pCh[0]=" << pCh[0] << endl;
        if (pCh)delete[]pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    if (pCh[0] == '+' || pCh[0] == '-') {
        if (pCh[1] <= '0' || pCh[1] > '9') {
            cout << "Bad simvol, pCh[1]=" << pCh[1] << endl;
            if (pCh)delete[]pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
        for (int i = 2; i < len; i++) {
            if (!(pCh[i] >= '0' && pCh[i] <= '9')) {
                cout << "Bad simvol, pCh[" << i << "]=" << pCh[i] << endl;
                if (pCh)delete[]pCh;
                len = 0;
                pCh = new char[len + 1];
                pCh[0] = '\0';
                return;
            } else
                cout << "DecStr::DecStr(const char* str) :stroka(str)" << endl;
        }
    }
    for (int i = 1; i < len; i++) {
        if (!(pCh[i] >= '0' && pCh[i] <= '9')) {
            cout << "Bad simvol, pCh[" << i << "]=" << pCh[i] << endl;
            if (pCh)delete[]pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        } else
            cout << "DecStr::DecStr(const char* str) :stroka(str)" << endl;
    }
}

DecStr::DecStr(const DecStr &from) : stroka(from) {
    cout << "DecStr::DecStr(const DecStr& from) : Stroka(from)" << endl;
}

DecStr::~DecStr() {
    cout << "DecStr::~DecStr()" << endl;
}

DecStr &DecStr::operator=(const DecStr &Ds) {
    if (&Ds != this) {
        delete[]pCh;
        len = strlen(Ds.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, Ds.pCh);
    }
    cout << "DecStr::operator::operator = (const DecStr Ds)" << endl;
    return *this;
}

DecStr operator+(const DecStr &pobj1, const DecStr &pobj2) {
    DecStr tmp(pobj1);
    int num1, num2;
    char *pChTmp;
    num1 = atoi(tmp.GetStr());
    num2 = atoi(pobj2.GetStr());
    int A = num1 + num2;
    if (tmp.len >= pobj2.len) {
        pChTmp = new char[tmp.len + 2];
    } else
        pChTmp = new char[pobj2.len + 2];

    _itoa_s(A, pChTmp, tmp.len + 2, 10);

    if (tmp.pCh) delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);

    cout << "DecStr operator +(const DecStr & pobj1, const DecStr & pobj2)" << endl;
    return tmp;
}

DecStr operator+(const DecStr &pobj1, int a) {
    DecStr tmp(pobj1);
    int num1, num2;
    char *pChTmp;
    num1 = atoi(tmp.GetStr());
    num2 = a;
    cout << a << endl;
    if (num1 > 0 && a > 0 && (INT_MAX - a < num1) ||
        num1 < 0 && a < 0 && (INT_MIN - a > num1)) {
        if (tmp.pCh) delete[] tmp.pCh;
        tmp.len = 0;
        tmp.pCh = new char[tmp.len + 1];
        tmp.pCh[0] = '\0';
        cout << "Overflow-\n";
        return tmp;
    }
    int A = num1 + num2;
    cout << A << endl;
    pChTmp = new char[pobj1.len + 12];
    _itoa_s(A, pChTmp, tmp.len + 12, 10);
    if (tmp.pCh) delete[] tmp.pCh;
    tmp.pCh = pChTmp;
    tmp.len = strlen(pChTmp);
    cout << "DecStr operator +(const DecStr & pobj1, const DecStr & pobj2)" << endl;
    return tmp;
}


int main() {
//    stroka obj('F');
//    obj.show();
//    cout << obj.GetStr() << endl;
//    stroka obj2("ITMO");
//    obj2.show();
//    stroka obj3 = obj2;
//    obj3.show();
//    IdentStr obj7("FBI;T");
//    obj7.show();
//    IdentStr obj8("9FBIT");
//    obj8.show();
//    IdentStr obj9('3');
//    obj9.show();
//    IdentStr obj10("while");
//    obj10.show();
//    IdentStr obj20("ITMO");
//    IdentStr obj21("FBIT");
//    obj20 = obj21;
//    obj20.show();
//    obj21 = "5PBKS";
//    obj21.show();
//    obj20[1] = 'X';
//    obj20.show();
//    char m = obj20[1];
//    cout << "m = " << m << endl;
//    ~obj20;
//    obj20.show();
//    obj20 = obj20 + obj20;
//    obj20.show();
//
//    obj20 = obj20 + "HIHIHAHA";
//    obj20.show();
//    obj20 = "HIHIHAHA" + obj20;
//    obj20.show();
//
//    DecStr obj19("65535");
//    obj19.show();
//    DecStr obj22("+1024");
//    obj22.show();
//    DecStr obj23("0255");
//    obj23.show();
    //DecStr obj24("-25+5");
    //obj24.show();
    //DecStr obj25("-0255");
    //obj25.show();
//    DecStr obj26("1024");
//    obj26 = "65535";
//    obj26.show();
//    obj26 = "01024";
//    obj26.show();
    DecStr obj27("1024");
    DecStr obj28("1024");
//    obj28 = obj27 + obj28;
//    obj28.show();

//    obj28 = obj28 + 1024;
//    obj28.show();
    obj28 = obj27 + (2147483);
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    obj28.show();
    //проверку в реверсе на последнюю цифру
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
