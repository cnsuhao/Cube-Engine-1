#ifndef FRUSTUM_H
#define FRUSTUM_H
#include "geometry/aabb.h"
#include "geometry/plane.h"
#include "geometry/aabb.h"
class Camera;
class Frustum
{
    friend class Camera;
public:
    /**
     * Constructor & Destructor.
     */
    Frustum(): _initialized(false), _clipZ(true){}
    ~Frustum(){}

    /**
     * init frustum from camera.
     */
    bool initFrustum(Camera* camera);

    /**
     * is aabb out of frustum.
     */
    bool isOutOfFrustum(const AABB& aabb) const;

    /**
     * get & set z clip. if bclipZ == true use near and far plane
     */
    void setClipZ(bool clipZ) { _clipZ = clipZ; }
    bool isClipZ() { return _clipZ; }

protected:
    /**
     * create clip plane
     */
    void createPlane( Camera* camera);

    Plane _plane[6];             // clip plane, left, right, top, bottom, near, far
    bool _clipZ;                // use near and far clip plane
    bool _initialized;
};
#endif // FRUSTUM_H