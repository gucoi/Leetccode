# socket

## 服务端程序

1. 创建一个socket，用函数socket
2. 绑定ip地址、端口等信息到socket上，用函数bind
3. 设置允许的最大连接数，用函数listen()
4. 接受客户端上来的连接，用函数accept()第三次握手之后返回
5. 收发数据，用函数send()和recv()，或者read()和write()
6. 关闭网络连接

## 客户端程序

1. 创建一个socket，用函数socket()
2. 设置要链接的对方的ip地址和端口属性
3. 连接服务器，用函数connect()，开始三次握手，第二次握手之后返回
4. 收发数据，用函数send()和recv()，或者read和write
5. 关闭网络连接
