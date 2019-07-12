# Protobuf_use
google protobuf的使用

1、什么是protobuf
    protobuf是灵活的，高效的，自动序列化结构化数据。类似XML，但是却更小更快更简单。你只需要定义一次数据结构然后你可以使用特定生成的源代码去很容易的写和读你的结构化数据，这些结构化数据来自各种各样的语言和各种各样的数据流。您甚至可以在不破坏已部署的程序的情况下更新数据结构，这些程序是根据“旧”格式编译的。
	
2、如何使用
    通过在.proto文件中定义协议缓冲区消息类型，可以指定要序列化的信息的结构。每个协议缓冲区message都是一个小的信息逻辑记录，包含一系列名称-值对，下面是.proto最基本的示例，它定义包含了关于一个人的个人信息：
	
message Person {
  required string name = 1;
  required int32 id = 2;
  optional string email = 3;

  enum PhoneType {
    MOBILE = 0;
    HOME = 1;
    WORK = 2;
  }
  message PhoneNumber {
    required string number = 1;
    optional PhoneType type = 2 [default = HOME];
  }

  repeated PhoneNumber phone = 4;
}