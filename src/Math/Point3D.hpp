/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_


namespace RayTracer {
    class Vector3D;

    /**
     * @class Point3D
     * Represents a point in 3D space.
     */
    class Point3D {
        public:
            /**
             * The x, y, and z coordinates of the point.
             */
            float x, y, z;
            /**
             * Default constructor for Point3D.
             * Initializes the point to (0, 0, 0).
             */
            Point3D();
            /**
             * Constructs a Point3D with specified x, y, and z coordinates.
             * @param x float The x coordinate.
             * @param y float The y coordinate.
             * @param z float The z coordinate.
             */
            Point3D(float x, float y, float z);
            /**
             * Constructs a Point3D from a Vector3D.
             * @param v const Vector3D & The vector to convert to a point.
             */
            Point3D(const Vector3D& v);

            /**
             * Constructs a Point3D from Vector3D.
             * @param other const Vector3D & The vector to convert to a point.
             */
            Point3D operator+(const Vector3D& vec) const;
            /**
             * Adds a Vector3D to the current Point3D.
             * @param vec const Vector3D & The vector to add.
             * @return A reference to the current Point3D after addition.
             */
            Point3D& operator+=(const Vector3D& vec);
            /**
             * Subtracts a Vector3D from the current Point3D.
             * @param vec const Vector3D & The vector to subtract.
             * @return The current Vector3D after subtraction.
             */
            Vector3D operator-(const Point3D& other) const;
            /**
             * Compares two Point3D objects for equality.
             * @param other const Point3D & The other point to compare.
             * @return true if the points are equal, false otherwise.
             */
            bool operator==(const Point3D& other) const;
            /**
             * Compares two Point3D objects for inequality.
             * @param other const Point3D & The other point to compare.
             * @return true if the points are not equal, false otherwise.
             */
            bool operator!=(const Point3D& other) const;
    };
}

#endif // POINT3D_HPP_
