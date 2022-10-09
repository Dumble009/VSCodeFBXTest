#include <iostream>
#include <fbxsdk.h>
#include "fbxtest.h"

void helloWorld()
{
    fbxsdk::FbxManager *fbx_manager = fbxsdk::FbxManager::Create();

    std::cout << "create FbxManager" << std::endl;

    fbx_manager->Destroy();

    std::cout << "destroy FbxManager" << std::endl;
}