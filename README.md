# ACPR19-DGPRTutorial
[ACPR 2019 Tutorial](https://kerautret.github.io/ACPR19-DGPRTutorial/):  Digital Geometry in Pattern Recognition : Extracting Geometric Features with DGtal and Applications

Slides of the presentation:

  - slides (comming soon)



Linux/MacOs build: [![Build Status](https://travis-ci.org/kerautret/ACCV2016DGPTutorial.svg?branch=WorkingExercices)](https://travis-ci.org/kerautret/ACCV2016DGPTutorial)

Windows build: [![Build status](https://ci.appveyor.com/api/projects/status/o2nkols3y1caoea3/branch/master?svg=true)](https://ci.appveyor.com/project/kerautret/accv2016dgptutorial/branch/master)


## Requires
Before starting the tutorial you need to have the following dependancies:

  - CMake >= 2.6
  - Boost >= 1.46 (modules: program_options)
  - [DGtal](https://github.com/DGtal-team/DGtal)



## Simple Installation of the DGtal Library 

To install DGtal follows theses steps: (more details available on the [official site](http://www.dgtal.org))

 - Clone the current version of DGtal: (or get the archive from a given USB key):
    ```
      git clone git@github.com:DGtal-team/DGtal.git
    ```
 
 - Then recopy the following command lines: 
   - `cd DGtal;` 
   - `mkdir build; cd build`
   - `cmake .. -DBUILD_EXAMPLES=FALSE -DBUILD_TESTING=FALSE`
   - `make`
 
 - Alternatively you can use `ccmake` and select in the interface the associated options.
 
 

