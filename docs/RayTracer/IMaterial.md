---
generator: doxide
---


# IMaterial

**class IMaterial**


Interface for material properties in the ray tracing engine.


## Functions

| Name | Description |
| ---- | ----------- |
| [getReflectivity](#getReflectivity) | Virtual destructor for the IMaterial interface. |
| [getTransparency](#getTransparency) | Gets the transparency of the material. |
| [getRefractiveIndex](#getRefractiveIndex) | Gets the refractive index of the material. |

## Function Details

### getReflectivity<a name="getReflectivity"></a>
!!! function "virtual float getReflectivity() const"

    Virtual destructor for the IMaterial interface.
    Gets the color of the material at a given intersection point.
    
    :material-location-enter: `intersectionPoint`
    :    const Vector3D & The point of intersection.
        
    :material-location-enter: `normal`
    :    const Vector3D & The normal vector at the intersection point.
        
    :material-location-enter: `viewDirection`
    :    const Vector3D & The direction of the viewer.
        
    :material-keyboard-return: **Return**
    :    The color of the material at the intersection point.
    Gets the reflectivity of the material.
        
    :material-keyboard-return: **Return**
    :    The reflectivity value (default is 0.0f).
    

### getRefractiveIndex<a name="getRefractiveIndex"></a>
!!! function "virtual float getRefractiveIndex() const"

    Gets the refractive index of the material.
        
    :material-keyboard-return: **Return**
    :    The refractive index value (default is 1.0f).
    

### getTransparency<a name="getTransparency"></a>
!!! function "virtual float getTransparency() const"

    Gets the transparency of the material.
        
    :material-keyboard-return: **Return**
    :    The transparency value (default is 0.0f).
    

