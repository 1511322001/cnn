#include"stdafx.h"
#include"commom.h"
array3 padding(array3 input_array, int zero_padding_num){//dim1Ϊ��� dim2Ϊ�߶� dim3Ϊ���
	if (zero_padding_num == 0)return input_array;
	array3 output_array;
	
	output_array = zero(output_array, input_array.size() + 2 * zero_padding_num, input_array[0].size() + 2 * zero_padding_num, input_array[0][0].size());//���ȡ���ȡ����

	for (size_t i = 0; i < input_array.size(); i++)
	{
		for (size_t j = 0; j < input_array[0].size(); j++)
		{
			for (size_t k = 0; k < input_array[0][0].size(); k++)
			{
				output_array[i][j + zero_padding_num][k + zero_padding_num] = input_array[i][j][k];
			}
			
		}
		
	}
	return output_array;
}
array3 resize(array3 input_array, int width, int height, int depth){//���þ����С
	input_array.resize(depth);
	for (size_t i = 0; i < depth; i++)
	{
		input_array[i].resize(height);
		for (size_t j = 0; j < height; j++)
		{
			input_array[i][j].resize(width);
		}

	}
	return input_array;

}
array3 zero(array3 input_array, int width, int height, int depth){//�����0

	input_array.resize(depth);
	for (size_t i = 0; i < depth; i++)
	{
		input_array[i].resize(height);
		for (size_t j = 0; j < height; j++)
		{
			input_array[i][j].resize(width);
			for (size_t k = 0; k < width; k++)
			{
				input_array[i][j][k]=0;
			}
		}

	}
	return input_array;

}
void print_matrxi(array3 input_array){//��ӡ����Ԫ����Ϣ,��ά
	for (size_t i = 0; i < input_array.size(); i++)
	{//��ӡ��i����ά����
		cout << "��" << i << "������" << endl;
		for (size_t j = 0; j < input_array[0].size(); j++)
		{
			for (size_t k = 0; k <input_array[0][0].size(); k++)
			{
				cout << input_array[i][j][k] << " ";
			}
			cout << endl;

		}

	}

}
array3 init_matrix_random(array3 input_array){//��һ��3ά���������ֵ
	for (size_t i = 0; i < input_array.size(); i++)
	{
		for (size_t j = 0; j < input_array[0].size(); j++)
		{
			for (size_t k = 0; k < input_array[0][0].size(); k++)
			{
				input_array[i][j][k]=(double)rand()/(double)RAND_MAX;
			}
		}
	}
	return input_array;


}
array3 conv(array3 input_array, array3 kernel_array,\
	array3& output_array,int stride, double bias){//ʹ�øú���ǰ��ȷ��output.size()==1.
	/////this fuction is pass;
	//ʵ�� 2ά3ά����ľ��
	//�����feature map
	int output_height=output_array[0].size();
	//���feature map�ĸ߶�
	int output_width = output_array[0][0].size();
	//���feature map�Ŀ��
	int output_depth = output_array.size();
	//ͨ��Ϊ1��Ҳ���Ƕ�ά
	///���þ���˴�С
	int kernel_width = kernel_array[0][0].size();
	int kernel_depth = kernel_array.size();
	int kernel_height = kernel_array[0].size();
	//ͨ��kernel_width��kernel_height���
	/////
	if (output_array.size()==1)//ά��Ϊ2��
	{
		for (size_t i = 0; i < output_array.size(); i++)
			//�����ȷ���
		{
			for (size_t j = 0; j < output_array[0].size(); j ++)
				//����߶ȷ���
			{
				for (size_t k = 0; k < output_array[0][0].size(); k ++)
					//�����ȷ���
				{
					output_array[i][j][k] = conv_kernel(input_array, kernel_array, j+stride, k+stride, bias);//��������˺�input�ض�����ľ��
				}
			}
		}

	}
	else
	{
		cout << "output.size()!=1,���output��ά��" << endl;

	}
	return output_array;//��ά���顣

}
double conv_kernel(array3 input_array,array3 kernel_array,\
	int ref_x,int ref_y,double bias){//һ�ξ������.test is pass

	double sum = 0;
	for (size_t i = 0; i < kernel_array.size(); i++)
	{
		for (size_t j = 0; j < kernel_array[0].size(); j++)
		{
			for (size_t k = 0; k < kernel_array[0][0].size(); k++)
			{
				sum+=kernel_array[i][j][k] *input_array[i][ref_y+j][ref_y+k];
			}
		}

	}
	Activator act;
	return act.forward(sum + bias);

}
 int calculate_output_size(int input_size,int filter_size,int zero_padding,int stride){
	return (input_size - filter_size + 2 * zero_padding) / stride + 1;// this funtion test is pass;

}
array3 matrix_rot180(array3 input_array){
	array3 output_array = input_array;
	for (size_t i = 0; i < input_array.size(); i++)
	{
		for (size_t j = 0; j < input_array[0].size(); j++)
		{
			for (size_t k = 0; k < input_array[0][0].size(); k++)
			{
				output_array[i][input_array[0].size()-1 - j][input_array[0][0].size()-1 - k] = input_array[i][j][k];

			}

		}
	}

	return output_array;
}