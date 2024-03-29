/* 
 * Tux Racer 
 * Copyright (C) 1999-2001 Jasmin F. Patry
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "tuxracer.h"
#include "render_util.h"
#include "hier.h"
#include "alglib.h"

#define USE_GLUSPHERE 0

#if USE_GLUSPHERE

/* Draws a sphere using gluSphere
 */
void draw_sphere( int num_divisions )
{
    GLUquadricObj *qobj;

    qobj = gluNewQuadric();
    gluQuadricDrawStyle( qobj, GLU_FILL );
    gluQuadricOrientation( qobj, GLU_OUTSIDE );
    gluQuadricNormals( qobj, GLU_SMOOTH );

    gluSphere( qobj, 1.0, 2.0 * num_divisions, num_divisions );

    gluDeleteQuadric( qobj );
    
}

#else 

void draw_sphere( int num_divisions )
{
    scalar_t theta, phi, d_theta, d_phi, eps, twopi;
    scalar_t x, y, z;
    int div = num_divisions;

    eps = 1e-15;
    twopi = M_PI * 2.0;

    d_theta = d_phi = M_PI / div;

    for ( phi = 0.0; phi + eps < M_PI; phi += d_phi ) {
	scalar_t cos_theta, sin_theta;
	scalar_t sin_phi, cos_phi;
	scalar_t sin_phi_d_phi, cos_phi_d_phi;

	sin_phi = sin( phi );
	cos_phi = cos( phi );
	sin_phi_d_phi = sin( phi + d_phi );
	cos_phi_d_phi = cos( phi + d_phi );
        
        if ( phi <= eps ) {

            glBegin( GL_TRIANGLE_FAN );
                glNormal3f( 0.0, 0.0, 1.0 );
                glVertex3f( 0.0, 0.0, 1.0 );

                for ( theta = 0.0; theta + eps < twopi; theta += d_theta ) {
		    sin_theta = sin( theta );
		    cos_theta = cos( theta );

                    x = cos_theta * sin_phi_d_phi;
		    y = sin_theta * sin_phi_d_phi;
                    z = cos_phi_d_phi;
                    glNormal3f( x, y, z );
                    glVertex3f( x, y, z );

                } 

		x = sin_phi_d_phi;
		y = 0.0;
		z = cos_phi_d_phi;
                glNormal3f( x, y, z );
                glVertex3f( x, y, z );
            glEnd();

        } else if ( phi + d_phi + eps >= M_PI ) {
            
            glBegin( GL_TRIANGLE_FAN );
                glNormal3f( 0.0, 0.0, -1.0 );
                glVertex3f( 0.0, 0.0, -1.0 );

                for ( theta = twopi; theta - eps > 0; theta -= d_theta ) {
		    sin_theta = sin( theta );
		    cos_theta = cos( theta );

                    x = cos_theta * sin_phi;
                    y = sin_theta * sin_phi;
                    z = cos_phi;
                    glNormal3f( x, y, z );
                    glVertex3f( x, y, z );
                } 
                x = sin_phi;
                y = 0.0;
                z = cos_phi;
                glNormal3f( x, y, z );
                glVertex3f( x, y, z );
            glEnd();

        } else {
            
            glBegin( GL_TRIANGLE_STRIP );
                
                for ( theta = 0.0; theta + eps < twopi; theta += d_theta ) {
		    sin_theta = sin( theta );
		    cos_theta = cos( theta );

                    x = cos_theta * sin_phi;
                    y = sin_theta * sin_phi;
                    z = cos_phi;
                    glNormal3f( x, y, z );
                    glVertex3f( x, y, z );

                    x = cos_theta * sin_phi_d_phi;
                    y = sin_theta * sin_phi_d_phi;
                    z = cos_phi_d_phi;
                    glNormal3f( x, y, z );
                    glVertex3f( x, y, z );
                } 
                x = sin_phi;
                y = 0.0;
                z = cos_phi;
                glNormal3f( x, y, z );
                glVertex3f( x, y, z );

                x = sin_phi_d_phi;
                y = 0.0;
                z = cos_phi_d_phi;
                glNormal3f( x, y, z );
                glVertex3f( x, y, z );

            glEnd();

        } 
    } 
} 

