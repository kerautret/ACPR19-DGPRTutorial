#include <math.h>
#include <cmath>

#include <stdio.h>
#include <omp.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

extern "C" {
#include "iio.h"
}




/**
  *
  * Function to normalize the images between 0 and 255
  *
**/
void image_Threshold (
	const float *I,	//input image 
	float *In,	//normalized output image
	int size,	//size of the image
        int nz,
        int threshold //number of color channels in the images
) 
{

  // Initial min and max values of the image
  for(int index_multichannel = 0; index_multichannel < nz; index_multichannel++){
  	  
        for (int index_image = 0; index_image < size; index_image +=nz)  {         
            int real_index = index_image + index_multichannel;
            if (I[real_index] < threshold){  
              In[real_index] = 0;
            }else{
              In[real_index] = I[real_index] ;
            }
        }
  }
}



/**
 *
 *  Function to read images using the iio library
 *  It allocates memory for the image and returns true if it
 *  correctly reads the image.
 *
 */
bool read_image(const char *fname, float **f, int &nx, int &ny, int &nz){
	*f = iio_read_image_float_vec(fname, &nx, &ny, &nz);	
	return *f ? true : false;
}


int main(int argc, char *argv[])
{
	if(argc < 2){
		cout << "Usage: " << argv[0] << " Input Output threshold "  << endl;
		return 0;
	}	

	int i = 1, nx, ny, nz;        
	const char *input  = argv[i++]; 
	const char *output = argv[i++];
        const int th = atoi(argv[i++]);
	float *I;
	bool correct1 = read_image (input, &I, nx, ny, nz);
	int size = nx * ny * nz;	
	float *f  = new float[size];
	image_Threshold (I, f, size, nz, th); 
	iio_save_image_float_vec((char *) output, f, nx, ny, nz);		
	delete[]f;
	free(I);
        return 0;
}
