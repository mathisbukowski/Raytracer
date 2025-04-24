---
generator: doxide
---


# PrimitiveFactory

**class PrimitiveFactory**


Factory class for creating primitive objects.


## Functions

| Name | Description |
| ---- | ----------- |
| [createSphere](#createSphere) | Creates a sphere primitive. |
| [createPlane](#createPlane) | Creates a plane primitive. |
| [createCylinder](#createCylinder) | Creates a cylinder primitive. |
| [createCone](#createCone) | Creates a cone primitive. |

## Function Details

### createCone<a name="createCone"></a>
!!! function "static std::shared_ptr&lt;IPrimitive&gt; createCone(const Vector3D&amp; apex, const Vector3D&amp; axis, float angle, const Color&amp; color)"

    Creates a cone primitive.
        
    :material-location-enter: `apex`
    :    const Vector3D & The apex point of the cone.
        
    :material-location-enter: `axis`
    :    const Vector3D & The axis vector of the cone.
        
    :material-location-enter: `angle`
    :    float The angle of the cone.
        
    :material-location-enter: `color`
    :    const Color & The color of the cone.
        
    :material-keyboard-return: **Return**
    :    A shared pointer to the created cone primitive.
    

### createCylinder<a name="createCylinder"></a>
!!! function "static std::shared_ptr&lt;IPrimitive&gt; createCylinder(const Vector3D&amp; base, const Vector3D&amp; axis, float radius, const Color&amp; color)"

    Creates a cylinder primitive.
        
    :material-location-enter: `base`
    :    const Vector3D & The base point of the cylinder.
        
    :material-location-enter: `axis`
    :    const Vector3D & The axis vector of the cylinder.
        
    :material-location-enter: `radius`
    :    float The radius of the cylinder.
        
    :material-location-enter: `color`
    :    const Color & The color of the cylinder.
        
    :material-keyboard-return: **Return**
    :    A shared pointer to the created cylinder primitive.
    

### createPlane<a name="createPlane"></a>
!!! function "static std::shared_ptr&lt;IPrimitive&gt; createPlane(const Vector3D&amp; normal, float distance, const Color&amp; color)"

    Creates a plane primitive.
        
    :material-location-enter: `normal`
    :    const Vector3D & The normal vector of the plane.
        
    :material-location-enter: `distance`
    :    float The distance of the plane from the origin.
        
    :material-location-enter: `color`
    :    const Color & The color of the plane.
        
    :material-keyboard-return: **Return**
    :    A shared pointer to the created plane primitive.
    

### createSphere<a name="createSphere"></a>
!!! function "static std::shared_ptr&lt;IPrimitive&gt; createSphere(const Vector3D&amp; center, float radius, const Color&amp; color)"

    Creates a sphere primitive.
    
    :material-location-enter: `center`
    :    const Vector3D & The center of the sphere.
        
    :material-location-enter: `radius`
    :    float The radius of the sphere.
        
    :material-location-enter: `color`
    :    const Color & The color of the sphere.
        
    :material-keyboard-return: **Return**
    :    A shared pointer to the created sphere primitive.
    

