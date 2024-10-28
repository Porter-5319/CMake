#ifndef GEOFIGURE_H
#define GEOFIGURE_H

#include "GridExport.h"

#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class GeoLine;
class GeoFace;

class GRID_API GeoUtils
{
public:
    bool isIntersection(const GeoLine &_line, const GeoFace &_face);
};

class GeoLine
{
public:
    GeoLine();
    GeoLine(const Vector3d &_start, const Vector3d &_end);

    const Vector3d &start() const;
    const Vector3d &end() const;

private:
    Vector3d     m_Start;           // 线段的起点
    Vector3d     m_End;             // 线段的终点
    Vector3d     m_Direction;       // 线段的方向向量
};


class GRID_API GeoFace
{
public:
    GeoFace();
    GeoFace(const vector<Vector3d> &_positions);

    const Vector3d &normal() const;
    const Vector3d &position(int index) const;

private:
    void caculateNormal();
private:
    Vector3d                   m_Normal;      // 面的法线
    vector<Vector3d>           m_VecPosition; // 面的顶点
};

#endif // GEOFIGURE_H
