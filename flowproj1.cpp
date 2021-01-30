#include<simplecpp>
#include <cmath>
// ### Program to print the product of the given one digit number and an N digit number. in one-by-one format from last to first digit of the product. ###
// ### AUTHOR : DARSHAN AGURU ###

// please use #include<cmath> for using the pow(a,b) operator.
// I need to work for a better way to do this problem  with sim ple way and declaring less variables..


main_program{
    int n, i, j, d, r, k, temp, temp2, len; // declaring the required int variables
    float t, z1, z2;                   // declaring the required float variables to handle large numbers without rounding off.


// ### INPUT ###

    cin >> d;
    cin >> n;
    int m[n + 1]; // creating int array for taking integer values one by one
    float p[n + 1]; // creating float array for printing answers one by one

    for (i = 1; i <= n; i++) { // for loop for taking input and storing each element in array
        cin >> m[i];
    }


// ### OUTPUT  and processing ###

    t = 0;
    for (j = 1; j <= n; j++) { // for loop for storing the elements of array as a single number.

        t = t + (m[j]*pow(10,j));

    }

    t = t / 10; // correcting the error.. unable to get any better idea.. so just divided it by 10..

    r = t * d;  // required product

    for (k = 0; k <= n; k++) { // loop for taking each digit of product and save it in array and print the elements of array

        temp = r / pow(10, k); // dividing the answer by 'k'th power of 10.. ### ex. if answer is 380247 then this result will be 380247 if k=0 ###

        temp2 = r / pow(10, k + 1); // dividing the answer by 'k + 1'th power of 10 to eliminate the units digit.. ### ex. if answer is 380247 then this result will be 38024 if k=0 ###

        z1 = temp * pow(10, k); // multipling the temp result by 'k'th power of 10... ### ex. if temp result is 380247 then this result will be 380247 if k=0 ###;

        z2 = temp2 * pow(10, k + 1);// multipling the temp result by 'k + 1'th power of 10 to add a zero in units place... ### ex. if temp result is 380247 then this result will be 380240 if k=0 ###;

        p[k] = (z1 - z2) / pow(10, k); // subtracting the z2 result from z1 result.. ###ex. in above cases z1 is 380247 and z2 is 380240 so z1-z2 is 7 which now will be the first digit from last of the answer.. as it was asked in the question..

        //cout << p[k] << endl;// printing each digit of answer from last to first.

      len = *(&p + 1) - p;

    }
    cout<<endl;
//    cout << len<<endl;

    if (p[n] != 0){
        for(int x  = 0; x < len; x++){
                cout<<p[x]<<endl;
            }
    }
    if (p[n] == 0){
        for(int y = 0; y < len-1; y++){
            cout << p[y] <<endl;
        }
     }



    return 0;
}


