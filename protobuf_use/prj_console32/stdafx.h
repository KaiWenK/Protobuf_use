// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
  
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

// TODO:  在此处引用程序需要的其他头文件
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/coded_stream.h> 
using namespace::google::protobuf::io;