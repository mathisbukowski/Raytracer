---
generator: doxide
---


# Scene

**class Scene**


Represents a scene containing primitives, lights, and a background color.


## Variables

| Name | Description |
| ---- | ----------- |
| [_primitives](#_primitives) | List of primitives in the scene. |
| [_lights](#_lights) | List of lights in the scene. |
| [_backgroundColor](#_backgroundColor) | Background color of the scene. |

## Functions

| Name | Description |
| ---- | ----------- |
| [Scene](#Scene) | Default constructor for the Scene class. |
| [addPrimitive](#addPrimitive) | Adds a primitive to the scene. |
| [addLight](#addLight) | Adds a light to the scene. |
| [setBackgroundColor](#setBackgroundColor) | Sets the background color of the scene. |
| [getBackgroundColor](#getBackgroundColor) | Gets the background color of the scene. |
| [findNearestIntersection](#findNearestIntersection) | Finds the nearest intersection of a ray with the primitives in the scene. |
| [getPrimitives](#getPrimitives) | Gets the list of primitives in the scene. |
| [getLights](#getLights) | Gets the list of lights in the scene. |

## Variable Details

### _backgroundColor<a name="_backgroundColor"></a>

!!! variable "Color _backgroundColor"

    Background color of the scene.
    

### _lights<a name="_lights"></a>

!!! variable "std::vector&lt;std::shared_ptr&lt;ILight&gt;&gt; _lights"

    List of lights in the scene.
    

### _primitives<a name="_primitives"></a>

!!! variable "std::vector&lt;std::shared_ptr&lt;IPrimitive&gt;&gt; _primitives"

    List of primitives in the scene.
    

## Function Details

### Scene<a name="Scene"></a>
!!! function "Scene()"

    Default constructor for the Scene class.
    

### addLight<a name="addLight"></a>
!!! function "void addLight(const std::shared_ptr&lt;ILight&gt;&amp; light)"

    Adds a light to the scene.
        
    :material-location-enter: `light`
    :    const std::shared_ptr\<ILight\> & The light to add.
    

### addPrimitive<a name="addPrimitive"></a>
!!! function "void addPrimitive(const std::shared_ptr&lt;IPrimitive&gt;&amp; primitive)"

    Adds a primitive to the scene.
    
    :material-location-enter: `primitive`
    :    const std::shared_ptr\<IPrimitive\> & The primitive to add.
    

### findNearestIntersection<a name="findNearestIntersection"></a>
!!! function "bool findNearestIntersection(const Ray&amp; ray, std::shared_ptr&lt;IPrimitive&gt;&amp; hitPrimitive, float&amp; t, Vector3D&amp; normal) const"

    Finds the nearest intersection of a ray with the primitives in the scene.
        
    :material-location-enter: `ray`
    :    const Ray & The ray to test for intersection.
        
    :material-location-enter: `hitPrimitive`
    :    std::shared_ptr\<IPrimitive\> & The primitive hit by the ray.
        
    :material-location-enter: `t`
    :    float & The distance to the intersection point.
        
    :material-location-enter: `normal`
    :    Vector3D & The normal vector at the intersection point.
        
    :material-keyboard-return: **Return**
    :    True if an intersection is found, false otherwise.
    

### getBackgroundColor<a name="getBackgroundColor"></a>
!!! function "const Color&amp; getBackgroundColor() const"

    Gets the background color of the scene.
        
    :material-keyboard-return: **Return**
    :    A constant reference to the background color.
    

### getLights<a name="getLights"></a>
!!! function "const std::vector&lt;std::shared_ptr&lt;ILight&gt;&gt;&amp; getLights() const"

    Gets the list of lights in the scene.
        
    :material-keyboard-return: **Return**
    :    A constant reference to the vector of lights.
    

### getPrimitives<a name="getPrimitives"></a>
!!! function "const std::vector&lt;std::shared_ptr&lt;IPrimitive&gt;&gt;&amp; getPrimitives() const"

    Gets the list of primitives in the scene.
        
    :material-keyboard-return: **Return**
    :    A constant reference to the vector of primitives.
    

### setBackgroundColor<a name="setBackgroundColor"></a>
!!! function "void setBackgroundColor(const Color&amp; color)"

    Sets the background color of the scene.
        
    :material-location-enter: `color`
    :    const Color & The background color to set.
    

