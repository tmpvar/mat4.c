# mat4.c [![stable](http://badges.github.io/stability-badges/dist/stable.svg)](http://github.com/badges/stability-badges)

Part of a fork of [@toji](http://github.com/toji)'s
[gl-matrix](http://github.com/toji/gl-matrix) in c, split into smaller pieces: this
package contains `glMatrix.mat4`.

## Usage

__main.c__
```c

#include <mat4/type.h>
#include <mat4/create.h>

mat4 m4 = mat4_create();

```

`gcc main.c -o main -Inode_modules/mat4.c/include`

### with cmake

__CMakeLists.txt__
```
cmake_minimum_required(VERSION 3.2)
project (mat4-test)
file(GLOB CMAKE_INCLUDES "node_modules/*/CMakeLists.txt")
include(${CMAKE_INCLUDES})
add_executable(main main.c)
```

## API

  - [mat4_adjoint()](#adjointoutmat4-amat4)
  - [mat4_clone()](#cloneamat4)
  - [mat4_copy()](#copyoutmat4-amat4)
  - [mat4_create()](#create)
  - [mat4_determinant()](#determinantamat4)
  - [mat4_fromQuat()](#fromquatoutmat4-qquat4)
  - [mat4_fromRotationTranslation()](#fromrotationtranslationoutmat4-qquat4-vvec3)
  - [mat4_frustum()](#frustumoutmat4-leftnumber-rightnumber-bottomnumber-topnumber-nearnumber-farnumber)
  - [mat4_identity()](#identityoutmat4)
  - [mat4_invert()](#invertoutmat4-amat4)
  - [mat4_lookAt()](#lookatoutmat4-eyevec3-centervec3-upvec3)
  - [mat4_multiply()](#multiplyoutmat4-amat4-bmat4)
  - [mat4_ortho()](#orthooutmat4-leftnumber-rightnumber-bottomnumber-topnumber-nearnumber-farnumber)
  - [mat4_perspective()](#perspectiveoutmat4-fovynumber-aspectnumber-nearnumber-farnumber)
  - [mat4_perspectiveFromFieldOfView()](#perspectivefromfieldofviewoutmat4-fovobject-nearnumber-farnumber)
  - [mat4_rotate()](#rotateoutmat4-amat4-radnumber-axisvec3)
  - [mat4_rotateX()](#rotatexoutmat4-amat4-radnumber)
  - [mat4_rotateY()](#rotateyoutmat4-amat4-radnumber)
  - [mat4_rotateZ()](#rotatezoutmat4-amat4-radnumber)
  - [mat4_scale()](#scaleoutmat4-amat4-vvec3)
  - [mat4_translate()](#translateoutmat4-amat4-vvec3)
  - [mat4_transpose()](#transposeoutmat4-amat4)

## mat4_adjoint(out:mat4, a:mat4)

  Calculates the adjugate of a mat4

## mat4_clone(a:mat4)

  Creates a new mat4 initialized with values from an existing matrix

## mat4_copy(out:mat4, a:mat4)

  Copy the values from one mat4 to another

## mat4_create()

  Creates a new identity mat4

## mat4_determinant(a:mat4)

  Calculates the determinant of a mat4

## mat4_fromQuat(out:mat4, q:quat4)

  Creates a matrix from a quaternion rotation.

## mat4_fromRotationTranslation(out:mat4, q:quat4, v:vec3)

  Creates a matrix from a quaternion rotation and vector translation
  This is equivalent to (but much faster than):
  
```c
  mat4_identity(dest);
  mat4_translate(dest, vec);
  mat4 quatMat = mat4_create();
  quat4_toMat4(quat, quatMat);
  mat4_multiply(dest, quatMat);
```

## mat4_frustum(out:mat4, left:float, right:float, bottom:float, top:float, near:float, far:float)

  Generates a frustum matrix with the given bounds

## mat4_identity(out:mat4)

  Set a mat4 to the identity matrix

## mat4_invert(out:mat4, a:mat4)

  Inverts a mat4

## mat4_lookAt(out:mat4, eye:vec3, center:vec3, up:vec3)

  Generates a look-at matrix with the given eye position, focal point, and up axis

## mat4_multiply(out:mat4, a:mat4, b:mat4)

  Multiplies two mat4's

## mat4_ortho(out:mat4, left:float, right:float, bottom:float, top:float, near:float, far:float)

  Generates a orthogonal projection matrix with the given bounds

## mat4_perspective(out:mat4, fovy:float, aspect:float, near:float, far:float)

  Generates a perspective projection matrix with the given bounds

## mat4_perspectiveFromFieldOfView(out:mat4, fov:float[4], near:float, far:float)

  Generates a perspective projection matrix with the given field of view.

## mat4_rotate(out:mat4, a:mat4, rad:float, axis:vec3)

  Rotates a mat4 by the given angle

## mat4_rotateX(out:mat4, a:mat4, rad:float)

  Rotates a matrix by the given angle around the X axis

## mat4_rotateY(out:mat4, a:mat4, rad:float)

  Rotates a matrix by the given angle around the Y axis

## mat4_rotateZ(out:mat4, a:mat4, rad:float)

  Rotates a matrix by the given angle around the Z axis

## mat4_scale(out:mat4, a:mat4, v:vec3)

  Scales the mat4 by the dimensions in the given vec3

## mat4_translate(out:mat4, a:mat4, v:vec3)

  Translate a mat4 by the given vector

## mat4_transpose(out:mat4, a:mat4)

  Transpose the values of a mat4

## License

[zlib](http://en.wikipedia.org/wiki/Zlib_License). See [LICENSE.md](https://github.com/stackgl/gl-mat4/blob/master/LICENSE.md) for details.
