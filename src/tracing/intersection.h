#ifndef INTERSECTION_H
#define INTERSECTION_H

namespace Trayracer2 {

class SceneObject;

struct Intersection {
    Intersection() = default;

    Intersection(bool hit, float dist, SceneObject* object) : hit(hit),
                                                                    dist(dist),
                                                                    object(object) {}

    bool hit;
    float dist;
    SceneObject* object;
};

}

#endif //INTERSECTION_H
