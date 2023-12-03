//
// Created by yoda45 on 08/03/2018.
//


#include "cone.h"
using std::vector;

vector<Point*> cone(float radius, float height, int slices, int stacks){
    int i, j;

    vector<Point*> points;

    //Angle of each slice
    float sl_angle = (2*M_PI)/slices;

    //Current angle
    float curr_angle = 0.0f;

    //Angle of layer above current one
    float above_angle;



    //step between stacks
    float step = height/stacks;



    float shift = radius/stacks; // difference in radius between stacks
    float small_radius = radius; // radius of smaller layer
    float big_radius = radius + shift; //radius of bigger layer

    float top_layer = 0;
    float bot_layer = -step;



    //drawing the base of the cone
    for(i=0; i != slices; i++){
        points.push_back(new Point(0.0f,0.0f,0.0f));
        points.push_back(new Point(radius * cos(curr_angle),0.0f,radius * sin(curr_angle)));
        curr_angle += sl_angle;
        points.push_back(new Point(radius * cos(curr_angle),0.0f,radius * sin(curr_angle)));
    }

    //calcular o espaçamento entre duas camadas
    //encontrar a camada superior e camada inferior
    // fazer um trapezio com triangulos
    for(i = 0; i!= stacks ; i++){
        //update smaller radius and bigger radius
        small_radius -= shift; big_radius -= shift;
        //update bottom layer and top layer
        bot_layer += step; top_layer += step;
        //update current angle and above angle
        curr_angle = 0; above_angle = sl_angle;

        //making a full stack
        for(j=0;j!=slices;j++){
            //making upper triangle of slice in stack
            points.push_back(new Point(big_radius*cos(curr_angle),bot_layer,big_radius * sin(curr_angle)));
            points.push_back(new Point(small_radius * cos(curr_angle),top_layer,small_radius*sin(curr_angle)));
            points.push_back(new Point(small_radius * cos(above_angle),top_layer,small_radius * sin(above_angle)));

            //making lower triangle of slice in stack
            points.push_back(new Point(big_radius * cos(curr_angle), bot_layer, big_radius * sin(curr_angle)));
            points.push_back(new Point(small_radius * cos(above_angle),top_layer, small_radius * sin(above_angle)));
            points.push_back(new Point(big_radius * cos(above_angle), bot_layer, big_radius * sin(above_angle)));

            // updating to make another slice
            curr_angle += sl_angle;
            above_angle += sl_angle;


        }

    }
    return points;
}