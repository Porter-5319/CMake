#ifndef GRIDEXPORT_H
#define GRIDEXPORT_H

#ifdef GRID_EXPORTS
#define GRID_API __declspec(dllexport)
#else
#define GRID_API __declspec(dllimport)
#endif

#endif // GRIDEXPORT_H
