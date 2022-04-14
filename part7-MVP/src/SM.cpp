# include "SM.h"

//Private
void SM::initRb()
{
	for (int i = 0; i < 88; i++)
	{
		rbs[i] = pow(2.0, (i + 1 - 49.0) / 12.0) * 440;;
	}
}


//Public
SM::SM()
{
	this->amps[0] = 0;
	this->amps[1] = 0;
	this->amps[2] = 0;
	this->amps[3] = 0;
	this->amps[4] = 0;
	this->amps[5] = 0;
	this->amps[6] = 0;

	for (int i = 0; i < 88; i++)
	{
		pressed[i] = false;
	}

	this->initRb();
}

void SM::update(int n)
{
	if (pressed[n - 1])
	{
		pressed[n - 1] = 0;
		count--;
	}
	else
	{
		pressed[n - 1] = 1;
		count++;
	}
}

void SM::updateAmp(int n, float val)
{
	maxSum += (val-amps[n]);
	std:: cout << "The sum is " << maxSum << std::endl;
	amps[n] = val;

}

bool SM::isPlaying(int n)
{
	return pressed[n];
}

float SM::getOutput(float phase)
{
	float output = 0;
	for (int i = 0; i < 88; i++)
	{
		if (this->pressed[i])
		{
			if (maxSum != 0)
			{
				output += (sin(rbs[i] * phase)
					+ amps[0] * sin(rbs[i] * 2 * phase)\
					+ amps[1] * sin(rbs[i] * 3 * phase)\
					+ amps[2] * sin(rbs[i] * 4 * phase)) / maxSum;
			}
			else
			{
				output += sin(rbs[i] * phase);
			}
			
		}
	}
	return 0.3*output / (float)count;

}

float SM::getRbAt(int n)
{
	return rbs[n];
}