#include "Line.cpp"
#include "SolidLine.cpp"
#include "DashedLine.cpp"
#include "DottedLine.cpp"
#include "DoubleDashedLine.cpp"
#include "DistantDashedLine.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){																																																																			
	srand(time(0));
	int lineType;
	Line *line;
	cout << "1.Solid Line\n2.Dotted Line\n3.Dashed Line\n4.Distant Dashed Line\n";
	cout << "5.Double Dashed Line\nEnter Line Type:";
	cin >> lineType;
	if 		(lineType==1)	line = new SolidLine(rand()%30+10);
	else if (lineType==2)	line = new DottedLine(rand()%30+10);
	else if (lineType==3)	line = new DashedLine(rand()%30+10);
	else if (lineType==4)	line = new DistantDashedLine(rand()%30+10);
	else					line = new DoubleDashedLine(rand()%30+10);
	line->draw();
	cout << '\n';
	line->setsize(rand()%30+10);
	line->draw();
	cout << '\n';
	return 0;
}
