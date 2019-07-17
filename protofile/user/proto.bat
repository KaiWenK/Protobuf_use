@echo off
rem 进入到当前脚本所在路径
cd /d %~dp0

rem 设置ptoto_path为当前路径的上一层目录
set ptoto_path=%~dp0\

rem 设置cpp_path路径（生成的pb.h和pb.cc的路径）
set cpp_path=%~dp0\proto-file\

echo start generate cpp files...

protoc --cpp_out=%cpp_path% --proto_path=%ptoto_path% %ptoto_path%\addressbook.proto
echo addressbook.ptoto generate .cpp success......

echo end generate cpp files...

@pause