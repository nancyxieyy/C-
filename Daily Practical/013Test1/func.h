#ifndef FUNC_H
#define FUNC_H
using namespace std;

class Cube {
private:
    int ma;//长
    int mb;//宽
    int mc;//高

public:
    //成员函数
    void cubeInit(void) {
        cout<<"请分别输入立方体的长宽高：";
        cin>>ma>>mb>>mc;
    }
    int getArea(void) {
        //获得立方体面积
        return (2*ma*mb + 2*ma*mc + 2*mb*mc);
    }

    int getVolume(void) {
        //获得立方体体积
        return (ma * mb * mc);
    }
};

#endif //FUNC_H