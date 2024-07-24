#include "PngReader.h"
#include <png.h>

#include"Model.h"

int main() 
{
	FILE* fp;
	png_structp pngPtr;
	png_infop infoPtr;

	fopen_s(&fp, "Test.png", "rb");

	Model model;
	model.print();
	delete fp;
	return 0;
}