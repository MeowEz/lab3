#include <iostream>

using namespace std;
int mas[10][10];
int mas_max[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            mas[i][j] = rand() % 10;
            cout << mas[i][j] << ' ';
        };
        cout << endl;
    }
    cout << "Max (Line)" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
        asm(
            ".intel_syntax noprefix \n"
            "mov eax,%1\n"
            "mov ebx,%2\n"
            "cmp eax,ebx\n"
            "ja big_1\n"
            "jb small_1\n"
            "big_1:\n" 
            "mov %0,eax\n" 
            "jmp fl_1\n"
            "small_1:\n"
            "mov %0, ebx\n"
            "fl_1:\n" 
            ".att_syntax\n"
            : "=r" (mas_max[i])
            : "r" (mas_max[i]), "r" (mas[i][j])
            : "eax", "ebx" 
        );  
        };
        cout << mas_max[i] << ' ';
    }
    for (int i = 0; i < 10; i++) mas_max[i] = 0; 
    cout << endl << "Max (Column)" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
        asm(
            ".intel_syntax noprefix \n"
            "mov eax,%1\n"
            "mov ebx,%2\n"
            "cmp eax,ebx\n"
            "ja big_2\n"
            "jb small_2\n"
            "big_2:\n" 
            "mov %0,eax\n" 
            "jmp fl_2\n"
            "small_2:\n"
            "mov %0, ebx\n"
            "fl_2:\n" 
            ".att_syntax\n"
            : "=r" (mas_max[i])
            : "r" (mas_max[i]), "r" (mas[j][i])
            : "eax", "ebx" 
        );  
        };
        cout << mas_max[i] << ' ';
    }
cout << endl;
}
