//
// Created by yoda45 on 01-03-2018.
//

#ifndef SPAAACE_CG_Point_H
#define SPAAACE_CG_Point_H


class Point {
    public:
        Point();
        Point(float x, float y, float z);
        float getX();
        float getY();
        float getZ();
    virtual ~Point(){}

    void setX(float x);

    void setY(float y);

    void setZ(float z);;
    private:
        float x;
        float y;
        float z;
};


#endif //SPAAACE_CG_Point_H
