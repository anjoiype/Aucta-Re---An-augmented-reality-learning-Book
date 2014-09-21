/*
created with obj2opengl.pl

source file    : .\t.obj
vertices       : 16
faces          : 28
normals        : 6
texture coords : 24


// include generated arrays
#import ".\t.h"

// set input data to arrays
glVertexPointer(3, GL_FLOAT, 0, tVerts);
glNormalPointer(GL_FLOAT, 0, tNormals);
glTexCoordPointer(2, GL_FLOAT, 0, tTexCoords);

// draw data
glDrawArrays(GL_TRIANGLES, 0, tNumVerts);
*/

unsigned int tNumVerts = 84;

float tVerts [] = {
  // f 1/1/1 2/2/1 3/3/1 
  0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 1/1/1 3/3/1 4/4/1 
  0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  // f 2/2/2 5/5/2 6/6/2 
  0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  0.395475819032761, 0.190717628705148, -0.0858034321372855,
  0.395475819032761, 0.190717628705148, 0.0858034321372855,
  // f 2/2/2 6/6/2 3/3/2 
  0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  0.395475819032761, 0.190717628705148, 0.0858034321372855,
  0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 5/5/1 7/7/1 8/8/1 
  0.395475819032761, 0.190717628705148, -0.0858034321372855,
  0.395475819032761, 0.309282371294852, -0.0858034321372855,
  0.395475819032761, 0.309282371294852, 0.0858034321372855,
  // f 5/5/1 8/8/1 6/6/1 
  0.395475819032761, 0.190717628705148, -0.0858034321372855,
  0.395475819032761, 0.309282371294852, 0.0858034321372855,
  0.395475819032761, 0.190717628705148, 0.0858034321372855,
  // f 7/7/3 9/9/3 10/10/3 
  0.395475819032761, 0.309282371294852, -0.0858034321372855,
  -0.395475819032761, 0.309282371294852, -0.0858034321372855,
  -0.395475819032761, 0.309282371294852, 0.0858034321372855,
  // f 7/7/3 10/10/3 8/8/3 
  0.395475819032761, 0.309282371294852, -0.0858034321372855,
  -0.395475819032761, 0.309282371294852, 0.0858034321372855,
  0.395475819032761, 0.309282371294852, 0.0858034321372855,
  // f 9/9/4 11/11/4 12/12/4 
  -0.395475819032761, 0.309282371294852, -0.0858034321372855,
  -0.395475819032761, 0.190717628705148, -0.0858034321372855,
  -0.395475819032761, 0.190717628705148, 0.0858034321372855,
  // f 9/9/4 12/12/4 10/10/4 
  -0.395475819032761, 0.309282371294852, -0.0858034321372855,
  -0.395475819032761, 0.190717628705148, 0.0858034321372855,
  -0.395475819032761, 0.309282371294852, 0.0858034321372855,
  // f 11/11/2 13/13/2 14/14/2 
  -0.395475819032761, 0.190717628705148, -0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 11/11/2 14/14/2 12/12/2 
  -0.395475819032761, 0.190717628705148, -0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  -0.395475819032761, 0.190717628705148, 0.0858034321372855,
  // f 13/13/4 15/15/4 16/16/4 
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  -0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  -0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  // f 13/13/4 16/16/4 14/14/4 
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  -0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 15/15/2 1/17/2 4/18/2 
  -0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  // f 15/15/2 4/18/2 16/16/2 
  -0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  -0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  // f 13/19/5 1/20/5 15/21/5 
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  -0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  // f 13/19/5 2/22/5 1/20/5 
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  0.0663026521060842, -0.690717628705148, -0.0858034321372855,
  // f 9/4/5 13/19/5 11/23/5 
  -0.395475819032761, 0.309282371294852, -0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  -0.395475819032761, 0.190717628705148, -0.0858034321372855,
  // f 7/18/5 13/19/5 9/4/5 
  0.395475819032761, 0.309282371294852, -0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  -0.395475819032761, 0.309282371294852, -0.0858034321372855,
  // f 7/18/5 2/22/5 13/19/5 
  0.395475819032761, 0.309282371294852, -0.0858034321372855,
  0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  // f 7/18/5 5/24/5 2/22/5 
  0.395475819032761, 0.309282371294852, -0.0858034321372855,
  0.395475819032761, 0.190717628705148, -0.0858034321372855,
  0.0663026521060842, 0.190717628705148, -0.0858034321372855,
  // f 14/19/6 16/21/6 4/20/6 
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  -0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  // f 14/19/6 4/20/6 3/22/6 
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  0.0663026521060842, -0.690717628705148, 0.0858034321372855,
  0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 10/4/6 12/23/6 14/19/6 
  -0.395475819032761, 0.309282371294852, 0.0858034321372855,
  -0.395475819032761, 0.190717628705148, 0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 8/18/6 10/4/6 14/19/6 
  0.395475819032761, 0.309282371294852, 0.0858034321372855,
  -0.395475819032761, 0.309282371294852, 0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 8/18/6 14/19/6 3/22/6 
  0.395475819032761, 0.309282371294852, 0.0858034321372855,
  -0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  // f 8/18/6 3/22/6 6/24/6 
  0.395475819032761, 0.309282371294852, 0.0858034321372855,
  0.0663026521060842, 0.190717628705148, 0.0858034321372855,
  0.395475819032761, 0.190717628705148, 0.0858034321372855,
};

