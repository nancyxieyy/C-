#ifndef HEADER_H
#define HEADER_H
using namespace std;

#define InitSize 10
#define IncSize 5

template <typename T>
class SeqList {
public:
    SeqList (int length = InitSize);
    ~SeqList();
public:
    bool ListInsert(int i, const T& e);
    bool ListDelete(int i);
    bool GetElem(int i, T& e);

private:
    T *data;
    int mlength;
    int maxsize;
};

#endif //HEADER_H