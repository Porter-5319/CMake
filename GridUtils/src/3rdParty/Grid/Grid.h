#ifndef GRID_H
#define GRID_H

#include "GridExport.h"
#include "Base.h"

namespace GG {

class GRID_API Grid
{
public:
    Grid();
    Grid(unsigned char _gridLayer, unsigned long long _gridId, double _size, const Vec3d &_vec);
    Grid(unsigned char _gridLayer, unsigned long long _gridId, const Vec3d &_size, const Vec3d &_vec);

    /**
     * @brief setGridLayer 设置网格层级
     * @brief getGridLayer 获取网格层级
     */
    void setGridLayer(unsigned char _layer);
    unsigned char getGridLayer() const;

    /**
     * @brief setGridId 设置网格编码
     * @brief getGridId 获取网格编码
     */
    void setGridId(unsigned long long _id);
    unsigned long long getGridId() const;

    /**
     * @brief setGridSize 设置网格大小 默认网格是立方体
     * @brief getGridSize 获取网格大小 默认网格是立方体
     */
    void setGridSize(double _value);
    double getGridSize() const;

    /**
     * @brief setGridSize 设置网格大小 如何不是立方体可以使用此接口
     * @brief getGridSizeVec3d 获取网格大小
     */
    void setGridSize(const Vec3d &_size);
    Vec3d getGridSizeVec3d() const;

    /**
     * @brief setLength // 设置网格的长度
     * @brief getLength // 获取网格的长度
     */
    void setLength(double _value);
    double getLength() const;

    /**
     * @brief setWidgth // 设置网格的宽度
     * @brief getWidgth // 获取网格的宽度
     */
    void setWidgth(double _value);
    double getWidgth() const;

    /**
     * @brief setHeight // 设置网格的宽度
     * @brief getHeight // 获取网格的高度
     */
    void setHeight(double _value);
    double getHeight() const;

    /**
     * @brief setGridCentor // 设置网格的中心位置
     * @brief getGridCentor // 获取网格的中心位置
     */
    void setGridCentor(const Vec3d &_size);
    const Vec3d& getGridCentor() const;

private:
    unsigned char       m_GridLayer;        //@ 网格层级
    unsigned long long  m_GridId;           //@ 网格id
    double              m_Length;           //@ 网格长度
    double              m_Width;            //@ 网格宽度
    double              m_Height;           //@ 网格高度
    Vec3d               m_Centor;           //@ 网格的中心位置
};

}

#endif // GRID_H