float tNormals [] = {
  // f 1/1/1 2/2/1 3/3/1 
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 1/1/1 3/3/1 4/4/1 
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 2/2/2 5/5/2 6/6/2 
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 2/2/2 6/6/2 3/3/2 
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 5/5/1 7/7/1 8/8/1 
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 5/5/1 8/8/1 6/6/1 
  1, 0, 0,
  1, 0, 0,
  1, 0, 0,
  // f 7/7/3 9/9/3 10/10/3 
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 7/7/3 10/10/3 8/8/3 
  0, 1, 0,
  0, 1, 0,
  0, 1, 0,
  // f 9/9/4 11/11/4 12/12/4 
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
  // f 9/9/4 12/12/4 10/10/4 
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
  // f 11/11/2 13/13/2 14/14/2 
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 11/11/2 14/14/2 12/12/2 
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 13/13/4 15/15/4 16/16/4 
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
  // f 13/13/4 16/16/4 14/14/4 
  -1, 0, 0,
  -1, 0, 0,
  -1, 0, 0,
  // f 15/15/2 1/17/2 4/18/2 
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 15/15/2 4/18/2 16/16/2 
  0, -1, 0,
  0, -1, 0,
  0, -1, 0,
  // f 13/19/5 1/20/5 15/21/5 
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 13/19/5 2/22/5 1/20/5 
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 9/4/5 13/19/5 11/23/5 
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 7/18/5 13/19/5 9/4/5 
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 7/18/5 2/22/5 13/19/5 
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 7/18/5 5/24/5 2/22/5 
  0, 0, -1,
  0, 0, -1,
  0, 0, -1,
  // f 14/19/6 16/21/6 4/20/6 
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 14/19/6 4/20/6 3/22/6 
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 10/4/6 12/23/6 14/19/6 
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 8/18/6 10/4/6 14/19/6 
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 8/18/6 14/19/6 3/22/6 
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 8/18/6 3/22/6 6/24/6 
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
};

float tTexCoords [] = {
  // f 1/1/1 2/2/1 3/3/1 
  0.0000, 1,
  0.2461, 1,
  0.2461, 0,
  // f 1/1/1 3/3/1 4/4/1 
  0.0000, 1,
  0.2461, 0,
  0.0000, 0,
  // f 2/2/2 5/5/2 6/6/2 
  0.2461, 1,
  0.3380, 1,
  0.3380, 0,
  // f 2/2/2 6/6/2 3/3/2 
  0.2461, 1,
  0.3380, 0,
  0.2461, 0,
  // f 5/5/1 7/7/1 8/8/1 
  0.3380, 1,
  0.3711, 1,
  0.3711, 0,
  // f 5/5/1 8/8/1 6/6/1 
  0.3380, 1,
  0.3711, 0,
  0.3380, 0,
  // f 7/7/3 9/9/3 10/10/3 
  0.3711, 1,
  0.5919, 1,
  0.5919, 0,
  // f 7/7/3 10/10/3 8/8/3 
  0.3711, 1,
  0.5919, 0,
  0.3711, 0,
  // f 9/9/4 11/11/4 12/12/4 
  0.5919, 1,
  0.6250, 1,
  0.6250, 0,
  // f 9/9/4 12/12/4 10/10/4 
  0.5919, 1,
  0.6250, 0,
  0.5919, 0,
  // f 11/11/2 13/13/2 14/14/2 
  0.6250, 1,
  0.7169, 1,
  0.7169, 0,
  // f 11/11/2 14/14/2 12/12/2 
  0.6250, 1,
  0.7169, 0,
  0.6250, 0,
  // f 13/13/4 15/15/4 16/16/4 
  0.7169, 1,
  0.9630, 1,
  0.9630, 0,
  // f 13/13/4 16/16/4 14/14/4 
  0.7169, 1,
  0.9630, 0,
  0.7169, 0,
  // f 15/15/2 1/17/2 4/18/2 
  0.9630, 1,
  1.0000, 1,
  1.0000, 0,
  // f 15/15/2 4/18/2 16/16/2 
  0.9630, 1,
  1.0000, 0,
  0.9630, 0,
  // f 13/19/5 1/20/5 15/21/5 
  0.4162, 0.1186,
  0.5838, 1,
  0.4162, 1,
  // f 13/19/5 2/22/5 1/20/5 
  0.4162, 0.1186,
  0.5838, 0.1186,
  0.5838, 1,
  // f 9/4/5 13/19/5 11/23/5 
  0.0000, 0,
  0.4162, 0.1186,
  0.0000, 0.1186,
  // f 7/18/5 13/19/5 9/4/5 
  1.0000, 0,
  0.4162, 0.1186,
  0.0000, 0,
  // f 7/18/5 2/22/5 13/19/5 
  1.0000, 0,
  0.5838, 0.1186,
  0.4162, 0.1186,
  // f 7/18/5 5/24/5 2/22/5 
  1.0000, 0,
  1.0000, 0.1186,
  0.5838, 0.1186,
  // f 14/19/6 16/21/6 4/20/6 
  0.4162, 0.1186,
  0.4162, 1,
  0.5838, 1,
  // f 14/19/6 4/20/6 3/22/6 
  0.4162, 0.1186,
  0.5838, 1,
  0.5838, 0.1186,
  // f 10/4/6 12/23/6 14/19/6 
  0.0000, 0,
  0.0000, 0.1186,
  0.4162, 0.1186,
  // f 8/18/6 10/4/6 14/19/6 
  1.0000, 0,
  0.0000, 0,
  0.4162, 0.1186,
  // f 8/18/6 14/19/6 3/22/6 
  1.0000, 0,
  0.4162, 0.1186,
  0.5838, 0.1186,
  // f 8/18/6 3/22/6 6/24/6 
  1.0000, 0,
  0.5838, 0.1186,
  1.0000, 0.1186,
};

