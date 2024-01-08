#include <iostream>
#include <string>

#include "bodyinfo.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 3){
        cout << "missing command line arguments" << endl;
        return -1;
    }

    /* TODO 2: Collect height "inHeight" and weight "inWeight" from command line arguments
    *float inHeight = ...
    *float inWeight = ...
    */
   float inHeight = stof(argv[1]);
   float inWeight = stof(argv[2]);

    /* TODO 3: Assign data to BodyInfo variable
    *BodyInfo newBody;
    * ...
    */
   BodyInfo newBody;
   newBody.height = inHeight;
   newBody.weight = inWeight;

   BodyInfo *person;
   person = &newBody;

    /* TODO 4: Compute BMI using only pointer access
    * ...
    */
   float calculation = (person->weight)/((person->height)*(person->height));
   float *BMI;
   BMI = &calculation;

    /* TODO 5: Print height, weight, and bmi.
    * ...
    */
    cout << "Height: " << person->height << " meters" << endl;
    cout << "Weight: " << person->weight << " kg" << endl;
    cout << "BMI: " << *BMI << " kg/m^2" << endl;

    return 0;
}
