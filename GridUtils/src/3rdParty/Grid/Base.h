#ifndef BASE_H
#define BASE_H

#include "GridExport.h"

#include <math.h>

namespace GG {
class GRID_API Vec3d
{
public:

    explicit Vec3d():X(0),Y(0),Z(0){}

    explicit Vec3d(double _X, double _Y, double _Z)
        :X(_X),Y(_Y),Z(_Z){}

    explicit Vec3d(const Vec3d& _vec)
        :X(_vec.X),Y(_vec.Y),Z(_vec.Z){}

    /**
     * @brief length 计算向量的长度
     * @return
     */
    double length(){
        return sqrt(X * X + Y * Y + Z * Z);
    }

    /**
     * @brief 重载拷贝赋值
     */
    Vec3d& operator=(const Vec3d& _other){
        if(this == &_other)
            return *this;
        X = _other.X;
        Y = _other.Y;
        Z = _other.Z;
        return *this;
    }

    /**
     * @brief 重载 -
     */
    Vec3d operator-(const Vec3d &_other) const{
        return Vec3d(X-_other.X,Y-_other.Y,Z-_other.Z);
    }

public:
    double X;
    double Y;
    double Z;
};

class GRID_API ObjectBase
{
public:
    explicit ObjectBase(const Vec3d &_pos,const Vec3d &_ori)
        :m_Position(_pos),m_Orientation(_ori){}

    explicit ObjectBase(const ObjectBase& _obj)
        :m_Position(_obj.m_Position)
        ,m_Orientation(_obj.m_Orientation){}

    /**
     * @brief getPosition 获取对象在空间的位置
     * @return 返回的位置
     */
    const Vec3d& getPosition() const {
        return m_Position;
    }

    /**
     * @brief setPosition 指定对象在空间的位置
     * @param[in] _pos 需要指定到的位置
     */
    void setPosition(const Vec3d &_pos){
        m_Position = _pos;
    }

    /**
     * @brief getOrientation 获取对象在空间的态势(俯仰、偏航、滚转)
     * @return 返回的态势
     */
    const Vec3d& getOrientation() const {
        return m_Orientation;
    }

    /**
     * @brief setOrientation 指定对象在空间的态势(俯仰、偏航、滚转)
     * @param _pos 需要指定的位置
     */
    void setOrientation(const Vec3d &_pos){
        m_Orientation = _pos;
    }

protected:
    Vec3d m_Position;
    Vec3d m_Orientation;
};

}

#endif // BASE_H
