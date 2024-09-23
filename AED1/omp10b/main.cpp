#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

string code = "BUSPFTM";

int glyphs2int(string str) {
    if (code.find(str[0]) > code.find(str[str.length()-1]))
        reverse(str.begin(), str.end());

    int prevcodeidx = -1;
    int repcount = 1;
    int num = 0;
    for (char c : str) {
        // find index
        int codeidx = code.find(c);
        // check errors
        if (codeidx < prevcodeidx) return -1;
        else if (codeidx == prevcodeidx) repcount++;
        if (repcount > 9) return -1;
        // convert
        num += (int)pow(10, codeidx);

        prevcodeidx = codeidx;
    }
    return num;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string glyphs;
        cin >> glyphs;

        cout << glyphs2int(glyphs) << endl;
    }
}