#endif /* USE_GLUSPHERE */

static GLuint get_sphere_display_list( int divisions ) {
    static bool_t initialized = False;
    static int num_display_lists;
    static GLuint *display_lists = NULL;
    int base_divisions;
    int i, idx;

    if ( !initialized ) {
	initialized = True;
	base_divisions = getparam_tux_sphere_divisions();

	num_display_lists = MAX_SPHERE_DIVISIONS - MIN_SPHERE_DIVISIONS + 1;

	check_assertion( display_lists == NULL, "display_lists not NULL" );
	display_lists = (GLuint*) malloc( sizeof(GLuint) * num_display_lists );

	for (i=0; i<num_display_lists; i++) {
	    display_lists[i] = 0;
	}
    }


    idx = divisions - MIN_SPHERE_DIVISIONS;

    check_assertion( idx >= 0 &&
		     idx < num_display_lists, 
		     "invalid number of sphere subdivisions" );

    if ( display_lists[idx] == 0 ) {
	/* Initialize the sphere display list */
//  display_lists[idx] = glGenLists(1);
//	glNewList( display_lists[idx], GL_COMPILE );
	draw_sphere( divisions );
//	glEndList();
    }

    return display_lists[idx];
}



/*--------------------------------------------------------------------------*/

/* Traverses the DAG structure and draws the nodes
 */
void traverse_dag( scene_node_t *node, material_t *mat )
{
    scene_node_t *child;

    check_assertion( node != NULL, "node is NULL" );
    glPushMatrix();

    glMultMatrixd( (double *) node->trans );

    if ( node->mat != NULL ) {
        mat = node->mat;
    } 

    if ( node->geom == Sphere ) {
        set_material( mat->diffuse, mat->specular_colour, 
                     mat->specular_exp );

//	if ( getparam_use_sphere_display_list() ) {
	    //glCallList( get_sphere_display_list(
		//node->param.sphere.divisions ) );
//	} else {
	    draw_sphere( node->param.sphere.divisions );
//	}
    } 

    child = node->child;
    while (child != NULL) {
        traverse_dag( child, mat );
        child = child->next;
    } 

    glPopMatrix();
} 

/*--------------------------------------------------------------------------*/

/*
 * make_normal - creates the normal vector for the surface defined by a convex
 * polygon; points in polygon must be specifed in counter-clockwise direction
 * when viewed from outside the shape for the normal to be outward-facing
 */
vector_t make_normal( polygon_t p, point_t *v )
{
    vector_t normal, v1, v2;
    scalar_t old_len;

    check_assertion( p.num_vertices > 2, "number of vertices must be > 2" );

    v1 = subtract_points( v[p.vertices[1]], v[p.vertices[0]] );
    v2 = subtract_points( v[p.vertices[p.num_vertices-1]], v[p.vertices[0]] );
    normal = cross_product( v1, v2 );

    old_len = normalize_vector( &normal );
    check_assertion( old_len > 0, "normal vector has length 0" );

    return normal;
} 

/*--------------------------------------------------------------------------*/

/* Returns true iff the specified polygon intersections a unit-radius sphere
 * centered at the origin.  */
