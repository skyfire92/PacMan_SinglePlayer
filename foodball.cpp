#include "foodball.h"
#include "map.h"
#include <algorithm>

#include <iostream>

FoodBall::FoodBall()
{
    Map referencemap;
    pacmanmapforreference = referencemap.getPacmanPaths();

    CreateFoodballPositionsVector();
}



QVector<QPoint> FoodBall::getFoodBallPositions()
{
    return foodballpositions;
}

void FoodBall::CreateFoodballPositionsVector()
{
    int horizontal_lines_y[10]={35,121,187,252,318,384,449,514,580,645};
    int vertical_lines_x[10]={35,79,144,209,274,340,406,470,536,579};

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
                if(pacmanmapforreference.contains(QPoint(vertical_lines_x[i],horizontal_lines_y[j])))
                {
                    foodballpositions.push_back(QPoint(vertical_lines_x[i],horizontal_lines_y[j]));
                }
        }
    }

    qDebug("Foodball positions vector size in function creating it: %d",foodballpositions.size());

    // Create a new vector without the duplicates
    QVector<QPoint> unique_foodballpositions;

    for (QVector<QPoint>::iterator iter = foodballpositions.begin(); iter != foodballpositions.end();iter++)
    {
        if(std::find(unique_foodballpositions.begin(),unique_foodballpositions.end(), *iter)==unique_foodballpositions.end())
        {
            unique_foodballpositions.push_back( *iter );
            foodballcount++;
        }
    }
    std::swap( foodballpositions, unique_foodballpositions );

    qDebug("Foodball positions vector size after deleting non-unique elements: %d",foodballpositions.size());
}