#include <iostream>

int main()
{
    FILE *f;
    try {
        if ((f = fopen("filename", "w")) == nullptr)
            throw "Not found\n";
        // Тут код, при котором может быть выброшено исключение
    }
    catch (const char *err) {
        std::cerr<<err;
        return -1;
    }
    fclose(f);
    return 0;
}


