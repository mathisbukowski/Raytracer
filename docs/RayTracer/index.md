---
generator: doxide
---


# RayTracer



## Types

| Name | Description |
| ---- | ----------- |
| [ILight](ILight.md) |  Interface for light sources in the ray tracing engine. |
| [IMaterial](IMaterial.md) |  Interface for material properties in the ray tracing engine. |
| [IPrimitive](IPrimitive.md) |  Interface for geometric primitives in the ray tracing engine. |
| [PrimitiveFactory](PrimitiveFactory.md) |  Factory class for creating primitive objects. |
| [Ray](Ray.md) |  Represents a ray in 3D space. |
| [Scene](Scene.md) |  Represents a scene containing primitives, lights, and a background color. |
| [Vector3D](Vector3D.md) |  Represents a 3D vector with basic vector operations. |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator*](#operator_u002a) | Multiplies a scalar by a vector. |

## Operator Details

### operator*<a name="operator_u002a"></a>

!!! function "Vector3D operator&#42;(float scalar, const Vector3D&amp; v)"

    Multiplies a scalar by a vector.
        
    :material-location-enter: `scalar`
    :    float The scalar value.
        
    :material-location-enter: `v`
    :    const Vector3D & The vector.
        
    :material-keyboard-return: **Return**
    :    The resulting vector after multiplication.
    

