#include "rtv1.h"

float clamp(float value, float min, float max){
    if (value < min){
        value = min;
    }
    else if (value > max){
        value = max;
    }
    return (value);
}

t_vec   clamp_vect(t_vec v){
    v.x = clamp(v.x * 255, 0.0f, 255.0f);
    v.y = clamp(v.y * 255, 0.0f, 255.0f);
    v.z = clamp(v.z * 255, 0.0f, 255.0f);
    return (v);
}

int rgb_to_int(t_vec v)
{
    int red = (int)v.x;
    int green = (int)v.y;
    int blue = (int)v.z;

    int rgb = red;
rgb = (rgb << 8) + green;
rgb = (rgb << 8) + blue;
return (rgb);
}