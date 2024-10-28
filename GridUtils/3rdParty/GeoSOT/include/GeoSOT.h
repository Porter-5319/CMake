#ifndef GEOSOT_KD_WGF_GEOSOT_H
#define GEOSOT_KD_WGF_GEOSOT_H

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__) || defined( __MWERKS__)
#  if defined(GEOSOT2D_EXPORTS_STATIC)
#    define GEOSOT2D_EXPORT
#    define GEOSOT2D_EXPORT_C extern "C"
#  elif defined(GEOSOT2D_EXPORTS)
#    define GEOSOT2D_EXPORT      __declspec(dllexport)
#    define GEOSOT2D_EXPORT_C    extern "C"  __declspec(dllexport)
#  else
#    define GEOSOT2D_EXPORT      __declspec(dllimport)
#    define GEOSOT2D_EXPORT_C    extern "C" __declspec(dllimport)
#endif
#else
#    define GEOSOT2D_EXPORT __declspec(dllimport)
#    define GEOSOT2D_EXPORT_C    extern "C" __attribute__ ((visibility("default")))
#endif

#include <vector>
// #include <map>
// #include <unordered_map>

/**
 * 点编码
 * @param latitude      纬度
 * @param longitude     经度
 * @param layer         层级
 * @param geoId         网格码
 */
GEOSOT2D_EXPORT_C void PointGridIdentify(const double latitude, const double longitude, unsigned char &layer, unsigned long long &geoId);

/**
 * 网格经纬度范围
 * @param layer            层级
 * @param geoId            网格码
 * @param longitudeMin     网格经度范围最小值 单位度(°)
 * @param latitudeMin      网格纬度范围最小值 单位度(°)
 * @param longitudeMax     网格经度范围最大值 单位度(°)
 * @param latitudeMax      网格纬度范围最大值 单位度(°)
 * @author hxj
 * @date 2020.05.21 新算法
 */
GEOSOT2D_EXPORT_C void RectFromGridCode(unsigned char layer, unsigned long long geoId, double &longitudeMin, double &latitudeMin, double &longitudeMax, double &latitudeMax);

/**
 * 网格中心坐标
 * @param   geoID       网格码
 * @param   chLayer     层级
 * @param   dbBC        网格中心纬度
 * @param   dbLC        网格中心经度
 * @author  hxj
 * @date    2020.03.12
 */
GEOSOT2D_EXPORT_C void GridCenterCoordinate(unsigned long long geoID, unsigned char chLayer, double &dbBC, double &dbLC);

/**
 * 矩形网格码数组
 * @param leftTopLatitude          左上点纬度
 * @param leftTopLongitude         左上点经度
 * @param rightBottomLatitude      右下点纬度
 * @param rightBottomLongitude     右下点经度
 * @param layer                    层级
 * @param geoIdArr                 网格码数组
 * @param rowNum                   行数量
 * @param colNum                   列数量
 * @return 0 正常 -1 geoIdArr网格码数组太小
 */
GEOSOT2D_EXPORT_C int RectGridSelect_Array(double leftTopLatitude, double leftTopLongitude, double rightBottomLatitude, double rightBottomLongitude, unsigned char layer, unsigned long long geoIdArr[], int &rowNum, int &colNum);

/**
 * 线选择网格码
 * @param latitude0      点0纬度
 * @param longitude0     点0经度
 * @param latitude1      点1纬度
 * @param longitude1     点1经度
 * @param layer          层级
 * @param geoIdArr       网格码数组
 * @param num            网格码数组长度
 * @return 0 正常 -1 geoIdArr网格码数组太小
 */
GEOSOT2D_EXPORT_C int LineGridSelect_Array(double latitude0, double longitude0, double latitude1, double longitude1, unsigned char layer, unsigned long long geoIdArr[], int &num);

/**
 * 扇形
 * @param latitude   圆心纬度
 * @param longitude  圆心经度
 * @param radius     半径 单位 米 m
 * @param startRad   起始方位角 弧度制
 * @param endRad     终点方位角 弧度制
 * @param chLayer    层级
 * @param geoIdArr   网格编码数组
 * @param num        网格编码数组大小
 * @return 0 正常 -1 调整网格编码数组大小
 * @author hxj
 * @date 2022年3月2日
 */
GEOSOT2D_EXPORT_C int SectorGrids(double latitude, double longitude, double radius, double startRad, double endRad, unsigned char chLayer, unsigned long long geoIdArr[], int &num);

/**
 * 网格编码(多边形)
 * @param[in]      dbB          多边形点纬度数组
 * @param[in]      dbL          多边形点经度数组
 * @param[in]      pointNum     多边形点的数量
 * @param[in]      chLayer      网格编码层级
 * @param[out]     geoIdArr     网格码数组
 * @param[in,out]  num          in:传入网格码数组的大小 out:生成网格码数量
 * @return 0 编码成功 -1 num太小，根据更改后的num调整geoIdArr大小 -2 多边形覆盖的网格编码太多 -3 输入无效经纬度
 * @author hxj
 * @date 2020.07.20 重写算法
 * @date 2020.07.24 提高鲁棒性
 */
GEOSOT2D_EXPORT_C int PolygonGridSelect_Array(double dbB[], double dbL[], int pointNum, unsigned char chLayer, unsigned long long geoIdArr[], int &num);

