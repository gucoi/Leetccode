# go

## go run

生成一个临时的可执行文件，直接在命令行输出程序执行结果，方便用户调试。

## go build

go build用于测试编译包，主要检查是否会有编译错误，如果是一个可执行文件的源码，就会直接生成一个可执行文件。

## go install

go install的作用只有两步，第一步是编译导入的包文件，所有导入的文件编译完才会编译主程序；第二步是将编译后生成的可执行文件放在bin目录下($GOPATH/bin)，编译后的包文件放在pkg（$GOPATH/pkg）目录下 。

## GOPATH

`GOPATH`是作为编译后二进制的存放目的地和`import`包时的搜索路径，

1. `GOPATH`之下主要包含三个目录：bin、pkg、src
2. bin目录主要存放可执行文件；pkg目录存放编译好的库文件，主要是*.a文件，src目录下主要存放go的源文件。

## GOROOT

`GOROOT`是go的安装路径










