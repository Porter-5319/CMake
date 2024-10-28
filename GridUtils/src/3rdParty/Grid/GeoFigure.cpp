#include "GeoFigure.h"
#include <assert.h>

GeoLine::GeoLine()
    :m_Start(),m_End(),m_Direction(){}

GeoLine::GeoLine(const Vector3d &_start, const Vector3d &_end)
    :m_Start(_start),m_End(_end),m_Direction(_end - _start)
{

}

const Vector3d &GeoLine::start() const
{
    return m_Start;
}

const Vector3d &GeoLine::end() const
{
    return m_End;
}

GeoFace::GeoFace()
    :m_Normal(),m_VecPosition()
{

}

GeoFace::GeoFace(const vector<Vector3d> &_positions)
    :m_Normal(),m_VecPosition(std::move(_positions))
{
    // 计算面的法向量
    caculateNormal();
}

const Vector3d &GeoFace::normal() const
{
    return m_Normal;
}

const Vector3d &GeoFace::position(int index) const
{
    // 确保数组不会越界
    assert(index < m_VecPosition.size());
    return m_VecPosition[index];
}

void GeoFace::caculateNormal()
{
    // 确保计算点的个数大于3个
    if(m_VecPosition.size() < 3)
        return;

    Vector3d v1 = m_VecPosition[1] -  m_VecPosition[0];
    Vector3d v2 = m_VecPosition[2] -  m_VecPosition[1];

    m_Normal = v1.cross(v2);
}

bool GeoUtils::isIntersection(const GeoLine &_line, const GeoFace &_face)
{
    // 面的法向量
    const Vector3d &normal = _face.normal();

    // 获取平面上的点
    const Vector3d &P0 = _face.position(0);

    // 获取线段的两个点
    const Vector3d &P1 = _line.start();
    const Vector3d &P2 = _line.end();

    // 计算向量
    const Vector3d &V1 = P0 - P1; // P1 -> P0
    const Vector3d &V2 = P2 - P1; // P1 -> P2

    // 计算向量点积
    double dotNormal1 = V1.dot(normal);
    double dotNormal2 = V2.dot(normal);

    // 判断线和面是否平行
    if (fabs(dotNormal2) < 1e-6) { // 平行或者点积为零时，向量之间几乎没有交点
        return false;
    }

    // 计算参数 t
    double t = dotNormal1 / dotNormal2;
    if (t < 0.0 || t > 1.0) {
        return false; // 没有交点或交点不在线段上
    }

    return true; // 目前还不能说明一定有交点
}
