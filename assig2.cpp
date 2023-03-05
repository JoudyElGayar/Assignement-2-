/* 
------------------------------------------------------------------
* Author: Joudy El Gayar
* Class: CSCE 1101/Assignement 2 
* ID: 900222142
* Exercise: 1
* Date: 03/02/2023
* Description: This program should to compute the distance between the object and the canters of the clusters and select the cluster that gives the minimum of such distance. *
------------------------------------------------------------------
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std; 

class point 
{
public:   // member functions 

point();               // Default Constructor, sets X = Y = 0
point (float, float); // Constructor. Initializes both X and Y.
void setX(float);         // Set X value
void setY(float);        // Set Y value
float getX() const; // Get X value
float getY() const;// Get Y value
void display()const;// Display point as (X , Y)
float distance (const point &p);// distance between current point object and another point p

private:    // to declare data members 
float x;
float y;

 };

 point::point()   // default constructor 
 {
x=0.0;
y=0.0;
 }
 point:: point(float X, float Y)     // parameterized constructor
 {
    x=X;
    y=Y;
 }
 void point:: setX( float X)  // setter for X
 {
    x=X;
 }
 void point:: setY( float Y)  // setter for Y 
 {
    y=Y;
 }
 float point :: getX() const    // getter for X
 {
    return x; 
 }
  float point :: getY() const    // gettter for Y
 {
    return y; 
 }
 void point:: display() const    // dispay function to print x and y coordinates of the point 
 {
    cout<< " The coordinates (x,y) are ( " <<x<< " , "<<y<<" )"<<endl;
 }

 float point :: distance (const point &p)     // fucntion to calculate distance 
 {
    return sqrt(pow((x-p.x),2)+pow((y-p.y),2));
 }
 point Center(point C[], int n)   // function to get the center 
 {
   float avx;
   float avy; 
   for (int i=0; i<n;i++)
   {
    avx= avx+C[i].getX();
    avy= avy+C[i].getY();
   }
   avx=avx/n;
   avy=avy/n;

   point centercluster;
   centercluster.setX(avx);
   centercluster.setY(avy);

   return centercluster;
 }
 void Closest(point A[], point B[], int n, point p)    //  to get the closet cluster 
 {
    point clusterA = Center(A,n);
    point clusterB = Center(A,n);
    if( p.distance(clusterA) < p.distance(clusterB) )
    {
        cout <<" Cluster A is the closet to the point. "<<endl;
    }
    else
    {
        cout<<" Cluster B is the closet to the point. "<<endl;
    }
    p.display();
 }
 int main()
 {
    srand(0);   // seed 
    int n=200;
    int m=20;
    point *A= new point[n];
    point *B= new point[n];
    point *p=new point[m];

    for (int i=0;i<n;i++)
    {
        float x=70.0+static_cast<float>(rand())*static_cast<float>(90.0-70.0)/RAND_MAX;
        float y=70.0+static_cast<float>(rand())*static_cast<float>(90.0-70.0)/RAND_MAX;
        
        A[i].setX(x);
        A[i].setY(y);
    }
for (int i=0;i<n;i++)
    {
        float x=20.0+static_cast<float>(rand())*static_cast<float>(40.0-20.0)/RAND_MAX;
        float y=20.0+static_cast<float>(rand())*static_cast<float>(40.0-20.0)/RAND_MAX;
        
        B[i].setX(x);
        B[i].setY(y);
    }

for (int i=0;i<n;i++)
    {
        float x=5.0+static_cast<float>(rand())*static_cast<float>(100.0-5.0)/RAND_MAX;
        float y=5.0+static_cast<float>(rand())*static_cast<float>(100.0-5.0)/RAND_MAX;
        
        p[i].setX(x);
        p[i].setY(y);
    }
for(int i=0 ;i<m;i++)
{
    Closest(A,B,n,p[i]);
}
return 0; 
    }

 