bool_t intersect_polygon( polygon_t p, point_t *v )
{
    ray_t ray; 
    vector_t nml, edge_nml, edge_vec;
    point_t pt;
    double d, s, nuDotProd, wec;
    double edge_len, t, distsq;
    int i;

    /* create a ray from origin along polygon normal */
    nml = make_normal( p, v );
    ray.pt = make_point( 0., 0., 0. );
    ray.vec = nml;

    nuDotProd = dot_product( nml, ray.vec );
    if ( fabs(nuDotProd) < EPS )
        return False;

    /* determine distance of plane from origin */
    d = -( nml.x * v[p.vertices[0]].x + 
           nml.y * v[p.vertices[0]].y + 
           nml.z * v[p.vertices[0]].z );

    /* if plane's distance to origin > 1, immediately reject */
    if ( fabs( d ) > 1 )
        return False;

    /* check distances of edges from origin */
    for ( i=0; i < p.num_vertices; i++ ) {
	point_t *v0, *v1;

	v0 = &v[p.vertices[i]];
	v1 = &v[p.vertices[ (i+1) % p.num_vertices ]]; 

	edge_vec = subtract_points( *v1, *v0 );
	edge_len = normalize_vector( &edge_vec );

	/* t is the distance from v0 of the closest point on the line
           to the origin */
	t = - dot_product( *((vector_t *) v0), edge_vec );

	if ( t < 0 ) {
	    /* use distance from v0 */
	    distsq = MAG_SQD( *v0 );
	} else if ( t > edge_len ) {
	    /* use distance from v1 */
	    distsq = MAG_SQD( *v1 );
	} else {
	    /* closest point to origin is on the line segment */
	    *v0 = move_point( *v0, scale_vector( t, edge_vec ) );
	    distsq = MAG_SQD( *v0 );
	}

	if ( distsq <= 1 ) {
	    return True;
	}
    }

    /* find intersection point of ray and plane */
    s = - ( d + dot_product( nml, make_vector(ray.pt.x, ray.pt.y, ray.pt.z) ) ) /
        nuDotProd;

    pt = move_point( ray.pt, scale_vector( s, ray.vec ) );

    /* test if intersection point is in polygon by clipping against it 
     * (we are assuming that polygon is convex) */
    for ( i=0; i < p.num_vertices; i++ ) {
        edge_nml = cross_product( nml, 
            subtract_points( v[p.vertices[ (i+1) % p.num_vertices ]], v[p.vertices[i]] ) );

        wec = dot_product( subtract_points( pt, v[p.vertices[i]] ), edge_nml );
        if (wec < 0)
            return False;
    } 

    return True;
} 

/*--------------------------------------------------------------------------*/

/* returns true iff polyhedron intersects unit-radius sphere centered
   at origin */
bool_t intersect_polyhedron( polyhedron_t p )
{
    bool_t hit = False;
    int i;

    for (i=0; i<p.num_polygons; i++) {
        hit = intersect_polygon( p.polygons[i], p.vertices );
        if ( hit == True ) 
            break;
    } 
    return hit;
} 

/*--------------------------------------------------------------------------*/

polyhedron_t copy_polyhedron( polyhedron_t ph )
{
    int i;
    polyhedron_t newph = ph;
    newph.vertices = (point_t *) malloc( sizeof(point_t) * ph.num_vertices );
    for (i=0; i<ph.num_vertices; i++) {
        newph.vertices[i] = ph.vertices[i];
    } 
    return newph;
} 

/*--------------------------------------------------------------------------*/

void free_polyhedron( polyhedron_t ph ) 
{
    free(ph.vertices);
} 

/*--------------------------------------------------------------------------*/

void trans_polyhedron( matrixgl_t mat, polyhedron_t ph )
{
    int i;
    for (i=0; i<ph.num_vertices; i++) {
        ph.vertices[i] = transform_point( mat, ph.vertices[i] );
    } 
} 

/*--------------------------------------------------------------------------*/

bool_t check_polyhedron_collision_with_dag( 
    scene_node_t *node, matrixgl_t modelMatrix, matrixgl_t invModelMatrix,
    polyhedron_t ph)
{
    matrixgl_t newModelMatrix, newInvModelMatrix;
    scene_node_t *child;
    polyhedron_t newph;
    bool_t hit = False;

    check_assertion( node != NULL, "node is NULL" );

    multiply_matrices( newModelMatrix, modelMatrix, node->trans );
    multiply_matrices( newInvModelMatrix, node->invtrans, invModelMatrix );

    if ( node->geom == Sphere ) {
        newph = copy_polyhedron( ph );
        trans_polyhedron( newInvModelMatrix, newph );

        hit = intersect_polyhedron( newph );

        free_polyhedron( newph );
    } 

    if (hit == True) return hit;

    child = node->child;
    while (child != NULL) {

        hit = check_polyhedron_collision_with_dag( 
	    child, newModelMatrix, newInvModelMatrix, ph );

        if ( hit == True ) {
            return hit;
        }

        child = child->next;
    } 

    return False;
} 

