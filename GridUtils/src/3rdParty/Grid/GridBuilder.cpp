#include "GridBuilder.h"
#include "Grid.h"

namespace GG {

GridBuilder::GridBuilder() {}

GG::Grid *GG::GridBuilder::createGrid(unsigned char _gridLayer, const Vec3d &_vec)
{
    Grid *grid = new Grid();
    return grid;
}

Grid *GridBuilder::createGrid(unsigned long long _gridId, unsigned char _gridLayer)
{
    // 通过网格编码和网格的层级计算网格的中心位置
    double lon, lat, alt = 0;
    // GridCenterCoordinate(_gridId,_gridLayer,lat,lon);

    // 将经纬度转为世界坐标
    return nullptr;

}

}
