#include "Grid.h"

namespace GG {

Grid::Grid()
    :m_GridLayer(0)
    ,m_GridId(0)
    ,m_Length(0)
    ,m_Width(0)
    ,m_Height(0)
    ,m_Centor(){

}

Grid::Grid(unsigned char _gridLayer, unsigned long long _gridId, double _size, const Vec3d &_vec)
    :m_GridLayer(_gridLayer)
    ,m_GridId(_gridId)
    ,m_Length(_size)
    ,m_Width(_size)
    ,m_Height(_size)
    ,m_Centor(_vec){

}

Grid::Grid(unsigned char _gridLayer, unsigned long long _gridId, const Vec3d &_size, const Vec3d &_vec)
    :m_GridLayer(_gridLayer)
    ,m_GridId(_gridId)
    ,m_Length(_size.X)
    ,m_Width(_size.Y)
    ,m_Height(_size.Z)
    ,m_Centor(_vec){

}

void Grid::setGridLayer(unsigned char _layer)
{
    m_GridLayer = _layer;
}

unsigned char Grid::getGridLayer() const
{
    return m_GridLayer;
}

void Grid::setGridId(unsigned long long _id)
{
    m_GridId = _id;
}
unsigned long long Grid::getGridId() const
{
    return m_GridId;
}

void Grid::setGridSize(double _value)
{
    m_Length = m_Width = m_Height = _value;
}

double Grid::getGridSize() const
{
    if(m_Length == m_Width == m_Height)
        return m_Length;
    else
        return -1;
}

void Grid::setGridSize(const Vec3d &_size)
{
    m_Length = _size.X;
    m_Width = _size.Y;
    m_Height = _size.Z;
}
Vec3d Grid::getGridSizeVec3d() const
{
    return Vec3d(m_Length,m_Width,m_Height);
}

}
