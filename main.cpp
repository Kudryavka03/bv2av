
#include <iostream>
#include <string>
#include <cmath>
#include <map> 
using namespace std;
string table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
map <long, long> tr;
long s[] = { 11,10,3,8,4,6 };
long  long xor1 = 177451812;
long long add1 = 8728348608;
string dec(string x1) {
    long long r = 0;
    for (int a = 0; a < 6; a++) {
        r += tr[x1[s[a]]] * pow(58, a);
    }
    return to_string(((long long)r - (long long)add1) ^ xor1);
}
string enc (long long  x1) {
    x1 = (x1 ^ xor1) + add1;
    char r[] = "BV1  4 1 7  ";
    for (int i = 0; i < 6; i++)
    {
        r[s[i]] = table[(int)(x1 / (long long)pow(58, i) % 58)];
    }
    string rstring = "";
    int r1 = sizeof(r);
    for (int j = 0; j <r1; j++)
    {
        rstring += r[j];
    }
    return rstring;
}
int main()
{
    int bh1;
    for (int i = 0; i < 58; i++) {
        tr[table[i]] = i;
    }
    for (;;) {
        cout << "请输入你要执行的功能编号(1:BV转AV，2:AV转BV):";
        cin >> bh1;
        if (bh1 == 1) {
            for (;;) {
                cout << "请输入您要转换程成AV号的BV号(带BV字段，q退回选择菜单):";
                string a;
                cin >> a;
                if (a == "q") {
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n==============生成AV号====================\n转换结果:av" << dec(a) << "\n==========================================\n\n";
                }

            }
        }
        if (bh1 == 2) {
            for (;;) {
                cout << "请输入您要转换程成BV号的AV号(不带AV字段，q退回选择菜单):";
                string a;
                cin >> a;
                if (a=="q") {
                    cout << "\n";
                    break;
                }
                else {
                    cout << "\n==============生成BV号====================\n转换结果:" << enc(stoll(a)) << "\n==========================================\n\n";
                }

            }
        }
    }
}
