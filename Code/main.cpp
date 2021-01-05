#include"raytracer.h"
#include<string>
#include<ctime>
using namespace std;

extern string STD_ALGORITHM;
extern int STD_ITERATIONS;
//main.exe 2.txt PPM 1000
int main(int argc, char* argv[]) {
	double start_time = clock();
	//if (argc < 2) return 0;
	
	//string modelName = argv[1];
	//STD_ALGORITHM = argv[2];
	//string Iter = argv[3];
	//STD_ITERATIONS = stoi(Iter);

	string modelName = "model2";
	STD_ALGORITHM = "PM";
	string Iter = "1";
	STD_ITERATIONS = stoi(Iter);

	string path = "model\\";
	string outputName = modelName + "_" + STD_ALGORITHM + "_" + Iter + ".bmp";
	cout << "Creating Scene: " << path+ modelName+".txt" << endl;
	cout << "Algorithm = " << STD_ALGORITHM << endl;
	cout << "Iteration = " << STD_ITERATIONS << endl;
	Raytracer* raytracer = new Raytracer;
	raytracer->SetInput(path+ modelName +".txt");
	raytracer->SetOutput(path+"result\\"+ outputName);
	//raytracer->SetOutput(path + "result\\"+ modelName+".bmp");
	raytracer->Run();
	delete raytracer;
	
	double end_time = clock();
	printf("Escaped time: %.5lf\n" , (end_time - start_time)/CLOCKS_PER_SEC);
	return 0;
}
