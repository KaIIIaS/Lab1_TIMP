#include "modAlphaCipher.h"

wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    wstring new_text = cipher_text;
    int length, position, line, index;
    length = cipher_text.size();
    line = (length - 1) / newkey + 1;
    index = 0;
    for (int column_number = newkey; column_number > 0; column_number--) {
        for (int line_number = 0; line_number < line; line_number++) {
            position = newkey*line_number+column_number;
            if (position-1 < length) {
                new_text[position-1] = cipher_text[index];
                index++;
            }
        }
    }
    return new_text;
}

wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    wstring new_text = open_text;
    int length, line, position, index;
    length = open_text.size();
    line = (length - 1) / newkey + 1;
    index = 0;
    for (int column_number = newkey; column_number > 0; column_number--) {
        for (int line_number = 0; line_number < line; line_number++) {
            position = column_number + newkey * line_number;
            if (position-1 < length) {
                new_text[index] = open_text[position-1];
                index++;
            }
        }
    }
    return new_text;
}
