---
generator: doxide
---


# Vector3D

**class Vector3D**


Represents a 3D vector with basic vector operations.


## Variables

| Name | Description |
| ---- | ----------- |
| [x](#x) |  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator+](#operator_u002b) | Adds two vectors. |
| [operator-](#operator_u002d) | Subtracts one vector from another. |
| [operator*](#operator_u002a) | Multiplies the vector by a scalar. |
| [operator/](#operator/) | Divides the vector by a scalar. |

## Functions

| Name | Description |
| ---- | ----------- |
| [Vector3D](#Vector3D) | Default constructor for Vector3D. |
| [Vector3D](#Vector3D) | Constructs a Vector3D with specified x, y, and z components. |
| [dot](#dot) | Computes the dot product of two vectors. |
| [cross](#cross) | Computes the cross product of two vectors. |
| [length](#length) | Computes the length (magnitude) of the vector. |
| [normalized](#normalized) | Normalizes the vector to have a length of 1. |

## Variable Details

### x<a name="x"></a>

!!! variable "float x, y, z"

    

## Operator Details

### operator*<a name="operator_u002a"></a>

!!! function "Vector3D operator&#42;(float scalar) const"

    Multiplies the vector by a scalar.
        
    :material-location-enter: `scalar`
    :    float The scalar value.
        
    :material-keyboard-return: **Return**
    :    The resulting vector after multiplication.
    

### operator+<a name="operator_u002b"></a>

!!! function "Vector3D operator+(const Vector3D&amp; other) const"

    Adds two vectors.
        
    :material-location-enter: `other`
    :    const Vector3D & The vector to add.
        
    :material-keyboard-return: **Return**
    :    The resulting vector after addition.
    

### operator-<a name="operator_u002d"></a>

!!! function "Vector3D operator-(const Vector3D&amp; other) const"

    Subtracts one vector from another.
        
    :material-location-enter: `other`
    :    const Vector3D & The vector to subtract.
        
    :material-keyboard-return: **Return**
    :    The resulting vector after subtraction.
    

### operator/<a name="operator/"></a>

!!! function "Vector3D operator/(float scalar) const"

    Divides the vector by a scalar.
        
    :material-location-enter: `scalar`
    :    float The scalar value.
        
    :material-keyboard-return: **Return**
    :    The resulting vector after division.
    

## Function Details

### Vector3D<a name="Vector3D"></a>
!!! function "Vector3D()"

    Default constructor for Vector3D.
    Initializes the vector to (0, 0, 0).
    

!!! function "Vector3D(float x, float y, float z)"

    Constructs a Vector3D with specified x, y, and z components.
    
    :material-location-enter: `x`
    :    float The x component.
        
    :material-location-enter: `y`
    :    float The y component.
        
    :material-location-enter: `z`
    :    float The z component.
    

### cross<a name="cross"></a>
!!! function "Vector3D cross(const Vector3D&amp; other) const"

    Computes the cross product of two vectors.
        
    :material-location-enter: `other`
    :    const Vector3D & The other vector.
        
    :material-keyboard-return: **Return**
    :    The resulting vector after the cross product.
    

### dot<a name="dot"></a>
!!! function "float dot(const Vector3D&amp; other) const"

    Computes the dot product of two vectors.
        
    :material-location-enter: `other`
    :    const Vector3D & The other vector.
        
    :material-keyboard-return: **Return**
    :    The dot product as a float.
    

### length<a name="length"></a>
!!! function "float length() const"

    Computes the length (magnitude) of the vector.
        
    :material-keyboard-return: **Return**
    :    The length of the vector as a float.
    

### normalized<a name="normalized"></a>
!!! function "Vector3D normalized() const"

    Normalizes the vector to have a length of 1.
        
    :material-keyboard-return: **Return**
    :    The normalized vector.
    

