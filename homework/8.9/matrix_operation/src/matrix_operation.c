#include "../inc/matrix_operation.h"


Matrix nm_init(Matrix matrix)
{
    /*
    我的编译链对%hhu有问题，不过转成int是很万能的
    用scanf输入uint8_t很麻烦，如果用%i，非常有可能出现：
    比如输入row的值是3
    row  ...  columns
    03   00   00      00
    把columns的值覆盖
    保险的的方法是使用临时int暂存
    */
   // 这里注意，传递到函数里的是matrix的副本，所以要不是在外面设置matrix，要不是return matrix
    matrix = (matrix == NULL) ? malloc(sizeof(struct MParam)) : matrix;
    printf("how many rows?\n");
    int tmp_rows = 0;
    scanf("%i", &tmp_rows);
    matrix->row = (uint8_t) tmp_rows;

    printf("how many columns?\n");
    int tmp_col = 0;
    scanf("%i", &tmp_col);
    matrix->column = (uint8_t) tmp_col;

    return matrix;
}

Matrix memory_init(Matrix matrix)
{
    // 这里注意，传递到函数里的是matrix的副本，所以要不是在外面设置matrix，要不是return matrix
    matrix = (matrix == NULL) ? malloc(sizeof(struct MParam)) : matrix;
    matrix->data = malloc(matrix->row * sizeof(float *)); // 指向float *, 需要float *的大小
    for (int i = 0; i < matrix->row; i++)
    {
        matrix->data[i] = malloc(matrix->column * sizeof(float)); // 指向float， 需要float的大小
    }
    return matrix;
}
void assign_matrix(Matrix matrix)
{
    float assignment = 0;
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->column; j++)
        {
            printf("please assign the (%i, %i) emlemt: ", i, j);
            scanf("%f", &assignment);
            matrix->data[i][j] = assignment;
        }
    }
}

void print_matrix(Matrix matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        printf("[");
        for (int j = 0; j < matrix->column; j++)
        {
            printf("%f ", matrix->data[i][j]);
        }
        printf("]\n");
    }
}

Matrix transposed(Matrix matrix)
{
    Matrix trans_matrix = malloc(sizeof(struct MParam));
    trans_matrix->row = matrix->column;
    trans_matrix->column = matrix->row;
    trans_matrix = memory_init(trans_matrix);
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->column; j++)
        {
            trans_matrix->data[j][i] = matrix->data[i][j];
        }
    }
    return trans_matrix;
}

Matrix product(Matrix left, Matrix right)
{
    if (left->column != right->row) 
    {
        printf("they can't product\n");
        return NULL;
    }
    Matrix result = malloc(sizeof(struct MParam));
    result->row = left->row; result->column = right->column;
    result = memory_init(result);
    for (int i = 0; i < result->row; i++)
    {
        for (int j = 0; j < result->column; j++)
        {
            float sum = 0;
            for (int k = 0; k < left->column; k++)
            {
                sum += left->data[i][k] * right->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

void free_matrix(Matrix *matrix)
{
    for (int i = 0; i < (*matrix)->row; i++)
    {
        free((*matrix)->data[i]);
        (*matrix)->data[i] = NULL;
    }
    free((*matrix)->data);
    (*matrix)->data = NULL;
    free(*matrix);
    *matrix = NULL;
}