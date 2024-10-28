#ifndef GRIDBUILDER_H
#define GRIDBUILDER_H

#include "GridExport.h"

#include <mutex>
#include <atomic>

namespace GG {

class Grid;
class Vec3d;

class GRID_API GridBuilder
{
public:
    inline static GridBuilder *getInstance()
    {
        // 利用原子变量解决，单例模式造成的内存泄露
        GridBuilder *sin = s_Instance.load();

        if (!sin) {
            // std::lock_guard 自动加锁解锁
            std::lock_guard<std::mutex> lock(m_mutex);
            sin = s_Instance.load();

            if (!sin) {
                sin = new GridBuilder();
                s_Instance.store(sin);
            }
        }

        return sin;
    }

    /**
     * @brief createGrid 创建网格
     * @param _gridLayer 网格的层级
     * @param _vec 网格的中心位置
     * @return 返回的创建的网格对象
     */
    Grid *createGrid(unsigned char _gridLayer, const Vec3d &_vec);

    /**
     * @brief createGrid 创建网格
     * @param _gridId 网格编码
     * @param _gridLayer 网格所在层级
     * @return
     */
    Grid *createGrid(unsigned long long _gridId, unsigned char _gridLayer);

protected:
    GridBuilder();
private:
    static std::atomic<GridBuilder *> s_Instance;
    static std::mutex m_mutex;
};

// 静态成员变量需要单独导出符号
GRID_API std::atomic<GridBuilder*> GridBuilder::s_Instance = nullptr;
GRID_API std::mutex GridBuilder::m_mutex;

}

#endif // GRIDBUILDER_H
