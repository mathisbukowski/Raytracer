---
generator: doxide
---


# Ray

**class Ray**


Represents a ray in 3D space.


## Variables

| Name | Description |
| ---- | ----------- |
| [_origin](#_origin) | The origin point of the ray. |
| [_direction](#_direction) | The direction vector of the ray. |

## Functions

| Name | Description |
| ---- | ----------- |
| [Ray](#Ray) | Constructs a Ray with a specified origin and direction. |
| [getOrigin](#getOrigin) | Gets the origin point of the ray. |
| [getDirection](#getDirection) | Gets the direction vector of the ray. |
| [pointAt](#pointAt) | Computes a point along the ray at a given parameter t. |

## Variable Details

### _direction<a name="_direction"></a>

!!! variable "Vector3D _direction"

    The direction vector of the ray.
    

### _origin<a name="_origin"></a>

!!! variable "Vector3D _origin"

    The origin point of the ray.
    

## Function Details

### Ray<a name="Ray"></a>
!!! function "Ray(const Vector3D&amp; origin, const Vector3D&amp; direction)"

    Constructs a Ray with a specified origin and direction.
    
    :material-location-enter: `origin`
    :    const Vector3D & The origin point of the ray.
        
    :material-location-enter: `direction`
    :    const Vector3D & The direction vector of the ray.
    

### getDirection<a name="getDirection"></a>
!!! function "const Vector3D&amp; getDirection() const"

    Gets the direction vector of the ray.
        
    :material-keyboard-return: **Return**
    :    A constant reference to the direction vector.
    

### getOrigin<a name="getOrigin"></a>
!!! function "const Vector3D&amp; getOrigin() const"

    Gets the origin point of the ray.
        
    :material-keyboard-return: **Return**
    :    A constant reference to the origin point.
    

### pointAt<a name="pointAt"></a>
!!! function "Vector3D pointAt(float t) const"

    Computes a point along the ray at a given parameter t.
        
    :material-location-enter: `t`
    :    float The parameter along the ray.
        
    :material-keyboard-return: **Return**
    :    The computed point as a Vector3D.
    

