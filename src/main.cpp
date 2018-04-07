/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: minto
 *
 * Created on 5 de marzo de 2018, 12:33
 */

#include <cstdlib>
#include <stdio.h>
#include "communication.h" // has printing also
#include "print_out.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	std::condition_variable& msg_cond;
	msg_cond = NULL;
    Communication robot(msg_cond,"158.42.206.10");
    //Communication robot("localhost");

    //Actions
    robot.start();
    
    double v = 12.43;
    printf("majorVersion = %f \n",v);
    
    return 0;
}

