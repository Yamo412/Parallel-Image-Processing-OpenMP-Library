#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <omp.h>
using namespace std;

void applyKernel(int *image[], int *mask[], int mask_size, int image_row, int image_column)
{

    int border = 0;
    for (int i = border; i < image_row - border; i++)
    {
        for (int j = border; j < image_column - border; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    sum += image[(i + k - border) % image_row][(j + l - border) % image_column] * mask[k][l];
                }
            }
            image[i][j] = sum;
        }
    }
}
int main()
{
    string inputFile, outputFile, maskFile;
    cout << "enter the input file name: ";
    cin >> inputFile;
    cout << "\n";
    cout << "enter the output file name: ";
    cin >> outputFile;
    cout << "\n";
    cout << "enter the mask file name: ";
    cin >> maskFile;
    cout << "\n";

    ifstream input(inputFile);
    int row, column;
    input >> row;
    input >> column;
    int **Input = new int *[row];
    for (int i = 0; i < row; i++)
        Input[i] = new int[column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            input >> Input[i][j];
    }
    input.close();

    //saving mask in dynamic array
    ifstream mask(maskFile);
    int size;
    mask >> size;
    int **Mask = new int *[size];
    for (int i = 0; i < size; i++)
        Mask[i] = new int[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            mask >> Mask[i][j];
    }

    cout << "enter the number of threads: ";
    int num;
    cin >> num;
    cout << endl;

    omp_set_num_threads(num);

#pragma omp parallel
    {
#pragma omp single
        {
            applyKernel(Input, Mask, size, row, column);
        }
    }

    ofstream output(outputFile);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            output << Input[i][j] << " ";
        output << "\n";
    }
    output.close();

//delete memory
    for (int i = 0; i < row; i++)
        delete[] Input[i];
    delete[] Input;

    for (int i = 0; i < size; i++)
        delete[] Mask[i];
    delete[] Mask;

    return 0;
}
