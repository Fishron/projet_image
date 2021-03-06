#include <iostream>
#include <cstdlib>

#include "morphology.hpp"

using namespace cv;
using namespace std;

void 
process(const char* sename, const char* imsname, const char* imdname)
{
  Mat se=imread(sename,IMREAD_GRAYSCALE);
  Mat image=imread(imsname,IMREAD_GRAYSCALE);
  Mat new_image(image.rows,image.cols,CV_8U);
  mm(se,image,new_image,minimum);
  imwrite(imdname,new_image);
  
  (void) sename;
  (void) imsname;
  (void) imdname;
}

void 
usage (const char *s)
{
  std::cerr<<"Usage: "<<s<<" im-se ims imd"<<std::endl;
  exit(EXIT_FAILURE);
}

#define param 3
int  
main( int argc, char* argv[] )
{
  if(argc != (param+1))
    usage(argv[0]);
  process(argv[1], argv[2], argv[3]);
  return EXIT_SUCCESS;  
}
