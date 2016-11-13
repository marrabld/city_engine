//
// Created by marrabld on 12/11/16.
//

#include "tests.h"
#include <iostream>
#include "../Vector3D.h"
#include <assert.h>
#include "../Math.h"
#include "../Matrix.h"

namespace tests{

    int test1(){

        Vector3D myVec = Vector3D(1.0, 2.0, 3.0);
        myVec = Math::subtract(myVec, myVec);


        std::cout << "myVec = " << std::to_string(myVec.z) << std::endl;

        return 0;

    }

    int test2(){
        float myFloat;

        Vector3D a = Vector3D(1.0, 3.0, -5);
        Vector3D b = Vector3D(4.0, -2, -1);
        myFloat = Math::dot(a, b);

        try{
            assert(myFloat == 3.0);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "dot products do not match " << std::endl;
        }

        std::cout << std::endl;
        std::cout << "The dot product of [1, 3, -5] and [4, -2, -1] is " << std::endl;
        std::cout << "myVec = " << std::to_string(myFloat) << std::endl;

        return 0;
    }

    int test3(){
        Vector3D myVec = Vector3D(1.0, 2.0, 3.0);
        Vector3D a = Vector3D(2.0, 3.0, 4.0);
        Vector3D b = Vector3D(5.0, 6.0, 7.0);
        Vector3D myresult = Vector3D(-3.f, 6.0, -3.f);
        myVec = Math::cross(a, b);

        try{
            assert(myVec==myresult);
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
            std::cout << "vectors do not match " << std::endl;
        }

        std::cout << std::endl;
        std::cout << "The cross product of [2, 3, 4] and [5, 6, 7] is " << std::endl;
        std::cout << "myVec = [" <<
                  std::to_string(myVec.x) <<
                  ", " <<
                  std::to_string(myVec.y) <<
                  ", " <<
                  std::to_string(myVec.z) <<
                  "]" <<
                  std::endl;
        return 0;
    }

    int test4(){
        Vector3D a = Vector3D(2.0, 3.0, 4.0);
        Vector3D b = Vector3D(5.0, 6.0, 7.0);
        Vector3D myVec = Vector3D();
        Vector3D myResult = Vector3D(7.f, 9.f, 11.f);

        myVec = Math::add(a, b);


        try{
            assert(myVec==myResult);
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
            std::cout << "vectors do not match " << std::endl;
        }

        std::cout << std::endl;
        std::cout << "The sum of [2, 3, 4] and [5, 6, 7] is " << std::endl;
        std::cout << "myVec = [" <<
                  std::to_string(myVec.x) <<
                  ", " <<
                  std::to_string(myVec.y) <<
                  ", " <<
                  std::to_string(myVec.z) <<
                  "]" <<
                  std::endl;
    }

    int test5(){
        Vector3D a = Vector3D(2.0, 3.0, 4.0);
        Vector3D b = Vector3D(5.0, 6.0, 7.0);
        Vector3D myVec = Vector3D();
        Vector3D myResult = Vector3D(10.f, 18.f, 28.f);

        myVec = Math::multiply(a, b);

        try{
            assert(myVec==myResult);
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
            std::cout << "vectors do not match " << std::endl;
        }

        std::cout << std::endl;
        std::cout << "The product of [2, 3, 4] and [5, 6, 7] is " << std::endl;
        std::cout << "myVec = [" <<
                  std::to_string(myVec.x) <<
                  ", " <<
                  std::to_string(myVec.y) <<
                  ", " <<
                  std::to_string(myVec.z) <<
                  "]" <<
                  std::endl;
    }

    int test6(){
        Vector3D a = Vector3D(2.0, 3.0, 4.0);
        float myVec;
        float myResult = 5.385165;

        myVec = Math::magnitude(a);

        try{
            assert(myVec==myResult);
        }
        catch(const std::exception& e){
            std::cout << e.what() << std::endl;
            std::cout << "vectors do not match " << std::endl;
        }

        std::cout << std::endl;
        std::cout << "The product of [2, 3, 4] and [5, 6, 7] is " << std::endl;
        std::cout << "" <<
                  std::to_string(myVec) <<
                  std::endl;
    }

    int test8(){
        float a;
        Vector3D myVec = Vector3D(3, 4, -3);
        myVec.Pprint();
        myVec.Normalize();
        myVec.Pprint();
        a = Math::magnitude(myVec);
        std::cout << std::to_string(a) << std::endl;

    }

    int test7(){
        std::cout << "Initializing Matrix" << std::endl;
        Matrix myMat = Matrix(7, 4);

        std::cout << "done" << std::endl;

        myMat.set(0, 0, -1.f);
        myMat.set(0, 1, -2.f);
        myMat.set(1, 0, -7.f);
        myMat.set(1, 1, -4.f);

        //myMat.data[0][0] = -999;

        std::cout << "Matrix vals" << std::endl;
        myMat.Pprint();
        std::cout << "shape is :: [" << std::to_string(myMat.Shape()[0]) << ", " << std::to_string(myMat.Shape()[1]) << "]" << std::endl;
        std::cout << std::endl;

        Matrix tempMat = myMat.T();
        tempMat.Pprint();
        std::cout << "shape is :: [" << std::to_string(tempMat.Shape()[0]) << ", " << std::to_string(tempMat.Shape()[1]) << "]" << std::endl;

    }

    int test9(){
        // Add Two matrices

        Matrix a(2, 2);
        Matrix b(2, 2);
        Matrix z(2, 2);

        a.set(0, 0, 3);
        a.set(0, 1, 11);
        a.set(1, 0, 2);

        b.set(0, 0, -4);
        b.set(0, 1, -2);
        b.data[1][1] = 3;

        z = Math::add(a, b);

        z.Pprint();

        return 0;

    }

    int test10(){

        Matrix a(2, 3);
        Matrix b(3, 4);
        Matrix z(2, 2);
        Matrix q(2, 2);

        a.set(0, 0, -2);
        a.set(0, 1, 3);
        a.set(0, 2, 2);
        a.set(1, 0, 4);
        a.set(1, 1, 6);
        a.set(1, 2, -2);

        std::cout << "==============================" << std::endl;
        std::cout << "A = " << std::endl;
        a.Pprint();

        b.set(0, 0, 4);
        b.set(0, 1, -1);
        b.set(0, 2, 2);
        b.set(0, 3, 5);
        b.set(1, 0, 3);
        b.set(1, 1, 0);
        b.set(1, 2, 1);
        b.set(1, 3, 1);
        b.set(2, 0, -2);
        b.set(2, 1, 3);
        b.set(2, 2, 5);
        b.set(2, 3, -3);

        std::cout << "B = " << std::endl;
        b.Pprint();

        z = Math::multiply(a, b);

        std::cout << "A * B = " << std::endl;
        z.Pprint();

        std::cout << "==============================" << std::endl;

        Matrix c = Matrix(2, 2);
        Matrix d = Matrix(2, 2);

        c.set(0, 0 , -1);
        c.set(0, 1, 2);
        c.set(1, 0, 3);
        c.set(1, 1, -4);

        std::cout << "C = " << std::endl;
        b.Pprint();

        d.set(0, 0, 0);
        d.set(0, 1, 1);
        d.set(1, 0, 2);
        d.set(1, 1, 5);

        std::cout << "c = " << std::endl;
        b.Pprint();

        std::cout << "C * D = " << std::endl;

        q = Math::multiply(c, d);
        q.Pprint();

        std::cout << "D * C = " << std::endl;

        q = Math::multiply(d, c);
        q.Pprint();
        std::cout << "==============================" << std::endl;

    }

}
