#include "../inc/matrix_operation.h"
#include <inttypes.h>

int main(void)
{

    Matrix matrix = NULL;
    matrix = nm_init(matrix);
    matrix = memory_init(matrix);
    assign_matrix(matrix);
    printf("the original matrix is: \n");
    print_matrix(matrix);

    Matrix trans_matrix = NULL;
    trans_matrix = transposed(matrix);
    printf("transposed matrix is: \n");
    print_matrix(trans_matrix);

    Matrix result = product(matrix, trans_matrix);
    printf("result is : \n");
    print_matrix(result);

    free(matrix);
    free(trans_matrix);
    free(result);
}