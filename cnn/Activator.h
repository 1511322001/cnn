#pragma once
class Activator
{//��relu����Ϊ��
public:
	Activator();
	~Activator();
	double forward(double weight_input);
	double back(double out_put);

};

