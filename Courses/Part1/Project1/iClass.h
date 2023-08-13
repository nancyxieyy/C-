#ifndef ICLASS_H
#define ICLASS_H
using namespace std;

class iClass
{
private:
    int* pints;
    int length;
public:
    //(1)
    iClass(int len);
    //(2)
    ~iClass();
    //(3)
    void print() const;
    //(4)
    int count_of(int i) const;
};

#endif //ICLASS_H