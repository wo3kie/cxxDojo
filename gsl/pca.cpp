/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 pca.cpp -o pca -lgsl -lgslcblas -lm
 *
 * Usage:
 *      $ ./pca
 */

/*
 * https://en.wikipedia.org/wiki/Principal_component_analysis
 *  #Computing_PCA_using_the_covariance_method
 */

 /*
  * Inspired with, https://gist.github.com/microo8/4065693
  */

#include <cassert>

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_statistics.h>

gsl_matrix * pca(
    gsl_matrix const * const matrix /* (points, dim) */,
    unsigned newDimension
){
    /* `points' is a number of points
     * `dim' is a number of dimensions,
     * 
     * [a0, a1, a2, ..., aN]
     * [b0, b1, b2, ..., bN]
     * ...
     * [z0, z1, z2, ..., zN]
     */

    unsigned const points = matrix->size1;
    unsigned const dim = matrix->size2;

    /* For each dimension calculate mean
     */

    gsl_vector * const mean = gsl_vector_alloc(dim);

    for(unsigned i = 0; i < dim; ++i){
        gsl_vector_set(
            mean,
            i,
            gsl_stats_mean(matrix->data + i, dim, points)
        );
    }

    /* Subtract mean
     */

    gsl_matrix * const mean_subtracted_matrix
        = gsl_matrix_alloc(points, dim);
    
    gsl_matrix_memcpy(mean_subtracted_matrix, matrix);

    for(unsigned i = 0; i < points; ++i){
        gsl_vector_view mean_subtracted_view
            = gsl_matrix_row(mean_subtracted_matrix, i);

        gsl_vector_sub(&mean_subtracted_view.vector, mean);
    }

    /* Calculate covariance matrix
     */

    gsl_matrix * const covariance_matrix = gsl_matrix_alloc(dim, dim);
    
    /*
     * Compute matrix-matrix product and sum
     * gsl_blas_dgemm(op1, op2, a, A, B, b, C )
     * C = a * op1(A) dot op2(B) + b * C
     * where op1, op2 can be CblasNoTrans, CblasTrans, CblasConjTrans
     *
     * covariance_matrix = mean_subtracted_matrix dot 
     *     mean_subtracted_matrix.T + 0 * covariance_matrix
     *
     * (points, dim).T dot (points, dim) =>
     * (dim, points) dot (points, dim) =>
     * (dim, dim)
     */
    
    gsl_blas_dgemm(
        CblasConjTrans,
        CblasNoTrans, 
        1.0 / (dim - 1),
        mean_subtracted_matrix,
        mean_subtracted_matrix,
        0.0,
        covariance_matrix
    );

    gsl_vector * const eigenvalues = gsl_vector_alloc(dim);
    gsl_matrix * const eigenvectors = gsl_matrix_alloc(dim, dim);

    /* Allocate a workspace for computing eigenvalues and eigenvectors
     * with the size O(4n)
     */ 

    gsl_eigen_symmv_workspace * const workspace
        = gsl_eigen_symmv_alloc(dim);

    /* Compute the eigenvalues and eigenvectors of the real 
     * symmetric matrix A.
     * The corresponding eigenvectors are stored in the dim
     * of the matrix `eigenvectors'
     */

    gsl_eigen_symmv(
        covariance_matrix,
        eigenvalues,
        eigenvectors,
        workspace
    );

    /* Simultaneously sorts the eigenvalues stored in the vector
     * and the corresponding eigenvectors
     *     GSL_EIGEN_SORT_VAL_ASC
     *     GSL_EIGEN_SORT_VAL_DESC
     *     GSL_EIGEN_SORT_ABS_ASC
     *     GSL_EIGEN_SORT_ABS_DESC
     */

    gsl_eigen_symmv_sort(
        eigenvalues,
        eigenvectors,
        GSL_EIGEN_SORT_ABS_DESC
    );

    /* Project original matrix to a new space with reduced dimensions
     */

    gsl_matrix * const result = gsl_matrix_alloc(points, newDimension);
    
    /* Make a matrix view of a submatrix of the matrix m. 
     * The upper-left element of the submatrix is the element (k1,k2)
     * of the original matrix. The submatrix has n1 rows and n2 columns.
     *
     * gsl_matrix_submatrix(matrix, k1, k2, n1, n2)
     */

    gsl_matrix_view const reduced_eigenvectors = gsl_matrix_submatrix(
        eigenvectors,
        0,
        0,
        dim,
        newDimension
    );

    /* result = 1 * mean_subtracted_matrix dot reduced_eigenvectors + 0 * result
     * (points, dim) dot (dim, new_dim) =>
     * (points, new_dim)
     */

    gsl_blas_dgemm(
        CblasNoTrans,
        CblasNoTrans,
        1.0,
        matrix,
        &reduced_eigenvectors.matrix,
        0.0,
        result
    );

    gsl_eigen_symmv_free(workspace);
    gsl_matrix_free(eigenvectors);
    gsl_vector_free(eigenvalues);
    gsl_matrix_free(covariance_matrix);
    gsl_matrix_free(mean_subtracted_matrix);
    gsl_vector_free(mean);

    return result;
}

#include <iostream>

int main(){
    double points[] = {
     // x  y
        1, 0,
        2, 1,
        3, 0,
        4, 1,
        5, 0,
        6, 1,
        7, 0,
        8, 1,
        9, 0
    };
        
    gsl_matrix_view const view = gsl_matrix_view_array(points, 9, 2);

    gsl_matrix * const result = pca(&view.matrix, 1);

    assert(gsl_matrix_get(result, 0, 0) == 1);
    assert(gsl_matrix_get(result, 1, 0) == 2);
    assert(gsl_matrix_get(result, 2, 0) == 3);
    assert(gsl_matrix_get(result, 3, 0) == 4);
    assert(gsl_matrix_get(result, 4, 0) == 5);
    assert(gsl_matrix_get(result, 5, 0) == 6);
    assert(gsl_matrix_get(result, 6, 0) == 7);
    assert(gsl_matrix_get(result, 7, 0) == 8);
    assert(gsl_matrix_get(result, 8, 0) == 9);

    gsl_matrix_free(result);
}
