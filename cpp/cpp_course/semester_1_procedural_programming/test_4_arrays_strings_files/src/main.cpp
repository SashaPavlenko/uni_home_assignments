#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string filename;
    cout << "Enter name of file in resource directory: ";
    cin >> filename;
    //filename = "Resource\\" + filename;
    ifstream file(filename);

    double x = 0, y = 0, z = 0;
    int red = 0, green = 0, blue = 0;
    

    //each row start with a "#"
    while (!file.eof())
    {
        file >> x >> y >> z >> red >> green >> blue;
        cout << " " << x << " " << y << " " << z << " " << red << " " << green\
            << " " << blue << endl;
    }

    file.close();

    return 0;
}