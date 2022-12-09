#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <models.cpp>

Model calculateGradient(Model model, TrainingExample *batch, int batchSize)
{
    Model gradient;
    gradient.setA(0);
    gradient.setB(0);
    gradient.setC(0);

    for (int index = 0; index < batchSize; index++)
    {
        TrainingExample example = batch[index];

        double dA = (model.getA() * example.getX() + model.getB() * example.getY() + model.getC() - example.getZ()) * example.getX();
        double dB = (model.getA() * example.getX() + model.getB() * example.getY() + model.getC() - example.getZ()) * example.getY();
        double dC = model.getA() * example.getX() + model.getB() * example.getY() + model.getC() - example.getZ();

        gradient.incrementA(dA);
        gradient.incrementB(dB);
        gradient.incrementC(dC);
    }

    return gradient;
}

void updateModelParameters(Model *model, Model gradient, double learningRate)
{
    model->decrementA(learningRate * gradient.getA());
    model->decrementB(learningRate * gradient.getB());
    model->decrementC(learningRate * gradient.getC());
}

bool converged(Model gradient)
{
    double sumSquares = gradient.getA() * gradient.getA() + gradient.getB() * gradient.getB() + gradient.getC() * gradient.getC();

    return sumSquares < 0.001;
}