/**
 * 扇形聚合网格
 * @param latitude     圆心纬度
 * @param longitude    圆心经度
 * @param radius       半径 单位 米 m
 * @param startRad     起始方位角 弧度制
 * @param endRad       终点方位角 弧度制
 * @param chLayer      层级
 * @param tgGeoIdArr   聚合网格数组
 * @param tgLayerArr   聚合网格层级数组
 * @param num          聚合网格数组大小
 * @param maxLayer     最大聚合层级
 * @return 0 正常 -1 调整网格编码数组大小
 * @author hxj
 * @date 2022年3月2日
 */
GEOSOT2D_EXPORT_C int SectorTogetherGrids(double latitude, double longitude, double radius, double startRad, double endRad, unsigned char chLayer, unsigned long long tgGeoIdArr[], unsigned char tgLayerArr[], int &num, unsigned char maxLayer = 1);

GEOSOT2D_EXPORT_C void SectorTogetherGridVec(double latitude, double longitude, double radius, double startRad, double endRad, unsigned char chLayer, std::vector<unsigned long long> &tgGeoIdArr, std::vector<unsigned char> &tgLayerArr, unsigned char maxLayer = 1);

GEOSOT2D_EXPORT_C void SectorTogetherGridVec2(double latitude, double longitude, double radius, double startRad, double endRad, unsigned char chLayer, std::vector<unsigned long long> &tgGeoIdArr, std::vector<unsigned char> &tgLayerArr, unsigned char maxLayer = 1);

GEOSOT2D_EXPORT_C void Grid3dRange(const std::array<unsigned char, 12> &geoId3d, unsigned char layer, double &dLon, double &dLat, double &dHeight, double &dLonM, double &dLatM, double &dHeightM);

/**
 * 感知范围网格
 * @param latitude 纬度
 * @param longitude 经度
 * @param height 高度
 * @param senseRadius 距离
 * @param startRad 平面起始弧度 0到2PI
 * @param endRad 平面终点弧度 0到2PI
 * @param pitchStart 俯仰角起始弧度 -PI/2到PI/2
 * @param pitchEnd 俯仰角终点弧度 -PI/2到PI/2
 * @param layer 层级
 * @param tgGeoIdArr 网格编码
 * @param tgLayerArr 网格层级
 * @param maxLayer 最大网格的层级
 */
GEOSOT2D_EXPORT_C void VisualTogetherGrids(
        double latitude,
        double longitude,
        double height,
        double senseRadius,
        double startRad,
        double endRad,
        double pitchStart,
        double pitchEnd,
        unsigned char layer,
        std::vector<std::array<unsigned char, 12>> &tgGeoIdArr,
        std::vector<unsigned char> &tgLayerArr,
        unsigned char maxLayer = 1);

/**
 * 感知范围网格
 * @param latitude 纬度
 * @param longitude 经度
 * @param height 高度
 * @param senseRadius 距离
 * @param startRad 平面起始弧度 0到2PI
 * @param endRad 平面终点弧度 0到2PI
 * @param pitchStart 俯仰角起始弧度 -PI/2到PI/2
 * @param pitchEnd 俯仰角终点弧度 -PI/2到PI/2
 * @param layer 层级
 * @param geoIdArr 网格编码
 */
GEOSOT2D_EXPORT_C void VisualGrids(
        double latitude,
        double longitude,
        double height,
        double senseRadius,
        double startRad,
        double endRad,
        double pitchStart,
        double pitchEnd,
        unsigned char layer,
        std::vector<std::array<unsigned char, 12>> &geoIdArr);

/**
 * 多边形聚合网格化
 * @param[in]   dbB            纬度数组
 * @param[in]   dbL            经度数组
 * @param[in]   pointNum       点数量
 * @param[in]   chLayer        剖分层级
 * @param[out]  tgGeoIdArr     聚合网格编码
 * @param[out]  tgLayerArr     聚合层级
 * @param[out]  num            数量
 * @param[in]   maxLayer       最大聚合层级
 * @return 0 编码成功 -1 num太小，根据更改后的num调整tgGeoIdArr和tgLayerArr大小 -2 多边形覆盖的网格编码太多 -3 输入无效经纬度
 * @author hxj
 * @date 2022年3月8日 新增
 */
GEOSOT2D_EXPORT_C int PolygonGridSelectTogether_Array_Limit(double dbB[], double dbL[], int pointNum, unsigned char chLayer, unsigned long long tgGeoIdArr[], unsigned char tgLayerArr[], int &num, unsigned char maxLayer = 1);

GEOSOT2D_EXPORT_C int PolygonGridSelectTogetherVec(double dbB[], double dbL[], int pointNum, unsigned char chLayer, std::vector<unsigned long long> &tgGeoIdArr, std::vector<unsigned char> &tgLayerArr, unsigned char maxLayer = 1);

GEOSOT2D_EXPORT_C void TranGeoID2RowCol(unsigned long long geoID, unsigned char chLayer, int &row, int &col);

GEOSOT2D_EXPORT_C void TranRowCol2GeoID(int row, int col, unsigned char chLayer, unsigned long long &geoID);

GEOSOT2D_EXPORT_C void TranBL2RowCol(double dbB, double dbL, unsigned char chLayer, int &row, int &col);



#endif //GEOSOT_KD_WGF_GEOSOT_H
