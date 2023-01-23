#include <iostream>
#include <cmath>

using namespace std;

struct point2d
{
    int x, y;
};

const float G = -3.711f;
const double PI = 3.1415926f;

point2d ground[100], landLeft, landRight;

int surfaceN, hSpeed, vSpeed, fuel, rotate, power;
point2d marsLander, landing;

int initialization()
{
    cin >> surfaceN;
	
    for (int i = 0; i < surfaceN; i++)
    {
	cin >> ground[i].x >> ground[i].y;

	if (ground[i].y == ground[i - 1].y)
        {
	    landLeft  = ground[i - 1];
	    landRight = ground[i];
	}
    }
}

int gameLoop()
{
    while (true)
    {
        cin >> marsLander.x >> marsLander.y >> hSpeed >> vSpeed >> fuel >> rotate >> power;

	double time;

	for (time = 0; time <= 1000; time += 0.001f)
        {
	    int x = marsLander.x + hSpeed * time;
	    int y = marsLander.y + vSpeed * time + (G * time * time) / 2 ;

            if (y < landRight.y)
            {
	        landing.x = x;
		landing.y = y + 1;
		break;
	    }
	}

	if (landLeft.x == 500)
        {
	    if (time < 3)
		cout << "0 4" << endl;
	    else if (marsLander.x < 2000)
		cout << "-45 3" << endl;
	    else if (vSpeed < -1)
		cout << "0 4" << endl;
	    else
		cout << "0 3" << endl;
	}
	else if (time > 2)
        {
	    double hAccelerate = -2 * (marsLander.x + hSpeed * time
				       - ((double)landLeft.x + landRight.x) / 2) / (time * time);
	    double vAccelerate = (-30 - vSpeed - G * time) / time;
	    double rotate = atan2(vAccelerate, hAccelerate) * 180 / PI;
	    double thrust = sqrt(hAccelerate * hAccelerate + vAccelerate * vAccelerate);

	    rotate = rint(rotate) - 90;
	    thrust = rint(thrust);

	    if (thrust > 4)
		thrust = 4;
	    else if (thrust < 0)
		thrust = 0;

            cout << (int)rotate << " " << (int)thrust << endl;
	}
	else
        {
      	    double vAccelerate = (-40 - vSpeed - G * time) / time;
	    if (vAccelerate > 0)
		cout << "0 " << (int)rint(vAccelerate) << endl;
	    else
                cout << "0 0" << endl;
        }
    }   
}

int main()
{
    initialization();
    gameLoop();
}