# RSA-Tool
### 基于openssl的RSA数据加密解密加签工具
### 简介

RSA算法是一种非对称加密算法,常被用于加密数据传输.如果配合上数字摘要算法, 也可以用于文件签名.

本文将讨论如何在iOS中使用RSA传输加密数据.

### 原理
RSA使用"秘匙对"对数据进行加密解密.在加密解密数据前,需要先生成公钥(public key)和私钥(private key).

公钥(public key): 用于加密数据及验证签名. 

私钥(private key): 用于解密数据及数据签名. 

常用于接入支付宝支付、微信支付等系列涉及安全问题的操作中



### 接入方法
- **下载openssl文件夹及RSATool**
- **将openssl文件夹及RSATool拖到工程下，打开当前项目的tag,修改bulid Settings->Search Paths->Header Search Paths为当前项目的相对路径**
	
### 使用方法
- **在需要引用的ViewController中import "RSATool.h"**
- **初始化RSATool并导入秘钥,下面以私钥加签为例**
		
		NSString *encodeString = @"待签名字符串";
		RSATool *tool = [RSATool new];
		[tool importKeyWithType:KeyTypePrivate andkeyString:APP_SECRET];
		NSString *signedString = [tool signString:encodeString];
		NSLog(@"加签后为:%@",signedString);
更多方法可以查看RSATool.h中的注释,关于秘钥的导入，提供了如下两种方法,其中keyType为秘钥类型，分为公钥与私钥，公钥用于加密，私钥用于解密及加签


- **通过秘钥path导入**
	
		- (BOOL)importKeyWithType:(KeyType)type andPath:(NSString*)path;

- **通过字符串导入**


		- (BOOL)importKeyWithType:(KeyType)type andkeyString:(NSString *)keyString;


