#include "modAlphaCipher.h"

using namespace std;

bool isValid(const wstring& s)
{
    for(const auto &c:s)
        if (!iswalpha(c))
            return false;
    return true;
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    unsigned op;
    cout<<"Введите ключ: ";
    wcin>>key;
    if (!wcin.good()) {
        wcerr<<"Неверный ключ\n";
        return 1;
    }
    modAlphaCipher cipher(key);
    do {
        wcout<<L"(0-vihod, 1-sh, 2-rsh): ";
        wcin>>op;
        if (op > 2) {
            wcout<<L"oshibka\n";
        } else if (op >0) {
            wcout<<L"Input text: ";
            wcin>>text;
            if (isValid(text)) {
                if (op == 1) {
                    wcout<<L"encrypt text: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<L"decrypt text: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"oshibka\n";
            }
        }
    } while (op != 0);
    
    return 0;
}
