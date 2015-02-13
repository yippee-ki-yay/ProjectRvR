#include "util.h"

void interpolation(float* x, float* y, float* fun)
{

float a, b, c;

	float tmp[3][3];
	float f[3];

	for(int i = 0; i < 3; i++)		// postavljanje vrednosti matrice na osnovu poznatih tacaka
	{
		tmp[i][0] = x[i]*x[i];
		tmp[i][1] = x[i];
		tmp[i][2] = 1;
		f[i] = y[i];
	}

	float copy[3][3];					//postavljanje kopije, zbog transponovanja
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			copy[i][j] = tmp[i][j];
		}
	}

	float det = 0;
	det = tmp[0][0]*(tmp[1][1]*tmp[2][2] - tmp[1][2]*tmp[2][1]) - tmp[0][1]*(tmp[1][0]*tmp[2][2] - tmp[1][2]*tmp[2][0]) + tmp[0][2]*(tmp[1][0]*tmp[2][1] - tmp[1][1]*tmp[2][0]);

	/*for(int i = 0; i < 3; i++)			//izracunavanje determinante
	{
		det = det + (tmp[0][i]*(tmp[1][(i+1)%3]*tmp[2][(i+2)%3] - tmp[1][(i+2)%3]*tmp[2][(i+1)%3]));
	}*/

	std::cout << det;

	if(det == 0)
	{
		x[2] += 1;
		y[2] += 1;
		interpolation(x, y, fun);
		std::cout << "ne postoji takva funkcija";
	}

	for(int i = 0; i < 3; i++)						// izracunavanje elemenata inverzne matrice
	{
		for(int j = 0; j < 3; j++)
		{
			tmp[i][j] = ((copy[(i+1)%3][(j+1)%3]*copy[(i+2)%3][(j+2)%3]) - (copy[(i+1)%3][(j+2)%3]*copy[(i+2)%3][(j+1)%3]))/det;
		}
	}

    for(int i = 0; i < 3; i++)						//postavljanje kopije na nove vrednosti
    {
        for(int j = 0; j < 3; j++)
        {
            copy[i][j] = tmp[i][j];
        }
    }


	for(int i = 0; i < 3; i++)						//transponovanje(nije neophodno)
    {
        for(int j = 0; j < 3; j++)
        {
            tmp[i][j] = copy[j][i];
        }

    }

    /*std::cout << std::endl;
    for(int i = 0; i < 3; i++)              //ispis
    {
        for(int j = 0; j < 3; j++)
            std::cout << tmp[i][j] << " ";
        std::cout << "\n";
    }*/

	a = tmp[0][0]*f[0] + tmp[0][1]*f[1] + tmp[0][2]*f[2];
	b = tmp[1][0]*f[0] + tmp[1][1]*f[1] + tmp[1][2]*f[2];
	c = tmp[2][0]*f[0] + tmp[2][1]*f[1] + tmp[2][2]*f[2];

	fun[0] = -a;
	fun[1] = -b;
	fun[2] = -c;

}




